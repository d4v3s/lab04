#include "programa3.h"
#include <cstdlib>

using namespace std;

Programa3::Programa3(){
	listLigCircInt = make_shared<ListLigCirc<int>>();
	listLigCircStr = make_shared<ListLigCirc<string>>();
}

Programa3::~Programa3(){

}

int Programa3::programa3ListaAutomatico(){
	cout << "-Testando a lista com 'STRINGS'" << endl;
	cout << ">Inserindo o valor 'Laboratorio 4' no inicio da lista" << endl;
	listLigCircStr->InsereNoInicio("Laboratorio 4");
	cout << ">Inserindo o valor 'Projeto finalizado!' no inicio da lista" << endl;
	listLigCircStr->InsereNoInicio("Projeto finalizado!");
	cout << ">Inserindo o valor 'Aqui é o fim!' no fim da lista" << endl;
	listLigCircStr->InsereNoFinal("Aqui é o fim");	
	cout << ">Inserindo o valor 'Posição 3' no indice 2" << endl;
	listLigCircStr->InsereNaPosicao(2,"Posição 3");	

	cout << ">Imprimindo o conteúdo da lista:" << endl;
	cout << *listLigCircStr;

	cout << endl;

	cout << "-Testando a lista com 'INTEIROS'" << endl;
	cout << ">Inserindo o valor '2' no inicio da lista" << endl;
	listLigCircInt->InsereNoInicio(2);
	cout << ">Inserindo o valor '1' no inicio da lista" << endl;
	listLigCircInt->InsereNoInicio(1);
	cout << ">Inserindo o valor '4' no fim da lista" << endl;
	listLigCircInt->InsereNoFinal(4);	
	cout << ">Inserindo o valor '3' no indice 2" << endl;
	listLigCircInt->InsereNaPosicao(2, 3);

	cout << ">Imprimindo o conteúdo da lista:" << endl;
	cout << *listLigCircInt;		

	return 0;
}

int Programa3::programa3FilaAutomatico(){
	return 0;
}

int Programa3::programa3ListaManual(){
	return 0;
}

int Programa3::programa3FilaManual(){
	return 0;
}

void Programa3::menuProg3(){
	short op;

	do{
		cout << endl;
		cout << "Digite '1' para testar Listas Encadeadas Circulares automaticamente" << endl;
		cout << "Digite '2' para testar uma Lista Encadeada Circular manualmente" << endl;
		cout << "Digite '3' para testar Filas Circulares automaticamente" << endl;
		cout << "Digite '4' para testar uma Fila Circular manualmente" << endl;
		cout << "Digite '5' para voltar" << endl;
		cout << endl;
		cout << ">Opção: ";
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				system("clear");
				programa3ListaAutomatico();
			break;
			case 2:
				system("clear");
				programa3ListaManual();
			break;
			case 3:
				system("clear");
				programa3FilaAutomatico();
			break;
			case 4:
				programa3FilaManual();
				system("clear");				
			break;
			case 5:
				system("clear");
			}

		if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5) cout << "Operação inválida" << endl;

	}while(op != 5);
}