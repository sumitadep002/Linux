#3.Write a program to print calendar of current month in next year,previous years.
#For eg:- sep 2014,sep 2012 if current month is sep 2013


#!/bin/bash

#This line uses the date command with the %m format specifier to obtain the current month.
month=$(date +%m)

#This line uses the date command with the %y format specifier to obtain the current year
year=$(date +%y)

#this line prints the calender of the current month and year
echo current month calender of present year:
cal $month $year

##this line prints the calender of the month of previous year
let year=year-1
echo current month calender of past year: 
cal $month $year

##this line prints the calender of the month of upcoming year
let year=year+2
echo curren month caleneder of next year:
cal $month $year
