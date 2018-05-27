#ifndef FC_H
#define FC_H

#include <memory>
#include <iostream>

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
	shared_ptr<FilaCircular<T>> lista;
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

template <typename T>
bool FilaCircular<T>::Inserir(T _valor) {
	if(lista.InserirNoFinal(_valor))
		return true;
	else
		return false;
}

template <typename T>
bool FilaCircular<T>::Remover() {
	if(lista.RemoveNoFinal()){
		return true;
		cout << "tá no if";
	}
		
	else
		return false;
}

template <typename T>
bool FilaCircular<T>::vazia() {
	if(lista.vazia())
		return true;
	else
		return false;
}

template <typename T>
int FilaCircular<T>::size() {
	return lista.size();
}

template <typename T>
std::ostream& operator<< ( std::ostream& o, FilaCircular<T> const &l) {
	o << l;

	return o;
}

#endif