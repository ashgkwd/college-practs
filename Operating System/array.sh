#!/bin/bash
#@author: Ashish Gaikwad <ash.gkwd@gmail.com>
#@copy: All rights unreserved.

clear
echo "#Array Play By Ashish Gaikwad"
echo "Enter number of elememts"
read size
echo "Enter $size array elements"
for (( c=0; c<$size; c++ ))
do
  read a[$c]
done

echo ""
echo "Elememts of array in reverse"
for (( d=size-1; d>=0; d-- ))
do
  echo ${a[$d]}
done