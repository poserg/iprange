#!/bin/bash

count=200

n=0

while [ $n -lt $count ]
do
    cp infile tmp
    ./listclassip.sh >> tmp &
    ./iprange tmp
    if [ "$?" -eq 0 ]
    then 
        let "n++"
        mv tmp infile
    else
        rm -f tmp
    fi
done
