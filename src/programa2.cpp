#include <cstdlib>
#include <iostream>
#include <string>
#include <memory>
#include "rpn.h"

using namespace std;

int programa2Automatico(){
	string expressao;
	shared_ptr<Rpn>calc;

	expressao = "5 3 * 2 * 10 /";
	cout << ">Operação realizada: " << expressao << endl;
	int result = calc->resolver(expressao);
	
	cout << "-Resultado: " << result << endl;	

	expressao = "4 6 + 2 * 10 /";
	cout << "-Operação realizada: " << expressao << endl;
	result = calc->resolver(expressao);
	
	cout << "-Resultado: " << result << endl;	

	cout << endl;

	return 0;
}

int programa2Manual(){
	string expressao;
	shared_ptr<Rpn>calc;

	cout << "-Exemplo: '5 3 * 2 * 10 /'" << endl;
	cout << ">Por favor insira uma expressão:";
	
	cin.ignore();
	getline(cin, expressao);

	cout << "-Operação realizada: " << expressao << endl;
	int result = calc->resolver(expressao);
	
	cout << "-Resultado: " << result << endl;

	cout << endl;

	return 0;	
}

void menuProg2(){
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
				programa2Automatico();
			break;
			case 2:
				system("clear");
				programa2Manual();
			break;
			case 3:
				system("clear");
		}

		if(op != 1 && op != 2 && op != 3) cout << "Operação inválida" << endl;

	}while(op !=3);
}

int main(){
	menuProg2();

	return 0;
}
