#!/bin/bash
read -p 'a: ' a
read -p 'b: ' b
read -p 'c: ' c

#spaces are necessary
if [ $a -gt $b ]
then
if [ $a -gt $c ]
then
echo $a
else
echo $c
fi
else
if [ $b -gt $c ]
then
echo $b
else
echo $c
fi
fi
