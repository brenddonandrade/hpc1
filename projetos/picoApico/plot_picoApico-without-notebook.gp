reset 
set terminal pngcairo
set title "MFLOPS x N"
set xlabel "N"
set ylabel "MFLOPS"
set logscale x 
set output "picoApico-w-notebook.png"
plot 	"NxMFLOPS-pc-2.dat" u 1:2 w lp title "PC-2", \
	"NxMFLOPS-pc-3.dat" u 1:2 w lp title "PC-3"
