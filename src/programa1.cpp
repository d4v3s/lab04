/**
 * @file    programa1.cpp
 * @brief   Implementação dos testes e menus, além da execução do programa da questão 1
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include "palindroma.h"

using namespace std;

int programa1Automatico(){
	shared_ptr<Palindroma>p;
	string str;

	cout << ">Testando com a palavra 'carro'" << endl;
	str = "carro";

	if(p->verificarPalindroma(str))
		cout << "-Palíndroma!" << endl;
	else
		cout << "-Não é palíndroma!" << endl;

	cout << ">Testando com a palavra 'arara'" << endl;

	str = "arara";

	if(p->verificarPalindroma(str))
		cout << "-Palíndroma!" << endl;
	else
		cout << "-Não é palíndroma!" << endl;

	cout << endl;

	return 0;
}

int programa1Manual(){
	shared_ptr<Palindroma>p;
	string str;

	cout << "Por favor insira uma palavra: ";
	cin >> str;

	if(p->verificarPalindroma(str))
		cout << "-Palíndroma!" << endl;
	else
		cout << "-Não é palíndroma!" << endl;

	cout << endl;

	return 0;
}

void menuProg1(){
	short op;

	do{
		cout << "Digite '1' para testar automaticamente" << endl;
		cout << "Digite '2' para testar manualmente" << endl;
		cout << "Digite '3' para sair" << endl;
		cout << ">Opção: ";
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				system("clear");
				programa1Automatico();
			break;
			case 2:
				system("clear");
				programa1Manual();
		}

		if(op != 1 && op != 2 && op != 3) cout << "Operação inválida" << endl;

	}while(op !=3);
}

int main(){
	menuProg1();

	return 0;
}