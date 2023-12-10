#7. Write a script to print day of the week using a) elif 

#!/bin/bash
echo enter day
read day
if ((day==1))
then
echo sunday
elif ((day==2))
then
echo monday
elif ((day==3))
then
echo tuesday
elif ((day==4))
then
echo wednesday
elif ((day==5))
then
echo thursday
elif ((day==6))
then
echo friday
elif ((day==7))
then
echo saturday
else
echo invalid input
fi
