reset 
set terminal pngcairo
set title "Population State"
set output "populationState.png"
plot "populationState.dat" matrix with image
