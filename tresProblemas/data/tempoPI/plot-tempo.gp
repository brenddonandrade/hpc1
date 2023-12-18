reset 
set terminal pngcairo
set title "{/:Bold Tempo da Compilação X OX-Threads}"
set output "./tempoXox-threads.png"
set xlabel "O's"
set ylabel "Tempo[s]"
set autoscale 

set key autotitle columnheader
set key box lt -1 lw 2

# plot
plot 	"tempo-comp.txt" u 1:2:xtic(1) w lp title "Serial", \
	"tempo-comp.txt" u 1:3:xtic(1) w lp title "Thread-1", \
	"tempo-comp.txt" u 1:4:xtic(1) w lp title "Thread-2", \
	"tempo-comp.txt" u 1:5:xtic(1) w lp title "Thread-3", \
	"tempo-comp.txt" u 1:6:xtic(1) w lp title "Thread-4", \
	"tempo-comp.txt" u 1:7:xtic(1) w lp title "Thread-6", \
	"tempo-comp.txt" u 1:8:xtic(1) w lp title "Thread-8", \
