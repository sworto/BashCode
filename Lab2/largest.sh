#!/bin/bash
NUM1=$1
NUM2=$2
NUM3=$3
echo -n "Biggest number is: " 
if((NUM1>NUM2&&NUM1>NUM3)); then echo $NUM1
elif((NUM2>NUM3&&NUM2>NUM1)); then echo $NUM2
else echo $NUM3
fi