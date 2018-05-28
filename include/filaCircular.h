#ifndef FC_H
#define FC_H

#include <memory>
#include <iostream>
#include "listaCircular.h"

/**
 * @file    filaCircular.h
 * @brief   Cabeçalho e implementação da classe FilaCircular
*/

using namespace std;
/* Implementacao da classe FilaCircular */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend eh preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class FilaCircular; // Declaracao antecipada da classe
template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, FilaCircular<T> const & );
// --

template <typename T>
class FilaCircular {
private:
	ListaCircular<T> lista; /*!< A lista circular é usada como container para a fila */
public: 
	FilaCircular();
	~FilaCircular();
	bool Inserir(T _valor);
	bool Remover();
	bool vazia();
	int size();

	friend std::ostream& operator<< <T>( std::ostream&, FilaCircular<T> const &l);
};

template <typename T>
FilaCircular<T>::FilaCircular() {

}

template <typename T>
FilaCircular<T>::~FilaCircular() {
	
}

/**Método de inserir valores à fila (enfileirar)*/
template <typename T>
bool FilaCircular<T>::Inserir(T _valor) {
	if(lista.InsereNoFinal(_valor))
		return true;
	else
		return false;
}

/**Método de remover valores da fila (desenfileirar)*/
template <typename T>
bool FilaCircular<T>::Remover() {
	if(lista.RemoveNoInicio()){
		return true;
	}
		
	else
		return false;
}

/**Método para verificação se a lista está vazia*/
template <typename T>
bool FilaCircular<T>::vazia() {
	return lista.vazia();
}

/**Método que informa o tamanho da fila*/
template <typename T>
int FilaCircular<T>::size() {
	return lista.size();
}

/**Sobrecarga do operador de inserção*/
template <typename T>
std::ostream& operator<< ( std::ostream& o, FilaCircular<T> const &l) {
	o << l.lista;

	return o;
}

#endif