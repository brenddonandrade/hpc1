cd ./source

gcc -o teste modelo_de_opiniao.c -lm
./teste

gnuplot plot_population.gp
xdg-open populationState.png

# cat populationState.dat
