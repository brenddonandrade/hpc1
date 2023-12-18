#!/bin/bash

#SBATCH --nodes=1                      #Numero de Nós
#SBATCH --ntasks-per-node=1            #Numero de tarefas por Nó
#SBATCH --ntasks=1                     #Numero total de tarefas MPI
#SBATCH --cpus-per-task=8            #Numero de threads
#SBATCH -p cpu_dev                        #Fila (partition) a ser utilizada
#SBATCH -J brenddon                         #Nome job
#SBATCH --exclusive                    #Utilização exclusiva dos nós durante a execução do job

#Exibe os nós alocados para o Job
echo $SLURM_JOB_NODELIST
nodeset -e $SLURM_JOB_NODELIST

cd $SLURM_SUBMIT_DIR

#Configura os compiladores
#Intel
#source /scratch/app/oneapi/2022.2/modulefiles-setup.sh


# carrega modulo
# intel
#module load intel-oneapi/2022

#GNU
#module load gcc/6.5

#Configura o executavel
way=$(pwd)
EXEC=$way/programa

#exibe informaçoes sobre o executavel
/usr/bin/ldd $EXEC

sed -i "s/#define NUM_THREADS/#define NUM_THREADS $1/g" ../lib/constantes.h

make clean
make
export OMP_NUM_THREADS=$1

sed -i "s/#define NUM_THREADS $1/#define NUM_THREADS/g" ../lib/constantes.h
#(time srun -N 1 -c $1 $EXEC $1 $2  $3 ) 2>  ./tempo-icc-b710-3200-$1/tempo-$1.out
(time srun -N 1 -c $1 $EXEC $1 $2  $3 ) 2>  ./tempo-icc-b710-16000-serial-otimizado/tempo.out

for i in $(seq 2 2 24);
	do
		mkdir tempo-intel-b710-$i	
		sed -i "s/#define NUM_THREADS/#define NUM_THREADS $i/g" ../lib/constantes.h

		make clean
		make
		export OMP_NUM_THREADS=$i

		sed -i "s/#define NUM_THREADS $i/#define NUM_THREADS/g" ../lib/constantes.h

		(time srun -N 1 -c $i ./programa $i $2 $3 > estadoInicial.out) 2>  ./tempo-intel-b710-$i/tempo-$i.out &
		
		# aguardando para proxima iteracao
                processo=$!
                wait $processo
	
		echo "Thread = $i" >> acompanhamento-intel-b710.txt
	done;
