#!/bin/bash
read -p 'character: ' c
read -p 'iteration: ' i

#both below while statements are valid
#while [ $i -gt 0 ]
while(($i>0))
do
#-n will avoid new line after echo
echo -n "$c"
let i--
done
