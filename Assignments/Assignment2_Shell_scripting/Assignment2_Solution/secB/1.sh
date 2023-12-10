#1.Write a program to find sum and product of two no.s using a) expr b) let c) bc
#!/bin/bash
echo enter a
read a 
echo enter b
read b

sum1=$(expr $a + $b)
product1=$(expr $a \* $b)

echo using expr sum is $sum1 and product is $product1
echo
let sum2=a+b
let product2=a*b

echo using let sum is $sum2 and product is $product2
echo

sum3=$( echo "$a+$b" | bc )
product3=$( echo "$a*$b" | bc )

echo using bc sum is $sum3 and product is $product3
