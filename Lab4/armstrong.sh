#/bin/bash
N=$1
N1=$((N%10))
N2=$(((N/10)%10))
N3=$(((N/100)%10))
if (( N1*N1*N1+N2*N2*N2+N3*N3*N3==N )); then echo "Armstrong"
else echo "Not armstrong"
fi
