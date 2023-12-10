#!/bin/bash

<<com
1
2 3
4 5 6
7 8 9 10

com

read -p "Enter number of raws-column: " n

i=0
j=0
k=0
for((i=1; i<=n; i++))
do
for((j=1; j<=i; j++))
do
let k++
echo -n $k
done
echo
done
