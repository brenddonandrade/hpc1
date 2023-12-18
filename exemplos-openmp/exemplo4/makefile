CC = gcc
CFLAGS = -fopenmp -lm
OBJ = exemplo4.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

exemplo: $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm exemplo $(OBJ)
