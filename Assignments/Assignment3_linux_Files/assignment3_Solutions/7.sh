#7. Write a shell Script that accepts two file names as command line arguments and compare two file contents and check whether contents are same or not. If they are same, then delete second file.

#!/bin/bash


#this is to preven user to enter other two CLI arguments
if [ $# -ne 2 ]
then
echo "Usage: $0 file1 file2"
exit 1
fi

file1="$1"
file2="$2"



#this will check whether file1 and file2 share same contants or not
if cmp -s "$file1" "$file2"
then
echo "The contents of $file1 and $file2 are the same"
echo "Deleting $file2..."
rm "$file2"
else
echo "The contents of $file1 and $file2 are different"
fi

