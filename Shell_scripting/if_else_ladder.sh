#!/bin/bash
echo "Enter your age:"
read age
if [ $age -gt 0 -a $age -lt 10 ]
then
echo your age is between 0-10
elif [ $age -gt 10 -a $age -lt 19 ]
then
echo you are teen ager
else
echo you are a youngster
fi
