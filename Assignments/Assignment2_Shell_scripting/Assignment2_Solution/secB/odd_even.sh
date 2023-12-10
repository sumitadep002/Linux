#!/bin/bash
read -p 'a: ' a

if(($a%2==0))
then
echo $a is even
else
echo $b is odd
fi
