#ifndef PALINDROMA_H
#define PALINDROMA_H
/**
 * @file    palindroma.h
 * @brief   Cabeçalho da classe palindroma
*/
#include <iostream>

class Palindroma {
private:
	std::string str;   //! string contendo frase ou palavra
public:

 	Palindroma ();
	~Palindroma (); 


	void setStr(std::string str_);

	std::string getStr();

	bool verificarPalindroma(std::string str_);
};


#endif 