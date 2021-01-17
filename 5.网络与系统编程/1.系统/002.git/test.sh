#!/bin/bash
cmd="./git_commit"
msg="first commit"
echo "1)${cmd}:" | lolcat
${cmd}
echo "2)${cmd} -m \"${msg}\":" | lolcat
${cmd} -m "${msg}"
echo "3)${cmd} -m:" | lolcat
${cmd} -m
echo "3)${cmd} -b:" | lolcat
${cmd} -b
