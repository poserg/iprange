#!/bin/bash

count=100

let count*=4
while [ $count -gt 0 ]
do
    k=$RANDOM
    let k%=256
    echo -n $k
    let count--
    let "db = $count % 4"
    if [ $db -eq 0 ] 
    then
        echo
    else 
        echo -n '.'
    fi
done
