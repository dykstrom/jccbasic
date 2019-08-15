#!/bin/sh

dir=bin

if [ -d $dir ]; then
    pushd $dir > /dev/null
    
    files=`ls *.exe`
    for file in $files; do
        echo $file
        ./$file
    done
    
    popd > /dev/null
else
    echo Directory \'$dir\' does not exist >&2
    exit 1
fi
