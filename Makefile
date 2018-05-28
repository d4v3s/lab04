# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Define o nome dos executaveis
PROG1 = $(BIN)/prog1
PROG2 = $(BIN)/prog2
PROG3 = $(BIN)/prog3

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam os executaveis finais
OBJS1 = $(OBJ)/palindroma.o $(OBJ)/programa1.o
OBJS2 = $(OBJ)/rpn.o $(OBJ)/programa2.o
OBJS3 = $(OBJ)/programa3.o

# Solicita todos os executáveis para os respectivos programas
all: programa1 programa2 programa3

programa1: $(OBJ)/programa1.o $(OBJ)/palindroma.o
	$(CC) $(CPPFLAGS) $(OBJS1) -o $(PROG1)

programa2: $(OBJ)/programa2.o $(OBJ)/rpn.o
	$(CC) $(CPPFLAGS) $(OBJS2) -o $(PROG2)

programa3: $(OBJ)/programa3.o
	$(CC) $(CPPFLAGS) $(OBJS3) -o $(PROG3)

# Define os arquivos objeto dos quais os programas dependem
$(OBJ)/rpn.o : $(INC)/rpn.h
	$(CC) $(CPPFLAGS) -c $(SRC)/rpn.cpp -o $@

$(OBJ)/palindroma.o : $(INC)/palindroma.h
	$(CC) $(CPPFLAGS) -c $(SRC)/palindroma.cpp -o $@

$(OBJ)/programa1.o : 
	$(CC) $(CPPFLAGS) -c $(SRC)/programa1.cpp -o $@

$(OBJ)/programa2.o : 
	$(CC) $(CPPFLAGS) -c $(SRC)/programa2.cpp -o $@

$(OBJ)/programa3.o :
	$(CC) $(CPPFLAGS) -c $(SRC)/programa3.cpp -o $@

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all


# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	rm -drf core $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	rm -f core ./build/*.o ./bin/*