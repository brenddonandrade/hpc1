#!/usr/bin/bash

#formatacao do arquivo
head -n 81 devmol.xsf > head-arq.txt
sed -n "82,89p" devmol.xsf > head-spin-1.txt
sed -n "2396,2401p" devmol.xsf > head-spin-2.txt
echo -e "\n END_DATAGRID_3D" > tail-spin.txt
echo "END_BLOCK_DATAGRID_3D" > tail-arq.txt

# obtendo matriz
# devmol
awk 'NR >= 90 && NR <= 2393' devmol.xsf > matrix-devmol-spin-1.txt
awk 'NR >= 2402 && NR <= 4705' devmol.xsf > matrix-devmol-spin-2.txt

# molecule
awk 'NR >= 90 && NR <= 2393' molecule.xsf > matrix-molecule-spin-1.txt
awk 'NR >= 2402 && NR <= 4705' molecule.xsf > matrix-molecule-spin-2.txt

# device
awk 'NR >= 90 && NR <= 2393' device.xsf > matrix-device-spin-1.txt
awk 'NR >= 2402 && NR <= 4705' device.xsf > matrix-device-spin-2.txt

# operacoes
awk -v 'FNR==NR {a[FNR] = $0} {b[FNR] = $0} {c[FNR] = $0} END {for (i = 1; i <= FNR; i++) for(j=1; j<NF; j++) print a[i][j] - b[i][j] - c[i][j]}' matrix-devmol-spin-1.txt matrix-molecule-spin-1.txt matrix-device-spin-1.txt > matrix-result-spin-1.txt
awk -v 'FNR==NR {a[FNR] = $0} {b[FNR] = $0} {c[FNR] = $0} END {for (i = 1; i <= FNR; i++) for(j=1; j<NF; j++) print a[i][j] - b[i][j] - c[i][j]}' matrix-devmol-spin-2.txt matrix-molecule-spin-2.txt matrix-device-spin-2.txt > matrix-result-spin-2.txt



# formatando arquivo final
cat head-arq.txt > densidade_final.xsf
cat head-spin-1.txt >> densidade_final.xsf
cat matrix-result-spin-1.txt >> densidade_final.xsf
cat tail-spin.txt >> densidade_final.xsf
cat matrix-result-spin-2.txt >> densidade_final.xsf
cat head-spin-2.txt >> densidade_final.xsf
cat tail-spin.txt >> densidade_final.xsf
cat tail-arq.txt >> densidade_final.xsf

# Removendo arquivos intermediarios
rm head-arq.txt
rm tail-spin.txt
rm tail-arq.txt
rm head-spin-1.txt
rm head-spin-2.txt
rm matrix-result-spin-1.txt
rm matrix-result-spin-2.txt
rm matrix-devmol-spin-1.txt
rm matrix-devmol-spin-2.txt
rm matrix-molecule-spin-1.txt
rm matrix-molecule-spin-2.txt
rm matrix-device-spin-1.txt
rm matrix-device-spin-2.txt
