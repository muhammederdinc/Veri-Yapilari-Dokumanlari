

#include "islem.hpp"
#include "Heaptree.hpp"
islem::islem()
{
    ifstream Satrial("dosya.txt",ios::app);
    sayac=0;
    while(!Satrial.eof())
    {
        Satrial>>sayi;
        if(sayi[0]-'0'<0||sayi[0]-'0'>9)
        {
            continue;
		}
        sayac++;
    }
    ifstream DosyaOku("dosya.txt",ios::app);
    HeapTree *a= new HeapTree(sayac);
    while(!DosyaOku.eof())
    {
        DosyaOku>>sayi;
        if(sayi[0]-'0'<0||sayi[0]-'0'>9)
        {
            continue;
		}
        a->Ekle(sayi);
    }
    ofstream Dosyayaz("sirali.txt",ios::app);
    for(int i=0;i<sayac;i++)
    {
        if(i!=(sayac-1))
        {
            if(!a->Bosmu())
           Dosyayaz<<a->EnKucuguCikar()<<endl;
        }
        else
        {
            if(!a->Bosmu())
            {
                cout<<a->puss()<<endl;
                Dosyayaz<<a->EnKucuguCikar()<<endl;
            }

        }

    }
}

islem::~islem()
{

}
