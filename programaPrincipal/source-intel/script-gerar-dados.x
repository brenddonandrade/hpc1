#!/bin/bash

# Cria o arquivo .dat
echo -e "x\ttime_seconds" > output.dat

# Loop sobre as pastas
for x in {2..48..2}
do
    folder="tempo-intel-b710-3200-$x"
    file="$folder/tempo-$x.out"

    # Verifica se o arquivo existe
    if [ -e "$file" ]; then
	# Ler o arquivo e extrair os minutos e segundos do tempo real
	real_time=$(grep real $file | awk '{print $2}')
	
	# Extrair minutos e segundos
	minutes=$(echo $real_time | awk -F 'm' '{print $1}')
	seconds=$(echo $real_time | awk -F 'm|s' '{print $2}')

	# Converter para segundos com casas decimais
	real_seconds=$(echo "$minutes * 60 + $seconds" | bc -l)


        # Adiciona a entrada ao arquivo .dat
        echo -e "$x\t$real_seconds" >> output.dat
    fi
done

echo "Concluído. Os dados foram salvos em output.dat"

