#ifndef PROGRAMA2_H
#define PROGRAMA2_H

#include "rpn.h"
#include "pilha.h"
#include <iostream>
#include <string>

class Programa2{
private:
	std::string expressao;
	std::shared_ptr<Rpn>calc;
public:
	Programa2();
	~Programa2();
	int programa2Automatico();
	int programa2Manual();
	void menuProg2();
};

#endif