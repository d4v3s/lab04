#ifndef PROGRAMA1_H
#define PROGRAMA1_H

#include "palindroma.h"
#include "pilha.h"
#include <iostream>
#include <string>

class Programa1{
private:
	std::string str;
	std::shared_ptr<Palindroma>p;
public:
	Programa1();
	~Programa1();
	int programa1Automatico();
	int programa1Manual();
	void menuProg1();
};

#endif