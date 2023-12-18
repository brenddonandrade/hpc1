CFLAGS = -fopenmp -I. -lm -O0
CC = gcc
OBJ = pi.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

modelo: $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)
	
.PHONY: clean
clean:
	-rm modelo $(OBJ)
