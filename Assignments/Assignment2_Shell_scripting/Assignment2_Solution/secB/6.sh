#6.Write a script to check type of a traingle.Sides of the triangle should be provided as command line arguments.


#!/bin/bash
#echo enter side a
#read a
#echo enter side b
#read b
#echo enter side c
#read c

a=$1
b=$2
c=$3
if((a==b && b==c))
then
echo this is Equilateral triangle
elif((a==b||b==c||a==c))
then
echo this is Isosceles Triangle
else
echo this is Scalene Triangle
fi
