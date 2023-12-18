reset 
set terminal pngcairo
set title "{/:Bold Tempo[s] X Threads - 3200 - gnu + intel}"
set xlabel "Threads"
set ylabel "Tempo[s]"

set autoscale

set grid
set grid linestyle 1 lc rgb "#888888"


set output "tempo-gnu-intel-3200.png"
plot 	"tempo-gnu-lab107c-3200.dat" u 1:2:xtic(1) w l title "lab107c-gnu", \
	"tempo-gnu-b710-3200.dat" u 1:2:xtic(1) w l title "B710-gnu", \
	"tempo-gnu-sequana-3200.dat" u 1:2:xtic(1) w l title "Sequana-gnu", \
	"tempo-intel-lab107c-3200.dat" u 1:2:xtic(1) w l title "lab107c-intel", \
        "tempo-intel-b710-3200.dat" u 1:2:xtic(1) w l title "B710-intel", \
        "tempo-intel-sequana-3200.dat" u 1:2:xtic(1) w l title "Sequana-intel" \
