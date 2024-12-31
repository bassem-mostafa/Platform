#!/bin/sh

# These repositories WILL NOT be affected
_3rd_party_repositories=(
    "Kernel/variant/FreeRTOS/*"
    "Kernel/variant/Zephyr/*"
    "Module/UART/driver/com0com"
)

skip_repositories=""
for index in "${!_3rd_party_repositories[@]}"; do
    if [ $index -gt 0 ]; then
        skip_repositories+="|${_3rd_party_repositories[index]}"
    else
        skip_repositories+="${_3rd_party_repositories[index]}"
    fi
done


# Traverse ALL submodules recursivly (filtering 3rd party repositories)
output=$(git submodule foreach --recursive "case \$displaypath in $skip_repositories) ;; *) printf \"./\$displaypath\n\" ;; esac")
# Delete unnecessary lines (lines start with 'Entering...')
output=$(echo "$output" | sed -E '/^Entering .+/d')
# Reverse the order
output=$(echo "$output" | tac)
# Append `.` current repository path
output=$(echo "$output" | sed '$s/$/\n./')
# Filter clean repositories
output=$(printf "$output" | xargs -I% sh -c "cd % && case \$(git status --porcelain) in \"\") ;; *) printf \"%\n\" ;; esac")

repositories=$output

# Retrieve repositories files
# Note: As sed separator `/` could exist in file paths, another separator is used in the following command `|`
output=$(printf "$repositories" | xargs -I% sh -c "cd % && git ls-files | sed -E \"s|(.+)|%\/\1|\"")
# Select ONLY source files
output=$(printf "$output" | grep -E "\.c$")
# Select ONLY source files containing pattern `VERSION[] = `
output=$(printf "$output" | xargs grep -EH "VERSION\[\] = " | sed -E "s/(.+):.+/\1/")

sources=$output

# Set the current version
version=$(echo "0.0.0".v$(date +"%Y%m%d-%H%M"))
printf "\`${PWD##*/}\` is being updated to: \`$version\`\n"

# Overwrite version value
output=$(echo "$sources" | xargs -I% sed -i -E "s/VERSION\[\] = \".+?\"/VERSION\[\] = \"$version\"/" %)

# Overwrite version into doxygen
output=$(echo "doxygen.conf" | xargs -I% sed -i -E "s/(PROJECT_NUMBER += ).+/\1$version/" %)

# Commit
echo "$repositories" | xargs -I% sh -c "echo % | sed -E \"s/./${PWD##*\/}/\" | xargs -I$ sh -c \"printf \\\"commit \\\\\\\`$\\\\\\\`\n\\\" && cd % && git add . && git commit --quiet --amend -m \\\"version $version\\\"\""

printf "\n\n"
printf "Generating Documentation ...\n"

# Generate Docs
output=$(doxygen doxygen.conf)

printf "\n\n"
printf "\`${PWD##*/}\` has been updated to \`$version\`"
