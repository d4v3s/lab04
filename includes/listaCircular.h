#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <iostream>
#include <memory>
#include "lista.h"

using namespace std;

/* Implementacao da classe ListaCircular */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend eh preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class ListaCircular; // Declaracao antecipada da classe

template <typename T> // Definicao antecipada do template para o operador de insercao
std::ostream& operator<<( std::ostream&, ListaCircular<T> const & );

template <typename T>
class ListaCircular : public ListaLigada <T>{
private:
	shared_ptr<Node<T>> cabeca;
	shared_ptr<Node<T>> cauda;
	int tamanho;
public:
	ListaCircular();
	~ListaCircular();
	bool InsereNoInicio(T _valor);
	bool InsereNoFinal(T _valor);
	bool InsereNaPosicao(int pos, T _valor);
	bool RemoveNoInicio();
	bool RemoveNoFinal();
	bool RemoveNaPosicao(int pos);

	friend std::ostream& operator<< <T>( std::ostream&, ListaCircular<T> const &l);
};

template <typename T>
ListaCircular<T>::ListaCircular(): cabeca(nullptr), cauda(nullptr), tamanho(0) {
	ListaLigada<T>();
}

template <typename T>
ListaCircular<T>::~ListaCircular() {

	while (cabeca != this->cauda){
		cauda->setNext(cabeca->getNext());
		cabeca = cabeca->getNext();
	}

	cauda->setNext(nullptr);
		
}

template <typename T>
/**Sobrecarga do método de inserção no início da fila*/
bool ListaCircular<T>::InsereNoInicio(T _valor) {

	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setNext(this->cabeca);
	this->cabeca = novo;
	this->tamanho++;

	auto atual = cabeca;  /*!< Auxiliar para percorrer a lista */

	/** @brief Procura o ultimo valor da lista*/
	for(int i = 0; i < tamanho-1; i++){
		atual = atual->getNext(); 
	}

	this->cauda = atual; /*!< cauda recebe o endereço do último valor da lista */
	this->cauda->setNext(this->cabeca); /*!< A cabeça da fila é definida como próximo valor após a cauda */

	return true;
}

template <typename T>
/**Sobrecarga do método de inserção no fim da fila*/
bool ListaCircular<T>::InsereNoFinal(T _valor) {
	if (this->cabeca == nullptr) {
		return InsereNoInicio(_valor);
	} else {
		auto atual = this->cabeca;

		for(int i = 0; i < tamanho-1; i++)
			atual = atual->getNext(); 
				
		auto novo = make_shared<Node<T>>(_valor);
		if (!novo) return false;

		atual->setNext(novo);
		this->cauda = novo;
		cauda->setNext(this->cabeca);
		this->tamanho++;
	}

	return true;
}

template <typename T>
/**Sobrecarga do método de inserção em uma posição específica da fila*/
bool ListaCircular<T>::InsereNaPosicao(int pos, T _valor) {
	if (pos<0) return false;
	if (pos==0)	return InsereNoInicio(_valor);
	if (pos==tamanho) return InsereNoFinal(_valor);

	if (pos > tamanho) return false;

	auto atual = this->cabeca;
	int posAtual = 0;
	while (atual->getNext() != this->cauda && posAtual < pos-1) {
		atual = atual->getNext();
		posAtual++;
	}
	
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setNext(atual->getNext());
	atual->setNext(novo);
	this->tamanho++;

	return true;
}

template <typename T>
/**Sobrecarga do método de remoção no início da fila*/
bool ListaCircular<T>::RemoveNoInicio() {
	if(!ListaLigada<T>::vazia()){
		if (this->cabeca==nullptr) return false;
		cabeca = cabeca->getNext();
		this->tamanho--;
		return true;
	}else
		return false;
}

template <typename T>
/**Sobrecarga do método de remoção no final da fila*/
bool ListaCircular<T>::RemoveNoFinal() {
	if(!ListaLigada<T>::vazia()){
		if (this->cabeca==nullptr) return false;

		if (this->cabeca->getNext()==this->cauda) {
			this->cabeca = this->cauda;
			this->tamanho--;
			return true;
		}

		auto atual = this->cabeca;
		while (atual->getNext()->getNext() != this->cauda)
			atual = atual->getNext();

		this->cauda = atual->getNext();
		atual->setNext(this->cauda);

		this->tamanho--;

		return true;
	}else
		return false;
}

template <typename T>
/**Sobrecarga do método de remoção em posição específica da fila*/
bool ListaCircular<T>::RemoveNaPosicao(int pos) {
	if(!ListaLigada<T>::vazia()){
		if (pos<0) return false;
		if (pos==0)	return RemoveNoInicio();
		if (pos==tamanho-1) return RemoveNoFinal();

		if (pos > tamanho-1) return false;

		auto atual = this->cabeca;
		int posAtual = 0;
		while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
			atual = atual->getNext();
			posAtual++;
		}

		atual->setNext(atual->getNext()->getNext());
		this->tamanho--;

		return true;
	}else
		return false;
}

template <typename T>
/**Sobrecarga do operador de inserção para a fila circular*/
std::ostream& operator<< ( std::ostream& o, ListaCircular<T> const &l) {
	auto atual = l.cabeca;

	for(int i = 0; i < l.tamanho; i++){	
		o << "-Elemento " << i+1 << ": " <<atual->getValor() << endl;
		atual = atual->getNext();
	}		

	return o;
}

#endif