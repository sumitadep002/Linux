#!/bin/bash
echo "Enter full path of the current directory"
read path
for path in $(cat $path)
do
echo "file: $path"
done
