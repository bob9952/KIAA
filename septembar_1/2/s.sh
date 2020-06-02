#!/bin/bash
for((i=1; i<=10; i++)); do
    file1="${i}_in.txt"
    file2="${i}_out.txt"
    file3="out${i}.txt"

    ./1 < $file1 > $file3 
    diff -w $file3 $file2 || break
    find . -name $file3 -delete
done
