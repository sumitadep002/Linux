#5.Write a script to create 10 directories, say exam1,exam2,...,exam10 Report error if a directory/file exists with same name then print error


#!/bin/bash
for i in {1..10}
do
if [ -e exam${i} ]
then
echo exam${i} can not be created because it already exist
else
mkdir exam${i}
fi
done
