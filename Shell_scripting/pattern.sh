#!/bin/bash

<<com
1
1 2
1 2 3
1 2 3 4

com

read -p "Enter number of raws-column: " n

i=0
j=0

for((i=1; i<=n; i++))
do
for((j=1; j<=i; j++))
do
echo -n $j
done
echo
done
