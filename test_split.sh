#!/bin/bash

for ((i=1; i<=6; i++))
do
  echo ""
  echo "Running iteration $i"
  
  # ./a.out 1

  num1=$((10**(i+1)))
  num2=$((10**(i)))

  ./a.out 0 $num1 $num2
done

exit