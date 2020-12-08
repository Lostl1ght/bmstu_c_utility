#!/bin/bash
if [ -z "$1" ]; then 
    echo "Not enough argumentsments.";
else
    valgrind  --leak-check=full --show-leak-kinds=all ../app.exe <pos_"$1"_in.txt >out.txt
    var=$?
    if [ $var != 0 ]; then 
        echo "         Positive test $1 FAILED. Return code is $var.";
    else
        echo "         Positive test $1 SUCCEDED. Return code is $var.";
    fi
    diff "./pos_$1_out.txt" "./out.txt"
fi
