#!/bin/bash

sed -i "s/#define NUM_THREADS/#define NUM_THREADS $1/g" ../lib/constantes.h


make clean
make
export OMP_NUM_THREADS=$1

sed -i "s/#define NUM_THREADS $1/#define NUM_THREADS/g" ../lib/constantes.h


# ./script-simples.x threads ox compilador
#(time ../../../siesta < benzene.fdf > ./output-$ox/benzeno-$ox.out) 2> ./output-$ox/tempo_de_execucao-$ox.out &
(time ./programa $1 $2 $3 > estadoInicial.out) 2>  testeTempo.out &
#(time ./programa $1 $2 $3) > texte.txt  & 
