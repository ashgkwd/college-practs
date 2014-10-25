#!/bin/bash
#@author: Ashish Gaikwad <ash.gkwd@gmail.com>
#@copy: All rights unreserved.

clear
echo "#Factorial Program By Ashish Gaikwad"
factorial=1

echo "Enter a number"
read input
for (( ; input>1; input-- ))
do
  factorial=$(expr $factorial \* $input)
done

echo "Factorial = $factorial"