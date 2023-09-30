CC=gcc
CFLAGS=-I. -lm
DEPS=modelo_de_opiniao.h
OBJ=modelo_de_opiniao.o

# Todos os arquivos ".o" dependem de de seus respectivos ".c" e da dependencia
# "-c" diz para gerar o arquivo objeto
# "-o $@" diz para colocar a saída da compilacao no arquivo nomeado no lado esquedo de ":"
# "$<" é o primeiro item na lista de dependencias
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

modelo: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

