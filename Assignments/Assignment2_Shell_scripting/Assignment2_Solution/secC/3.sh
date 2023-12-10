#3.Write a script to check whether given argument is a regular file or directory

#!/bin/bash
#echo -e "Enter the name of the file: $PWD/"
#read file_name
if [ -f $1 ]
then
echo $1 is a file 
elif [ -e $1 ]
then
echo $1 is a directory
else
echo $1 does not exist
fi

