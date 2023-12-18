#!/bin/bash

sed -i "s/#define NUM_THREADS/#define NUM_THREADS $1/g" ../lib/constantes.h

make clean
make

sed -i "s/#define NUM_THREADS $1/#define NUM_THREADS/g" ../lib/constantes.h

(time ./programa $1 $2 $3 > estadoInicial.out) 2>  testeTempo.out 

echo "Thread = $1" >> acompanhamento-gnu-b710.txt
