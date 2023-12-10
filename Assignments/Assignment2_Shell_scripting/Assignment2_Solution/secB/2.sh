#!/bin/bash
echo enter numerator:
read numerator
echo enter denominator
read denominator
result=$( echo "scale=2; $numerator/$denominator" | bc )
echo $result
