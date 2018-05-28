/**
 * @file    programa3.cpp
 * @brief   Implementação dos testes e menus, além da execução do programa da questão 3
*/

#include "listaCircular.h"
#include "filaCircular.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int programa3ListaAutomatico(){

	shared_ptr<ListaCircular<int>> listLigCircInt(new ListaCircular<int>);
	shared_ptr<ListaCircular<string>> listLigCircStr(new ListaCircular<string>);

	cout << ">Testando a lista com 'STRINGS'" << endl;
	cout << "+Inserindo o valor 'Laboratorio 4' no inicio da lista" << endl;
	listLigCircStr->InsereNoInicio("Laboratorio 4");
	cout << *listLigCircStr << endl;
	cout << "+Inserindo o valor 'Projeto finalizado!' no inicio da lista" << endl;
	listLigCircStr->InsereNoInicio("Projeto finalizado!");
	cout << *listLigCircStr << endl;
	cout << "+Inserindo o valor 'Aqui é o fim!' no fim da lista" << endl;
	listLigCircStr->InsereNoFinal("Aqui é o fim");	
	cout << *listLigCircStr << endl;
	cout << "+Inserindo o valor 'Posição 3' no indice 2" << endl;
	listLigCircStr->InsereNaPosicao(2,"Posição 3");	
	cout << *listLigCircStr << endl;
	cout << "-Removendo no final" << endl;
	listLigCircStr->RemoveNoFinal();
	cout << *listLigCircStr << endl;
	cout << "-Removendo no final" << endl;
	listLigCircStr->RemoveNoFinal();
	cout << *listLigCircStr << endl;
	cout << "-Removendo na posicao 1" << endl;
	listLigCircStr->RemoveNaPosicao(1);
	cout << *listLigCircStr << endl;
	cout << "-Removendo no inicio" << endl;
	listLigCircStr->RemoveNoInicio();
	cout << *listLigCircStr << endl;
	cout << endl;

 	cout << ">Testando a lista com 'INTEIROS'" << endl;
	cout << "+Inserindo o valor '2' no inicio da lista" << endl;
	listLigCircInt->InsereNoInicio(2);
	cout << *listLigCircInt << endl;
	cout << "+Inserindo o valor '1' no inicio da lista" << endl;
	listLigCircInt->InsereNoInicio(1);
	cout << *listLigCircInt << endl;
	cout << "+Inserindo o valor '4' no fim da lista" << endl;
	listLigCircInt->InsereNoFinal(4);	
	cout << *listLigCircInt << endl;
	cout << "+Inserindo o valor '3' no indice 2" << endl;
	listLigCircInt->InsereNaPosicao(2, 3);	
	cout << *listLigCircInt << endl;
	cout << "-Removendo no final" << endl;
	listLigCircInt->RemoveNoFinal();
	cout << *listLigCircInt << endl;
	cout << "-Removendo no final" << endl;
	listLigCircInt->RemoveNoFinal();
	cout << *listLigCircInt << endl;
	cout << "-Removendo na posicao 1" << endl;
	listLigCircInt->RemoveNaPosicao(1);
	cout << *listLigCircInt << endl;
	cout << "-Removendo no inicio" << endl;
	listLigCircInt->RemoveNoInicio();
	cout << *listLigCircInt << endl;

	return 0;
}

int programa3FilaAutomatico(){

	shared_ptr<FilaCircular<string>> filaCircularStr(new FilaCircular<string>);

	cout << ">Testando a fila com 'STRINGS'" << endl;
	cout << "+Inserindo o 'Pedro' na fila" << endl;
	filaCircularStr->Inserir("Pedro");
	cout << *filaCircularStr << endl;
	cout << "+Inserindo o 'Fulano' na fila" << endl;
	filaCircularStr->Inserir("Fulano");
	cout << *filaCircularStr << endl;
	cout << "+Inserindo a 'Amanda' na fila" << endl;
	filaCircularStr->Inserir("Amanda");
	cout << *filaCircularStr << endl;
	cout << "+Inserindo a 'Carla' na fila" << endl;
	filaCircularStr->Inserir("Carla");
	cout << *filaCircularStr << endl;
	cout << "-Removendo o Pedro" << endl;
	filaCircularStr->Remover();
	cout << *filaCircularStr << endl;
	cout << "-Removendo o Fulano" << endl;
	filaCircularStr->Remover();
	cout << *filaCircularStr << endl;
	cout << "-Removendo a Amanda" << endl;
	filaCircularStr->Remover();
	cout << *filaCircularStr << endl;
	cout << "-Removendo a Carla" << endl;
	filaCircularStr->Remover();
	cout << *filaCircularStr << endl;
	cout << endl;

	shared_ptr<FilaCircular<int>> filaCircularInt(new FilaCircular<int>);
	
	cout << ">Testando a lista com 'INTEIROS'" << endl;
	for(int i = 4; i > 0; i--){
		cout << "+Inserindo o valor '"<< i <<"' na fila" << endl;
		filaCircularInt->Inserir(i);
		cout << *filaCircularInt << endl;
	}
 	
	for(int i = 4; i > 0; i--){
		cout << "-Removendo o "<< i <<" da fila" << endl;	
		filaCircularInt->Remover();
		cout << *filaCircularInt << endl;
	}

	return 0;
}

int programa3ListaManual(){
	short op;
	int indice;
	string valor;
	shared_ptr<ListaCircular<string>> listLigCircStr(new ListaCircular<string>);

	do{
		cout << endl;
		cout << "Digite '1' para inserir no inicio da fila" << endl;
		cout << "Digite '2' para inserir no final da fila" << endl;
		cout << "Digite '3' para inserir especificando o índice na fila" << endl;
		cout << "Digite '4' para remover no inicio da fila" << endl;
		cout << "Digite '5' para remover no fim da fila" << endl;
		cout << "Digite '6' para remover especificando o índice na fila" << endl;
		cout << "Digite '7' para exibir a lista" << endl;
		cout << "Digite '8' para exibir o tamanho da lista" << endl;
		cout << "Digite '9' para verificar se a fila está vazia" << endl;
		cout << "Digite '10' para voltar" << endl;
		cout << endl;
		cout << ">Opção: ";
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				system("clear");
				cout << "Por favor insira algo: ";
				cin.ignore();
				getline(cin, valor);
				listLigCircStr->InsereNoInicio(valor);
				cout << *listLigCircStr << endl;
			break;
			case 2:
				system("clear");
				cout << "Por favor insira algo: ";
				cin.ignore();
				getline(cin, valor);
				listLigCircStr->InsereNoFinal(valor);
				cout << *listLigCircStr << endl;
			break;
			case 3:
				system("clear");
				cout << "Informe o índice da posição na fila: ";
				cin >> indice;
				cout << "Por favor insira algo: ";
				cin.ignore();
				getline(cin, valor);
				listLigCircStr->InsereNaPosicao(indice, valor);
				cout << *listLigCircStr << endl;
			break;
			case 4:
				system("clear");				
				listLigCircStr->RemoveNoInicio();
				cout << *listLigCircStr << endl;
			break;
			case 5:
				system("clear");
				listLigCircStr->RemoveNoFinal();
				cout << *listLigCircStr << endl;
			break;
			case 6:
				system("clear");
				cout << "Informe o índice da posição na fila: ";
				cin >> indice;
				listLigCircStr->RemoveNaPosicao(indice);
				cout << *listLigCircStr << endl;
			break;
			case 7:
				system("clear");
				cout << *listLigCircStr << endl;
			break;
			case 8:
				system("clear");
				cout << "Tamanho: " << listLigCircStr->size() << endl;
				cout << *listLigCircStr << endl;
			break;
			case 9:
				system("clear");
				if(listLigCircStr->vazia())
					cout << "Lista vazia" << endl;
				else{
					cout << "Lista não vazia" << endl;
					cout << *listLigCircStr << endl;
				}
			break;
			case 10:
				system("clear");
			}

		if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6 && op != 7 && op != 8 && op != 9 && op != 10)
			cout << "Operação inválida" << endl;

	}while(op != 10);

	return 0;
}

int programa3FilaManual(){
	short op;
	string valor;
	shared_ptr<FilaCircular<string>> filaCircularStr(new FilaCircular<string>);

	do{
		cout << endl;
		cout << "Digite '1' para inserir elemento na fila" << endl;
		cout << "Digite '2' para remover elemento da fila" << endl;
		cout << "Digite '3' para exibir a fila" << endl;
		cout << "Digite '4' para exibir o tamanho da fila" << endl;
		cout << "Digite '5' para verificar se a fila está vazia" << endl;
		cout << "Digite '6' para voltar" << endl;
		cout << endl;
		cout << ">Opção: ";
		cin >> op;
		cout << endl;

		switch(op){
			case 1:
				system("clear");
				cout << "Por favor insira algo: ";
				cin.ignore();
				getline(cin, valor);
				filaCircularStr->Inserir(valor);
				cout << *filaCircularStr << endl;
			break;
			case 2:				
				filaCircularStr->Remover();
				cout << *filaCircularStr << endl;
			break;
			case 3:
				system("clear");
				cout << *filaCircularStr << endl;
			break;
			case 4:
				system("clear");				
				cout << "Tamanho: " << filaCircularStr->size() << endl;
				cout << *filaCircularStr << endl;
			break;
			case 5:
				system("clear");
				if(filaCircularStr->vazia())
					cout << "Fila vazia" << endl;
				else{
					cout << "Fila não vazia" << endl;
					cout << *filaCircularStr << endl;
				}
			break;
			case 6:
				system("clear");
				
			}

		if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5 && op != 6)
			cout << "Operação inválida" << endl;

	}while(op != 6);
	return 0;
}

void menuProg3(){
	short op;

	do{
		cout << endl;
		cout << "Digite '1' para testar Listas Encadeadas Circulares automaticamente" << endl;
		cout << "Digite '2' para testar uma Lista Encadeada Circular manualmente" << endl;
		cout << "Digite '3' para testar Filas Circulares automaticamente" << endl;
		cout << "Digite '4' para testar uma Fila Circular manualmente" << endl;
		cout << "Digite '5' para sair" << endl;
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
			}

		if(op != 1 && op != 2 && op != 3 && op != 4 && op != 5) cout << "Operação inválida" << endl;

	}while(op != 5);
}

int main(){
	menuProg3();

	return 0;
}