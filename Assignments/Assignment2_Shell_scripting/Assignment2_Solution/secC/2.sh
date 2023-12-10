#!/bin/bash
while true  
do
echo "a)length of the string"
echo "b)Copying string"
echo "c)Concatenation of strings"
echo "d)Comparison"
echo "e)reversing a string"
echo
echo enter your choice:
read choice
<<<<<<< HEAD
=======
echo enter string:
read string1
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
echo
case $choice in
'a')echo enter the string: 
read string
echo length of $string is ${#string};;
'b')echo enter string2:
read string2
string1=$string2
echo string1 is copied into string2 variable
echo string1 is $string1 and string2 is $string2;;
'c')echo enter the string2:
read string2
string1=${string1}${string2}
echo string1 is $string1;;
'e')len=${#string1}
for((i=$len-1;i>=0;i--))
do 
<<<<<<< HEAD
reverse="$reverse${string1:$i:1}"
=======

reverse="$reverse${string1:$i:1}"
#another way to do it 
#reverse = $(echo $string1 | rev)
#
>>>>>>> f52763f2638bddc9d525298d831e7e86bb093de9
done
echo "$string1 -> $reverse";;
'd')
echo enter string2 to compare with $string1:
read string2
if [ ${string1} -eq ${string2} ]
then
echo $string1 = $string2
else
echo $string1 != $string2
fi;;
*)echo program is in invalid state try again;;
esac
done
