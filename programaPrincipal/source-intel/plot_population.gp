# plot_population.gp
reset
set terminal pngcairo
set title "Population State"

datafile =  "./dados-matrizes/populationState-.dat"

set output "./imagens/populationState-.png"

set xrange [0:*]
set yrange [0:*]

plot datafile matrix with image
