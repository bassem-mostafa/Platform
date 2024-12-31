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

printf "${PWD##*/} has pending modifications into\n"
printf "$repositories" | xargs -I% sh -c "echo % | sed -E \"s/./${PWD##*\/}/\" | xargs -I$ sh -c \"printf \\\">>> $\n\\\"\""
