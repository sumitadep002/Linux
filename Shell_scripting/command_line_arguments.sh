#!/bin/bash
echo $1 $2 $3 $4
args=("$@")
echo ${args[0]} ${args[1]} ${args[2]}
#print all the arguments
echo $@
#print the nimber of arguments
echo $#
