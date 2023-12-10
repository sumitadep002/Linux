#6.Write a script to check each entry of a directory is a file or directory.
#!/bin/bash 
directory_path=$1
# Iterate over each entry in the directory
for entry in $directory_path
do
if [ -d $entry ]
then
echo "$entry is a directory"
elif [ -f "$entry" ]
then
echo "$entry is a file"
else
echo "$entry is not a valid file or directory"
fi
done
