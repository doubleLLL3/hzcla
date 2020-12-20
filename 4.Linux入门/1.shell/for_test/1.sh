#!/bin/bash
read p q
declare -a Road
count=0

for (( i=0; i<q; i++ )); do
    read left right
    for (( j=left; j<=right; j++ )); do
        if [[ ${Road[j]}x == x ]]; then
            Road[j]=1
            count=$[$count + 1]
        fi
    done
done

echo $[$p - $count + 1]
