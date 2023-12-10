#!/bin/bash
echo "enter you name and age"
read name age
if [ $age -ge 18 ]
then
echo "Hello $name you are able to vote for upcoming elections"
else
echo "Hello $name you are underage hence you are not eligible to vote in upcoming elections"
fi
