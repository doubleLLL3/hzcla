#!/bin/bash
if [[ $# -ne 2 ]];then
    echo "Error"
    exit
fi

Start=$1
End=$2
declare -a Prime

function init_prime() {
    local end=$1  # $1——第一个传入参数；声明和赋值可以放在一起
    local i
    Prime[1]=1
    for ((i=2; i<=${end}; i++));do
        # 将素数排在前面
        if [[ Prime[$[i]] -eq 1 ]]; then
            continue 
        fi
        Prime[0]=$[ ${Prime[0]} + 1 ]
        Prime[${Prime[0]}]=$i
        ##
        for ((j=$[ ${i} * ${i} ]; j<=${end}; j+=i));do
            Prime[${j}]=1
        done
    done
}

init_prime ${End}
sum=0

# 方式一：将素数存在前排
for ((i=1; i<=${Prime[0]}; i++)); do
    sum=$[ ${sum} + ${Prime[$i]} ]
done
:<<!
# 方式二：根据标记判断素数
for ((i=${Start}; i<=${End}; i++));do
    # 判空：方法一，-z String、方法二，Stringx == x
    if [[ ${Prime[$i]}x == x ]];then
        #echo ${i}
        sum=$[ ${sum} + ${i} ]
    fi
done
!
echo ${sum}
