#!/bin/bash
#write a shell script to check to see if the file-file_path exists, if it exists display "file_path".
FILE=$1
if [ -e $FILE ]
then
echo $FILE does exists
if [ -f $FILE ]
then
echo "$FILE is regular"
else
echo "$FILE is directory"
fi
else
echo "$FILE does not exits"
fi
