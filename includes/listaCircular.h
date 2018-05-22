#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <iostream>
#include <memory>

using namespace std;

/* Implementacao da classe ListaCircular */

/* Para permitir sobrecarregar o operador de insercao
   numa classe template como friend eh preciso adicionar
   o trecho de codigo a seguir */
template <typename T> class ListaCircular; // Declaracao antecipada da classe

template <typename T>
class ListaCircular : public ListaLigada{
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
};

template <typename T>
ListaCircular<T>::ListaCircular(): cabeca(nullptr), cauda(cabeca), tamanho(0) {
	ListaLigada();
}

template <typename T>
ListaCircular<T>::~ListaCircular() {
	while (cabeca != this->cauda)
		cabeca = cabeca->getNext();
}

template <typename T>
bool ListaCircular<T>::InsereNoInicio(T _valor) {
	auto novo = make_shared<Node<T>>(_valor);
	if (!novo) return false;

	novo->setNext(this->cabeca);
	this->cabeca = novo;
	this->tamanho++;

	auto atual = make_shared<Node<T>>(_valor);

	while(atual->getNext() != cauda)
		atual = atual->getNext();

	this->cauda = atual;
	this->cauda->setNext(this->cabeca);

	return true;
}

template <typename T>
bool ListaCircular<T>::InsereNoFinal(T _valor) {
	if (this->cabeca == nullptr) {
		return InsereNoInicio(_valor);
	} else {
		auto atual = this->cabeca;
		while (atual->getNext() != this->cauda)
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
bool ListaCircular<T>::InsereNaPosicao(int pos, T _valor) {
	if (pos>tamanho-1) return false;
	if (pos<0) return false;
	if (pos==0)	return InsereNoInicio(_valor);
	if (pos==tamanho-1) return InsereNoFinal(_valor);

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
bool ListaCircular<T>::RemoveNoInicio() {
	if (this->cabeca==nullptr) return false;
	cabeca = cabeca->getNext();
	this->tamanho--;
	return true;
}

template <typename T>
bool ListaCircular<T>::RemoveNoFinal() {
	if (this->cabeca==nullptr) return false;

	if (this->cabeca->getNext()==this->cauda) {
		this->cabeca = this->cauda;
		this->tamanho--;
		return true;
	}

	auto atual = this->cabeca;
	while (atual->getNext()->getNext() != this->cauda)
		atual = atual->getNext();
	atual->setNext(this->cauda);
	this->tamanho--;

	return true;
}

template <typename T>
bool ListaCircular<T>::RemoveNaPosicao(int pos) {
	if (pos<0) return false;
	if (pos==0)	return RemoveNoInicio();

	auto atual = this->cabeca;
	int posAtual = 0;
	while (atual->getNext()->getNext() != this->cauda && posAtual < (pos-1)) {
		atual = atual->getNext();
		posAtual++;
	}

	atual->setNext(atual->getNext()->getNext());
	this->tamanho--;

	return true;
}

#endif