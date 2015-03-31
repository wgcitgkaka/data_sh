#!/bin/bash


echo "hello world"

while read line
do
	echo $line
done < ./1.data
