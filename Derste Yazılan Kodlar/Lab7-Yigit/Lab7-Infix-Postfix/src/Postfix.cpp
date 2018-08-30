#include "Postfix.hpp"
bool Postfix::OncelikDusukmu(char op1,char op2){
			if(op1 == '(') return false;
			else if(op2 == '(') return false;
			else if(op2 == ')')return true;
			else if(op1 == '*' || op1 == '/') return true;
			else if(op2 == '*' || op2 == '/') return false;
			else return true;
		}
		
		string Postfix::infixToPostfix(string infix){
			int uzunluk=infix.length();
			Stack<char> *stack = new Stack<char>();
			string postfix="";
			for(int i=0;i<uzunluk;i++){
				if(isdigit(infix[i])){
					while(isdigit(infix[i])){
						postfix += infix[i];
						i++;
					}
					postfix += " ";
					i--;
				}
				else if(infix[i] == '('){
					stack->push(infix[i]);
				}
				else if(infix[i] == '*' || infix[i] == '+' || infix[i] == '-' || infix[i] == '/'){
					while(!stack->isEmpty() && stack->top() != '('){					
						if(OncelikDusukmu(stack->top(),infix[i])){
							postfix += stack->top();
							postfix += " ";
							stack->pop();
						}
						else{
							break;
						}
					}
					stack->push(infix[i]);
				}
				else if(infix[i] == ')'){
					while(!stack->isEmpty() && stack->top() != '('){
						postfix += stack->top();
						postfix += " ";
						stack->pop();						
					}
					if(!stack->isEmpty()) stack->pop();
				}
			}
			while(!stack->isEmpty()){
				postfix += stack->top();
				postfix += " ";
				stack->pop();
			}
			delete stack;
			return postfix;
		}
Postfix::Postfix(string infix){
			ifade = infixToPostfix(infix);
		}
		double Postfix::Hesapla(){
			double sonuc;
			int uzunluk = ifade.length();
			Stack<double> *stack = new Stack<double>();
			for(int i=0;i<uzunluk;i++){
				if(isspace(ifade[i])) continue;
				if(isdigit(ifade[i])){
					string sayi="";
					while(isdigit(ifade[i])){
						sayi+=ifade[i];
						i++;
					}
					double s;
					s=atof(sayi.c_str());
					stack->push(s);
					i--;
					continue;
				}
				else{
					double sayi2 = stack->top();
					stack->pop();
					double sayi1 = stack->top();
					stack->pop();
					switch(ifade[i]){
						case '+':
							stack->push(sayi1+sayi2);
						break;
						case '-':
							stack->push(sayi1-sayi2);
						break;
						case '*':
							stack->push(sayi1*sayi2);
						break;
						case '/':
							stack->push(sayi1/sayi2);
						break;
					}
				}
			}
			if(!stack->isEmpty()){
				sonuc = stack->top();
				stack->pop();
			}
			delete stack;
			return sonuc;
		}
		string Postfix::postfix()const{
			return ifade;
		}
		ostream& operator<<(ostream& ekran,Postfix& sag){
			ekran<<sag.ifade<<endl;
			return ekran;
		}