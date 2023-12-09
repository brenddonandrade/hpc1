reset 
set terminal pngcairo
set title "Population Relation Time"
set output "relaxation_time.png"
set xlabel "Cu [%]"
set ylabel "τ [STEPS]"

plot "relaxation_time_save.dat" u 2:1 w lp title "Cu"
