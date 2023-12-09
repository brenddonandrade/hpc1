#!/bin/bash


for i in $(seq 2 2 48);
	do
		mkdir tempo-intel-sequana-$i	
		sed -i "s/#define NUM_THREADS/#define NUM_THREADS $i/g" ../lib/constantes.h

		make clean
		make
		export OMP_NUM_THREADS=$i

		sed -i "s/#define NUM_THREADS $i/#define NUM_THREADS/g" ../lib/constantes.h

		(time ./programa $i $2 $3 > estadoInicial.out) 2>  ./tempo-intel-sequana-$i/tempo-$i.out &
		
		# aguardando para proxima iteracao
                processo=$!
                wait $processo
		
		echo "Thread = $i" >> acompanhamento-intel-sequana.txt
	done;
