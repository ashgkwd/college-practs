#!/bin/bash
#@author: Ashish Gaikwad <ash.gkwd@gmail.com>
#@copy: All rights unreserved.

echo "" # Nice looking blank line
echo "#Is it vowel or not"
case $1 in
  a|e|i|o|u) echo "Its Vowel! Nacho :)" ;;
  *) echo "Its not Vowel." ;;
esac

echo ""
echo "#Printing all command line arguments"
for i in $*
do
  echo $i
done

echo ""
echo "#Maths sum and average"
echo "Enter three numbers"
read _1
read _2
read _3
sum=$(expr $_1 + $_2 + $_3)
echo "Sum = $sum"
echo "Average = $(expr $sum / 3)"

echo ""
echo "#Greatest of above three"
if [[ $_1 -gt $_2 && $_1 -gt $_3 ]]
  then
  echo "$_1 is greatest"
elif [[ $_2 -gt $_3 && $_2 -gt $_1 ]]
  then
  echo "$_2 is Greatest"
else
  echo "$_3 is greatest"
fi

echo ""
echo "#While loop"
n=1
while [ $n -le 5 ] # -le lessthan or equal
do
  echo $n
  n=$(expr $n + 1)
done

echo ""
echo "#For loop three expression"
for (( c=5; c>0; c-- ))
do
  echo $c
done