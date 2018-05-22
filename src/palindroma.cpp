#include "palindroma.h"
#include "pilha.h"
#include <iostream>
#include <string>  
/**
 * @file    palindroma.cpp
 * @brief   Classe palindroma
*/



//! Um construtor padrao.
Palindroma::Palindroma():str(""){}

//! destrutor da classe.
Palindroma::~Palindroma(){}

//! Metodo que atribui uma string ao atributo da classe str
/*!
	\param str_ um argumento string.
*/
void Palindroma::setStr(std::string str_){
	str = str_;
}


//! Metodo que retorna o atributo da classe str contendo uma string
std::string Palindroma::getStr(){
	return str;
}

//! Metodo que verifica se a string passada e uma palindroma.
bool Palindroma::verificarPalindroma(std::string str_){

int cont = 0; // contador de caractere
int tam = 0; //	tamanho da pilha


Pilha<char> pilha(str_.size()); //pilha de char, alocando tamanho da string recebida

	//> pecorre a string inserindo cada caractere na pilha
	for(int i = 0; str_[i] != '\0'; i++){
		pilha.push(str_[i]);
	}

	tam = pilha.size(); // pega tamanho atual da pilha 

	//pecorre a pilha comparando caractere por caractere com a string
	//até chegar ao meio (caso a quantidade de elementos seja par)
	//ou ao meio-1(caso a quantidade de elementos seja ímpar)
	for(int i = 0; i < tam/2; i++){
		//se igual incrementa cont
		if(pilha.top() == str_[i])
			cont++;
		//remove elemento do topo
		pilha.pop();
	}

	
	//resultado
	if(cont==tam/2)
		return true;
	else
		return false;
}