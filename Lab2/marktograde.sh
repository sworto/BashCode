#!/bin/bash
echo "Enter the marks: "
read MARKS
if ((MARKS>=90)); then echo "Grade 0"
elif ((MARKS>=80 && MARKS<90)); then echo "Grade E"
elif ((MARKS>=70&& MARKS<80)); then echo "Grade A"
else echo "Grade B"
fi