#!/bin/bash
pos_end=15
neg_end=8
for i in $(seq 1 $neg_end);
do
    ./neg_test.sh "$i"
done
for i in $(seq 1 $pos_end);
do
    ./pos_test.sh "$i"
done
rm -rf ./out.txt