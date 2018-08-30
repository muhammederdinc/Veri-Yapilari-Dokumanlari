#include "Postfix.hpp"

int main()
{
   string infix;
   cout<<"Infix ifade:";
   cin>>infix;
   Postfix *p = new Postfix(infix);
   cout<<"Postfix: "<<*p<<endl;
   cout<<"Sonuc="<<p->Hesapla()<<endl;
   
   delete p;
   return 0;
}