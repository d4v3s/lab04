#ifndef RPN_H
#define RPN_H
#include <string> 
/**
 * @file    rpn.h
 * @brief   Cabeçalho da classe rpn (Reverse Polish Notation)
*/

class Rpn {
private:
	std::string expressao;   //! string contendo a expressao 
public:

 	Rpn();
	~Rpn(); 


	void setExpressao(std::string expressao_);

	std::string getExpressao();

	int resolver(std::string str_);
};


#endif 