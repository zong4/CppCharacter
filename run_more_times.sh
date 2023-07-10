#!/bin/bash

for ((i=1; i<=20; i++))
do
  echo ""
  echo "Running iteration $i"
  ./a.out
done

exit