# gera um  codigo prg.x
gcc -fopenmp -o prg.x prg.c 

for i in $(seq 1 4) 6 8
	do
		export OMP_NUM_THREADS=$i
		./prg..x
	done
