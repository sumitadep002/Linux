#!/bin/bash
echo "Enter your file or directory name:"
read filename
if [ -f $filename ]
then
echo it is a file
elif [ -d $filename ]
then
echo it is a directory
else
echo "$filename does not exists"
fi
