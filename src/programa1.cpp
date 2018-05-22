#include "programa1.h"
#include <cstdlib>

using namespace std;

Programa1::Programa1(){
	p = make_shared<Palindroma>();
}

Programa1::~Programa1(){

}

int Programa1::programa1Automatico(){
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

int Programa1::programa1Manual(){
	cout << "Por favor insira uma palavra: ";
	cin >> str;

	if(p->verificarPalindroma(str))
		cout << "-Palíndroma!" << endl;
	else
		cout << "-Não é palíndroma!" << endl;

	cout << endl;

	return 0;
}

void Programa1::menuProg1(){
	short op;

	do{
		cout << "Digite '1' para testar automaticamente" << endl;
		cout << "Digite '2' para testar manualmente" << endl;
		cout << "Digite '3' para voltar" << endl;
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
			break;
			case 3:
				system("clear");
		}

		if(op != 1 && op != 2 && op != 3) cout << "Operação inválida" << endl;

	}while(op !=3);
}
