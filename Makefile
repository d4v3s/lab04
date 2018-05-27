# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Define o nome do executavel
PROG = $(BIN)/prog

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o executavel final
OBJS = $(OBJ)/main.o $(OBJ)/palindroma.o $(OBJ)/rpn.o $(OBJ)/programa1.o $(OBJ)/programa2.o $(OBJ)/programa3.o 

all : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

# Alvo para a compilação com informações de debug
# Altera a flag CPPFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CPPFLAGS += -g -O0 
debug: all

# Alvo para a construcao do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main.o : $(OBJ)/main.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/rpn.o : $(INC)/rpn.h
	$(CC) $(CPPFLAGS) -c $(SRC)/rpn.cpp -o $@

$(OBJ)/palindroma.o : $(INC)/palindroma.h
	$(CC) $(CPPFLAGS) -c $(SRC)/palindroma.cpp -o $@

$(OBJ)/programa1.o : $(INC)/programa1.h
	$(CC) $(CPPFLAGS) -c $(SRC)/programa1.cpp -o $@

$(OBJ)/programa2.o : $(INC)/programa2.h
	$(CC) $(CPPFLAGS) -c $(SRC)/programa2.cpp -o $@

$(OBJ)/programa3.o : $(INC)/programa3.h
	$(CC) $(CPPFLAGS) -c $(SRC)/programa3.cpp -o $@
# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doc:
	rm -drf core $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.
clean:
	rm -f core ./build/*.o ./bin/*