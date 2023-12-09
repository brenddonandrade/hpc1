reset 
set terminal pngcairo
set title "Population Relation Time"
set output "../data/graphics/relaxation/relaxation_time.png"
set xlabel "Cu [%]"
set ylabel "τ [STEPS]"

plot "relaxation_time.dat" u 2:1 w lp title "Cu"
