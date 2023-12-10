#!/bin/bash
echo "Press any option"
echo "1 to see date"
echo "2 to see list of files of current directory"
echo "3 to see currernt path of the working direcctory"
read choice
case $choice in
1)date;;
2)ls -ltr;;
3) pwd;;
*)echo invalid option
esac
