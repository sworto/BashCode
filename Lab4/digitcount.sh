#!/bin/bash
N=$1
while((N>0)); do
	((COUNT++))
	((N=N/10))
done
echo "Total Digits:" $COUNT