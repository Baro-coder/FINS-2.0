#!/bin/bash

WORKDIR="/home/bszyk/Projects/FINS/fins-cpp"

echo "=============="
echo "=-- MAKING --="
echo "=============="
echo

make

if [[ $? -eq 0 ]]; then

	echo "==============="
	echo "=-- RUNNING --="
	echo "==============="
	echo
	
	${WORKDIR}/bin/fins	
else
	echo
	echo "Compilation failure!"
	exit 1 
fi
