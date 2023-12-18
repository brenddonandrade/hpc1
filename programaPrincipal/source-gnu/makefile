# Autor: Brenddon Oliveira
# Data: 15/09 ver: 0.1

# Serial
#MKLROOT = /opt/intel/oneapi/mkl/2023.0.0/
#LIBS =  -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
#(COMP  -m64  -I"${MKLROOT}/include")


# Paralelo
#MKLROOT = /opt/intel/oneapi/mkl/2023.0.0/
#LIBS = -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_gnu_thread.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lgomp -lpthread -lm -ldl


CC=gcc
#CFLAGS= -I. -lm -lncurses 
#CFLAGS= -I. -O3 -lm -lncurses 
CFLAGS= -I. -O3 -lm -lncurses -fopenmp

DEPS=../lib/modelo_de_opiniao.h
OBJ=../obj/modelo_de_opiniao.o
SOURCE=./modelo_de_opiniao.c
# Todos os arquivos ".o" dependem de de seus respectivos ".c" e da dependencia
# "-c" diz para gerar o arquivo objeto
# "-o $@" diz para colocar a saída da compilacao no arquivo nomeado no lado esquedo de ":"
# "$<" é o primeiro item na lista de dependencias


programa: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(OBJ): $(SOURCE) $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean
clean:
	rm -f $(OBJ) programa
