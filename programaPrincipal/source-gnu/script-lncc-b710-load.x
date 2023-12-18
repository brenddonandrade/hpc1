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
Intel
source /scratch/app/modulos/intel-psxe-2016.sh

#ou
#GNU
module load gcc/6.5

