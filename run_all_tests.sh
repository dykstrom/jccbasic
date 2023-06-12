#!/bin/sh

# shellcheck disable=SC2039

DIR=bin

if [ -d $DIR ]; then
    pushd $DIR > /dev/null || exit
    
    files=$(ls -- *.exe)
    for file in $files; do
        echo "$file"
        ./"$file"
    done
    
    popd > /dev/null || exit
else
    echo Directory \'$DIR\' does not exist >&2
    exit 1
fi
