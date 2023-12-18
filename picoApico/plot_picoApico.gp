reset 
set terminal pngcairo
set title "MFLOPS x N"
set xlabel "N"
set ylabel "MFLOPS"
set logscale x 
set output "picoApico.png"
plot 	"NxMFLOPS-b710.dat" u 1:2 w lp title "B710", \
	"NxMFLOPS-sequana.dat" u 1:2 w lp title "Sequana", \
	"NxMFLOPS-lab107c.dat" u 1:2 w lp title "lab107c"
