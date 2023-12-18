CC=gcc
CFLAGS = -fopenmp -lm
OBJ = exemplo2.o

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS)
	
exemplo: $(OBJ)
	$(CC) -o exemplo $(OBJ) $(CFLAGS)

.PHONY: clean
clean:
	rm exemplo %.o
