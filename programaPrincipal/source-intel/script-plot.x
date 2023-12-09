#!/bin/bash

sed -i "s/populationState-/populationState-$1/g" plot_population.gp
sed -i "s/Population State/Population State Steps=$1/g" plot_population.gp

gnuplot plot_population.gp
sed -i "s/populationState-$1/populationState-/g" plot_population.gp
sed -i "s/Population State Steps=$1/Population State/g" plot_population.gp
