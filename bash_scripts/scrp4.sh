#!/usr/bin/env bash

#while

num=23
while (( num < 30 )); do
  echo "${num}"
  (( num++ ))
done

#until
until (( num >= 35 )); do #dopoki wynik false -> do smth
  echo "${num}"
  (( num++ ))
done

#for
n=5
for ((i=0; i < n; i++)); do
  echo "${i}"
done


array=(5 7 9 11)

for (( i = 0; i < "${#array[@]}"; i++ )); do
  echo "Index: ${i}, value: ${array[i]}"
done

#foreach

for value in "${array[@]}" ; do
  echo $(( value + 5 ))

done