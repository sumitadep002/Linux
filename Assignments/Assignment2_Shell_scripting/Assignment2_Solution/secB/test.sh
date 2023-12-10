#!/bin/bash
if [ -e ${C_Files} ]
then
mv *.c C_Files
else
mkdir C_Files
mv *.c C_Files
fi

