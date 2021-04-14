#!/bin/bash

IFS=$'\n'

rm generated_output.txt

for i in `cat test.txt`; do 
    echo $i | xargs ./$1 >> $2
done 