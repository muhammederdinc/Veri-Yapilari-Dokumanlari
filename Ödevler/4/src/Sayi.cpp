

#include "Sayi.hpp"

string Sayi::Karsilastir(string a,string b)
{
    if(lenght(a)>lenght(b))
        return a;
    else if(lenght(a)<lenght(b))
        return b;
    else
    {
        for(int i=0;i<lenght(a);i++)
        {
            if((a[i])>(b[i]))
                return a;
            else if((a[i])<(b[i]))
                return b;
            else
                if(i==lenght(a)-1)
                return a;
        }
    }

}
int Sayi::lenght(string a)
{
   int i=0;
   while(a[i])
   {
      i++;
   }
   return i;
}
Sayi::~Sayi()
{

}
