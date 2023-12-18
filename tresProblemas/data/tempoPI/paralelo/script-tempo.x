#!/bin/bash

# Verifica se o número de argumentos é igual a 1
if [ "$#" -ne 1 ]; then
    echo "Uso: $0 <arquivo>"
    exit 1
fi

# Nome do arquivo fornecido como argumento
arquivo=$1

# Verifica se o arquivo existe
if [ ! -f "$arquivo" ]; then
    echo "Erro: O arquivo '$arquivo' não existe."
    exit 1
fi

# Extrai o tempo real do arquivo usando expressões regulares
tempo_real=$(grep -oP 'real\t\K[0-9]+m[0-9,.]+s' "$arquivo")

# Extrai minutos e segundos e converte para segundos usando o ponto como separador decimal
minutos=$(echo "$tempo_real" | grep -oP '[0-9]+m' | tr -d 'm')
segundos=$(echo "$tempo_real" | grep -oP '[0-9,.]+s' | tr -d 's' | tr ',' '.')

# Converte minutos para segundos
minutos_em_segundos=$(echo "$minutos * 60" | bc)

# Calcula o tempo total em segundos
tempo_em_segundos=$(echo "$minutos_em_segundos + $segundos" | bc)

# Imprime o tempo total em segundos
echo "Tempo Real em Segundos: $tempo_em_segundos"

