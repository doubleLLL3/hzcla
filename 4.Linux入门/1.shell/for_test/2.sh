#!/bin/bash
read n
end=10000
declare -a Prime

function init() {
    local i
    Prime[1]=1
    for (( i=2; i<=${end}; i++ )); do
        if [[ ${Prime[i]}x == x ]]; then
            Prime[0]=$[${Prime[0]} + 1]
            Prime[${Prime[0]}]=$i
        fi
        for (( j=1; j<=Prime[0]; j++ )); do
            if [[ $[$i * ${Prime[j]}] -gt ${end} ]]; then
                break
            fi
            Prime[$[$i * ${Prime[j]}]]=1
            if [[ $[$i % ${Prime[j]}] -eq 0 ]]; then
                break
            fi
        done
    done
}

init
echo ${Prime[n]}
