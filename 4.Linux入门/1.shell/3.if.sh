#!/bin/bash
TargetFile="for_if.c"
if [[ -r ${TargetFile} ]];then
    gcc for_if.c -o for_if
    ./for_if
else
    echo "${TargetFile} not Found!"
fi

read a
if [[ ${a} -gt 10 ]];then  
    echo "$a > 10"
elif [[ ${a} -eq 10 ]];then
    echo "$a = 10"
else
    echo "$a < 10"
fi
