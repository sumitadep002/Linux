#7. Write a script to print day of the week using b) case
#!/bin/bash
echo enter a number
read n
case $n in
1)echo sunday;;
2)echo monday;;
3)echo tuesday;;
4)echo wednesday;;
5)echo thursday;;
6)echo friday;;
7)echo saturday;;
*)echo invalid
esac
