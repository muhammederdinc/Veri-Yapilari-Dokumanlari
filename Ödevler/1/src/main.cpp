
#include <iostream>
#include <Windows.h>
#include "Sembol.hpp"
#include "Kart.hpp"
#include <time.h>
using namespace std;

void degistir(Kart **k,int a,int b)
{
        Kart *gcc;
        gcc=k[a];
        k[a]=k[b];
        k[b]=gcc;

}
char karakter[100]="!#$&%?*/-afdshğmxffgxnnzxlkjhds";
int adet;
Sembol* Semboldizi[100];
Kart* Kartdizi[100];
HANDLE hConsole= GetStdHandle(STD_OUTPUT_HANDLE);
void yaz()
{
    for(int i=0;i<adet;i++)
    {

       SetConsoleTextAttribute(hConsole,Kartdizi[i]->getSembol()->getrenk());
       cout<< Kartdizi[i]->getSembol()->getkarakter()<<"       ";

    }
    SetConsoleTextAttribute(hConsole, 7);
}
void ata()
{
    cout<<"Kart Adedi :";
    cin>>adet;
    for(int i=1;i<=adet;i++)
        cout<<i<<"       ";
    cout<<endl;
    int renk[adet];
    srand(time(NULL));
    for(int i=0;i<adet;i++)
    {
        renk[i]=rand()%15+1;
        Semboldizi[i]=new Sembol(&karakter[i],renk[i]);
        Kartdizi[i]=new Kart(&Semboldizi[i]);
    }

   yaz();
    cout<<endl;
}

void yerdegistir()
{
    cout<<"Yerlerin degis"<<endl;
    cout<<"Kacinci karti degistirmek istiyorsun :";
    int birinci;
    cin>>birinci;
    cout<<"Hangi kart ile degistirmek istiyorsun :";
    int ikinci;
    cin>>ikinci;
    birinci--;
    ikinci--;
     degistir(Kartdizi,birinci,ikinci);
    for(int i=1;i<=adet;i++)
        cout<<i<<"       ";
    cout<<endl;
    int k=1;
    yaz();
cout<<endl;
}
void terscevir()
{
    int i=1;
    cout<<endl;
    for(int a=0;a<=(adet/2)-1;a++)
    {
        degistir(Kartdizi,a,(adet-i));
        i++;
    }
    for(int i=1;i<=adet;i++)
        cout<<i<<"       ";
    cout<<endl;
     yaz();
    cout<<endl;
}
int  basla()
{
    ata();
    int islem;
    while(true)
    {
    cout<<"Islemler :"<<endl;
    cout<<"1. Kart Degistir"<<endl;
    cout<<"2. Ters Cevir"<<endl;
    cout<<"3. Cikis"<<endl;
    cout<<">>";
    cin>>islem;
    switch(islem)
    {
    case 1: yerdegistir();
    continue;
    case 2: terscevir();
    continue;
    case 3: return 0;
     }
    }


}
int main()
{
    basla();
    return 0;
}
