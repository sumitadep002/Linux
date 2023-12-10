#!/bin/bash
Name=sumit
Password=Ec@190
echo "Enter your username:"
read name
echo "Enter you password"
read -ps password
if [ "$Name" == $name ]
then
echo "You have entered correct username"
elif [ "$password" == "$Password" ]
then
echo "You have entered correct password"
elif [ "$password" == "$Password" -a "$Name" == "$name" ]
then
echo "Your entered password for $name correct"
fi
