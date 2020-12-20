#!/bin/bash
read s
echo $s | tr " " "\n" | sort | uniq -c | sort -n -r | head -3
