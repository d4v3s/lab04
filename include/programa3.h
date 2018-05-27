#ifndef PROGRAMA3_H
#define PROGRAMA3_H

#include "listaCircular.h"
#include "filaCircular.h"
#include <iostream>
#include <string>

class Programa3{
private:
	std::shared_ptr<FilaCircular<int>>filaCircularInt;
	std::shared_ptr<FilaCircular<string>>filaCircularStr;
	std::shared_ptr<ListaCircular<int>>listLigCircInt;
	std::shared_ptr<ListaCircular<string>>listLigCircStr;
public:
	Programa3();
	~Programa3();
	int programa3ListaAutomatico();
	int programa3FilaAutomatico();
	int programa3ListaManual();
	int programa3FilaManual();
	void menuProg3();
};

#endif