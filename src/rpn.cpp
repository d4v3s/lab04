#include "rpn.h"
#include "pilha.h"
#include <iostream>
#include <sstream>
#include <string>  
/**
 * @file    rpn.cpp
 * @brief   Classe rpn (Reverse Polish Notation)
*/
using namespace std;

//! Um construtor padrao.
Rpn::Rpn():expressao(""){}

//! destrutor da classe.
Rpn::~Rpn(){}

//! Metodo que atribui uma string ao atributo expressao da classe 
/*!
	\param expressao_ um argumento string.
*/
void Rpn::setExpressao(string expressao_){
	expressao = expressao_;
}


//! Metodo que retorna o atributo da classe expressao contendo uma string
string Rpn::getExpressao(){
	return expressao;
}

//! Metodo que recebe uma expressao em notação polonesa inversa
//  e retorna o resultado int
//!
int Rpn::resolver(string expressao_){

stringstream ss(expressao_); // buffer para manipular a string

string aux;

Pilha<string> p2(expressao_.size()); //cria uma pilha de string alocando tamanho da expressao
	
	//pecorre o buffer e vai atribuindo a aux
	while(ss >> aux){

			//adicionar na pilha somente se for numeros 
			if(aux!="+" && aux!="-" && aux!="*" &&  aux!="/"){
				p2.push(aux);
			}

			//tratar operacoes, quando aux receber
			if(aux=="+"){
					int calc=0;
					//resolver a opercao indicada ate esvaziar a pilha
					while(!p2.empty()){ 
						//valor do topo
						calc+=std::stod(p2.top());
						p2.pop(); //remove valor do topo
					}
					//resultado coloca de volta na pilha limpa
					p2.push(std::to_string(calc));
			}

			if(aux=="-"){
					int calc=std::stod(p2.top()); 
					p2.pop(); 
					//resolver a opercao indicada ate esvaziar a pilha
					while(!p2.empty()){
						//valor do topo
						calc = std::stod(p2.top()) - calc; 
						p2.pop(); 
					}
					//resultado de volta na pilha
					p2.push(std::to_string(calc));
			}
			if(aux=="*"){
					int calc=1;
					//resolver a opercao indicada ate esvaziar a pilha
					while(!p2.empty()){
						//valor do topo
						calc*=std::stod(p2.top());
						p2.pop();
					}
					//resultado de volta na pilha
					p2.push(std::to_string(calc));
			}
			if(aux=="/"){
					int calc=std::stod(p2.top()); 
					p2.pop(); 
					//resolver a opercao indicada ate esvaziar a pilha
					while(!p2.empty()){
						//valor do topo
						
						calc = std::stod(p2.top()) / calc; 
						p2.pop(); 
						
						
					}
					//resultado de volta na pilha
					p2.push(std::to_string(calc));
					
					
			}
	}

	return std::stod(p2.top());
}