#!/bin/bash


a=12
b=50

#below both are valid for addition
#val=`expr $a + $b`
let val=a+b
echo "a + b : $val"

val=`expr $a - $b`
echo "a - b : $val"

val=`expr $a \* $b`
echo "a * b : $val"

val=`expr $b / $a` 
echo "b / a : $val"

val=`expr $b % $a`
echo "b % a : $val"

val=$(echo "scale=2; $b/$a" | bc)
echo "b/a = $val"

if [ $a == $b ]
then
   echo "a is equal to b"
fi

if [ $a != $b ]
then
   echo "a is not equal to b"
fi
