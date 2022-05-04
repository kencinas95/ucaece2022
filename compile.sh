#!/bin/sh

BASE=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )
MAKE=$(which make)

clean()
{
    working_dir="$1"    
    target_makefile="$working_dir/makefile"
    
    if [ -e "$target_makefile" ]; then
        $MAKE clean
    else
        echo "MAKEFILE DOES NOT EXIST"
        target_compiled="$working_dir/target"
        for f in $target_compiled/*; do
            echo $f
        done
    fi
}

compile()
{
    working_dir="$1"
    echo "$working_dir"
    target_makefile="$working_dir/makefile"

    if [ ! -e "$target_makefile" ]; then
        cp "$BASE/makefile" "$target_makefile"
    else
        clean "$working_dir"
        cp "$BASE/makefile" "$target_makefile"
    fi

    cd "$working_dir"
    $MAKE    
    rm -rf "$working_dir/makefile"    
}

if [ $# -gt 0 ]; then
    for sub_dir in $@; do
        if [ -d "$BASE/$sub_dir" ]; then
            compile "$BASE/$sub_dir"
        else
            echo "$BASE/$sub_dir does not exists!"
        fi
    done
else
    for sub_dir in $BASE/*/; do        
        compile $sub_dir
    done
fi 