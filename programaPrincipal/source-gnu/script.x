#!/bin/bash

# como executar 
# 	./script.x 6 0 gnu_mtune &

for i in $(seq 6 2 8);
	do
		mkdir tempo-gnu-$i	
		sed -i "s/#define NUM_THREADS/#define NUM_THREADS $i/g" ../lib/constantes.h

		make clean
		make
		export OMP_NUM_THREADS=$i

		sed -i "s/#define NUM_THREADS $i/#define NUM_THREADS/g" ../lib/constantes.h

		(time ./programa $i $2 $3 > estadoInicial.out) 2>  ./tempo-gnu-$i/tempo-$i.out &
		
		# aguardando para proxima iteracao
		processo=$!
		wait $processo
		
			
		echo "Thread = $i" >> acompanhamento-gnu.txt
	done;
