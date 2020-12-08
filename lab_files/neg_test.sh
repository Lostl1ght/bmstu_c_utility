if [ -z "$1" ]; then 
    echo "Not enough argumentsments.";
else
    valgrind --leak-check=full --show-leak-kinds=all ../app.exe <neg_"$1"_in.txt >out.txt
    var=$?
    if [ $var == 0 ]; then 
        echo "         Negative test $1 FAILED. Return code is $var.";
    else
        echo "         Negative test $1 SUCCEDED. Return code is $var.";
    fi
    diff "./neg_$1_out.txt" "./out.txt"
fi
