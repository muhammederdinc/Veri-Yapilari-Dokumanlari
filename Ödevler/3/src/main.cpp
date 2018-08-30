

#include <iostream>
#include <fstream>
#include <string>
#include "Queue.hpp"
#include "BinarySearchTree.hpp"
using namespace std;
int DosyaSatirSayisi()
{
        ifstream DosyaOku("dosya.txt",ios::app);
        int sayac=0;
		string sayi;
		
		while(!DosyaOku.eof())
        {
			DosyaOku>>sayi;
			if(sayi[0]-'0'<0||sayi[0]-'0'>9) 
			{
				continue;
			}
			sayac++;
        }
        return sayac;
}
void Basla()
{
		Queue *kuyruk[DosyaSatirSayisi()];
        ifstream DosyaO("dosya.txt",ios::app);
        string sayi;
		
        for(int i=0;i<DosyaSatirSayisi();i++)
        {
            kuyruk[i]=new Queue();
            DosyaO>>sayi;
			int j=0;
            while(sayi[j]!='\0')
            {
				if(sayi[j]-'0'<0||sayi[j]-'0'>9)
				{
					if(j==0) 
					{
						break;
					}
					j++;
					continue;
				}
				else
				{
					kuyruk[i]->enqueue((sayi[j]-'0'));
					j++;
				}
            }
        }
    BinarySearchTree *agac = new BinarySearchTree();
    for(int i=0;i<DosyaSatirSayisi();i++)
    agac->ekle(kuyruk[i]);

    cout<<"inorder :"<<endl;
    agac->Inorder();
    cout<<endl;
    cout<<"preorder:"<<endl;
    agac->Preorder();
    cout<<endl;
    cout<<"postorder"<<endl;
    agac->Postorder();
    cout<<endl;
	
}
int main()
{
    Basla();
    return 0;
}

