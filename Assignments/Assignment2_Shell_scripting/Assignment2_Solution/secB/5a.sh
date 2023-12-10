#a) Write a script to find biggest of three no.s

#!/bin/bash
echo enter a
read a
echo enter b
read b
echo enter c
read c
if((a>b && a>c))
then
echo $a is biggest
elif((b>a && b>c))
then
echo $b is biggest
else
echo $c is biggest
fi
