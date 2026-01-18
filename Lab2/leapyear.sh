#!/bin/bash
echo -n "Enter the year: "
read YEAR
if ((YEAR%4==0)); then echo A Leap Year
else echo Not a Leap Year
fi