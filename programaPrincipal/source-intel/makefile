# Autor: Brenddon Oliveira
# Data: 15/09 ver: 0.1


#lab107c
#MKLROOT = /opt/intel/oneapi/mkl/2023.0.0/

#b710
#MKLROOT = /scratch/app/oneapi/2022.2/mkl/2022.1.0/

#sequana
#MKLROOT =  /opt/intel/oneapi/2022/mkl/2022.0.2/

# serial
#LIBS = -Wl,--start-group ${MKLROOT}/lib/ia32/libmkl_intel.a ${MKLROOT}/lib/ia32/libmkl_sequential.a ${MKLROOT}/lib/ia32/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
#(COMP   -I"${MKLROOT}/include")


# Paralelo
#LIBS = -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_intel_thread.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -liomp5 -lpthread -lm -ldl
#(COMP  -I"${MKLROOT}/include" )


CC=icc
#CFLAGS= -I. -lm -lncurses -no-multibyte-chars 
#CFLAGS= -I. -O2  -lm -lncurses -I"${MKLROOT}/include" -no-multibyte-chars 
CFLAGS= -I. -O2 -lm -lncurses -qopenmp -no-multibyte-chars -I"${MKLROOT}/include"


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
