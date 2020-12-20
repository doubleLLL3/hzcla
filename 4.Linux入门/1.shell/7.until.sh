#!/bin/bash
num=0
until [[ $num -eq 100 ]];do
    echo $num
    num=$[ ${num} + 1 ]
done
