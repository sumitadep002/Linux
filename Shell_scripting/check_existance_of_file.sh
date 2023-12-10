#!/bin/bash
echo "Enter the filename:"
read filename
echo "Enter the path:"
read path
if [ $path -e $filename ]
then
echo "$filename file exists"
else
echo "$filename file does nnot exist"
fi
done
