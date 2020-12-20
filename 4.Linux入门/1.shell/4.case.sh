#!/bin/bash
read a
case $a in 
    1)
        echo 1
        ;;
    2)
        echo 2
        ;;
    *) # 默认情况
        echo "Not Found!"
        ;;
esac
