#!/bin/bash

old_value=0
j=0
for i in $(seq 0 3);
	do 	
		echo "Task $i" >> controle2.txt
		echo "Task $i"	
		sed -i "s/\-O$j/\-O$i/g" makefile
		
		make clean
		make
		
		for k in $(seq 1 4) 6 8;
			do	
				echo "Thread $k" >> controle.txt
				echo "Thread $k"
				export OMP_NUM_THREADS=$k
				(time ./modelo) &> ../../data/tempoMult/paralelo/tempo-paralelo-O$i-$k.out &
				wait $!
			done
		j=$i
	done;
sed -i "s/\-O$j/\-O$old_value/g" makefile
