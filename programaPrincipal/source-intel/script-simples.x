#!/bin/bash

sed -i "s/#define NUM_THREADS/#define NUM_THREADS $1/g" ../lib/constantes.h

make clean
make
export OMP_NUM_THREADS=$1

sed -i "s/#define NUM_THREADS $1/#define NUM_THREADS/g" ../lib/constantes.h


# ./script-simples.x threads ox compilador
(time ./programa $1 $2 $3 > estadoInicial.out) 2>  tempo-intel-lab107c-3200-serial-puro/tempo.out &
#./programa $1 $2 $3 
#(time ./programa $1 $2 $3) > texte.txt  & 
