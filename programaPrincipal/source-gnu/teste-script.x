#!/bin/bash

# Ler o arquivo e extrair os minutos e segundos do tempo real
real_time=$(grep real $1 | awk '{print $2}')

# Extrair minutos e segundos
minutes=$(echo $real_time | awk -F 'm' '{print $1}')
seconds=$(echo $real_time | awk -F 'm|s' '{print $2}')

# Converter para segundos com casas decimais
real_seconds=$(echo "$minutes * 60 + $seconds" | bc -l)

echo "Tempo real em segundos: $real_seconds"

