#!/bin/bash
#@author: Ashish Gaikwad <ash.gkwd@gmail.com>
#@copy: All rights unreserved.

clear
echo "#Insertion Sort By Ashish Gaikwad"
echo "User Ctrl+D to finish input"
while read line
do
  a+=($line)
done

echo ""
echo "Array elements before sorting"
echo ${a[@]}

for (( c=1; c<=${#a[@]} -1; c++ ))
do
  d=$c
  while [[ $d -gt 0 && ${a[$d]} -lt ${a[$d -1]} ]]; do
    t=${a[$d]}
    a[$d]=${a[$d -1]}
    a[$d -1]=$t
    let d--
  done
done

echo "Array elements after sorting"
echo ${a[@]}