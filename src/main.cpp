#include <iostream>
#include <string>  
#include <cstdlib>
#include "programa1.h"
#include "programa2.h"
#include "programa3.h"

using namespace std;

void menu(){
	short op;
	Programa1 questao1;
	Programa2 questao2;
	Programa3 questao3;

	do{
		cout << endl;
		cout << "Digite '1' para testar a questão 1" << endl;
		cout << "Digite '2' para testar a questão 2" << endl;
		cout << "Digite '3' para testar a questão 3" << endl;
		cout << "Digite '4' para encerrar" << endl;
		cout << ">Opção: ";
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				system("clear");
				questao1.menuProg1();
			break;
			case 2:
				system("clear");
				questao2.menuProg2();
			break;
			case 3:
				system("clear");
				questao3.menuProg3();
			break;
			case 4:
				cout << "Saindo..." << endl;
		}

		if(op != 1 && op != 2 && op != 3 && op != 4) cout << "Operação inválida" << endl;

	}while(op != 4);
}

int main() {
	menu();
}

