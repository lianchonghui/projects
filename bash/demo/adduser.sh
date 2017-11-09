#!/bin/bash

echo $1

for I in `echo $1 | sed 's/,/ /g'`; do
	if  id $I &> /dev/null; then
		echo "$I exists."
	else
		echo "$I not exists."
	fi
done
