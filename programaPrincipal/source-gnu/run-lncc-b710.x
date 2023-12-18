#!/bin/bash

#SBATCH --nodes=1                      #Numero de Nós
#SBATCH --ntasks-per-node=1            #Numero de tarefas por Nó
#SBATCH --ntasks=1                     #Numero total de tarefas MPI
#SBATCH --cpus-per-task=24            #Numero de threads
#SBATCH -p cpu_dev                        #Fila (partition) a ser utilizada
#SBATCH -J brenddon                         #Nome job
#SBATCH --exclusive                    #Utilização exclusiva dos nós durante a execução do job

#Exibe os nós alocados para o Job
echo $SLURM_JOB_NODELIST
nodeset -e $SLURM_JOB_NODELIST

cd $SLURM_SUBMIT_DIR

#Configura os compiladores
#Intel
#source /scratch/app/modulos/intel-psxe-2016.sh

#ou
#GNU
module load gcc/6.5

#Configura o executavel
EXEC=/scratch/uff21hpc/brenddon.oliveira/hpc1/programaPrincipal/source-gnu/programa

#exibe informaçoes sobre o executavel
/usr/bin/ldd $EXEC

#configura o numero de threads, de acordo com o parametro definido no Slurm
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK

srun  -N 1 -c $SLURM_CPUS_PER_TASK $EXEC


(time srun -N 1 -c $SLURM_CPUS_PER_TASK $EXEC 24 0 gcc_mtune ) 2>  ./tempo-gnu-b710-24/tempo-24.out 

# echo "Thread = 24" >> acompanhamento-gnu-b710.txt
