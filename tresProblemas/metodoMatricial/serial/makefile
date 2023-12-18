CFLAGS = -lm -I. -O0
CC = gcc
OBJ = metodos2.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

modelo: $(OBJ)
	$(CC) -o $@ $< $(CFLAGS)
	
.PHONY: clean
clean:
	-rm modelo $(OBJ)
