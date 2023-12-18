old_value=$(grep '#define N' programaTesteProcessador.c | cut -d N -f2)

rm NxMFLOPS.dat

for i in $(seq 1 7)
	do
		./programa >> NxMFLOPS.dat	
		
		echo $i
		value=$(grep '#define N' programaTesteProcessador.c | cut -d N -f2)
		new_value=$((value*10))

		new_value_2=$((new_value/4))
		
		new_2=$((new_value_2*2))
		new_3=$((new_value_2*3))
		echo $new_value_2 $new_2 $new_3 $new_value

		
		sed -i "s/$value/ $new_value_2/g" programaTesteProcessador.c
		gcc -o programa programaTesteProcessador.c -lm
		./programa >> NxMFLOPS.dat

		sed -i "s/$new_value_2/ $new_2/g" programaTesteProcessador.c
		gcc -o programa programaTesteProcessador.c -lm
		./programa >> NxMFLOPS.dat

		sed -i "s/$new_2/ $new_3/g" programaTesteProcessador.c
		gcc -o programa programaTesteProcessador.c -lm
		./programa >> NxMFLOPS.dat
		
		sed -i "s/$new_3/ $new_value/g" programaTesteProcessador.c
		gcc -o programa programaTesteProcessador.c -lm
		./programa >> NxMFLOPS.dat
	
	done

sed -i "s/$new_value/ $old_value/g" programaTesteProcessador.c
#gnuplot plot_picoApico.gp
#xdg-open picoApico.png
