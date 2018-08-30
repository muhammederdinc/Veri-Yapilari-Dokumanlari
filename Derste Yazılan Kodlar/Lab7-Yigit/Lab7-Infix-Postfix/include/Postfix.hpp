#ifndef POSTFIX_HPP
#define POSTFIX_HPP

#include "Stack.hpp"
#include <cctype>
#include <cstdlib>

class Postfix{
	private:
		string ifade; //postfix ifade
		
		bool OncelikDusukmu(char,char);
		
		string infixToPostfix(string);
	public:
		Postfix(string);
		double Hesapla();
		string postfix()const;
		friend ostream& operator<<(ostream&,Postfix&);
};


#endif