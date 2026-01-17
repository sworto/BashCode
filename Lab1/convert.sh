#!/bin/bash
read -p "Enter the distance in meter: " DISTANCE
read -p "Enter the dimension to convert into: " DIMENSION
if [ "$DIMENSION" = "M" ]; then echo "Distance in meter: " $DISTANCE
elif [ "$DIMENSION" = "CM" ]; then echo "Distance in centimeter: " $((DISTANCE*100))
elif [ "$DIMENSION" = "KM" ]; then echo "Distance in kilometer: " $((DISTANCE/1000))
else echo "NOT A VALID DIMENSION!!"
fi
