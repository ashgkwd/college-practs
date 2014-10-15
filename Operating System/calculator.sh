#!/bin/bash
#@author: Ashish Gaikwad <ash.gkwd@gmail.com>
#@copy: All rights unreserved.

clear
echo "#Calculator By Ashish Gaikwad"
while [ 1 -eq 1 ]
do
  echo "Use Ctrl+Z to exit"
  echo "Enter two numbers"
  read ash
  read sonia
  echo -e " + add\n - sub\n * multi\n / div\n % mod\n"
  read c
  case $c in
    '+') c=$(expr $ash + $sonia) ;;
    '-') c=$(expr $ash - $sonia) ;;
    '*') c=$(expr $ash \* $sonia) ;;
    '/') c=$(expr $ash / $sonia) ;;
    '%') c=$(expr $ash % $sonia) ;;
    *) echo "Bogus operation"
      continue ;;
  esac
  echo "answer = $c"
done