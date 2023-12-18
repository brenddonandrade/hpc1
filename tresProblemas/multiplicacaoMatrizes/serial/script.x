#!/bin/bash

old_value=0

j=0
for i in $(seq 0 3);
	do 	
		echo "Task $i" >> controle.txt
		echo "Task $i"	
		sed -i "s/\-O$j/\-O$i/g" makefile
		
		make clean
		make
		
		(time ./modelo) &> ../data/tempoMult/serial/tempo-serial-O$i.out 
		j=$i
	done;
sed -i "s/\-O$j/\-O$old_value/g" makefile
