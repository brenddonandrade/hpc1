reset 
set terminal pngcairo
set title "{/:Bold Tempo [s] x Flags - 3200 - gnu}"
set xlabel "Flags"
set ylabel "Tempo[s]"

set autoscale

set grid
set grid linestyle 1 lc rgb "#888888"

set style fill solid 0.5  # Preenchimento sólido com transparência de 50%

dados = "tempo-gnu-3200-serial-metricas.txt"

set output "tempo-gnu-barras-3200.png"
plot dados using 2:xticlabels(1) with boxes
