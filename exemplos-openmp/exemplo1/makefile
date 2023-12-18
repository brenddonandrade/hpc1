CC=gcc
CFLAGS = -I. -fopenmp
OBJ = exemplo1.o

%.o: %.c
	$(CC) -c -o $@ $(CFLAGS)

exemplo: $(OBJ)
	$(CC) -o exemplo $(OBJ) $(CFLAGS)

.PHONY: clean
clean:
	rm exemplo %.o
