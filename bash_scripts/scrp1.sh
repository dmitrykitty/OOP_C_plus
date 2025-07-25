#!/bin/bash

echo "Application is starting..."

default_app_name="Spring"
echo "Application name is ${default_app_name}!"

value=4

array=(1 5 22 100)
echo "Array ${array[2]} has ${value} elements"
echo "${array[@]}" #aby wypisac cały array

array[2]=54
array+=(10 34) #dodanie elementow
echo "${array[@]}"

read number
echo "Your number is $number"