#!/bin/bash
if [ ! -d ${C_Files} ]
then
mkdir C_Files
fi
mv *.c C_Files
