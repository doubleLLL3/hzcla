#!/bin/bash
path="x.TestDir"
echo "./ls -al:" | lolcat
./ls -al
echo "./ls -l:" | lolcat
./ls -l
echo "./ls -al $path:" | lolcat
./ls -al $path
echo "./ls -l $path:" | lolcat
./ls -l $path
echo "./ls -b:" | lolcat
./ls -b
echo "./ls -b $path:" | lolcat
./ls -b $path
