#!/bin/bash
A=$1;
B=$2;
echo "**BASH CALCULATOR***"
echo "Add: +"
echo "Subtract -"
echo "Multiply *"
echo "Divide /"
echo -n "Select Operations: "
read OPERATOR
if [[ "$OPERATOR" == "+" ]]; then echo "Addition:" $(( A+B ))
elif [[ "$OPERATOR" == "-" ]]; then echo "Subtraction:" $(( A-B ))
elif [[ "$OPERATOR" == "*" ]]; then echo "Multiplication:" $((A*B))
elif [[ "$OPERATOR" == "/" ]]; then echo "Quotient:" $(( A/B )) "Remainder:" $((A%B))
else echo "Invalid Input" 
fi