
#include "HeapTree.hpp"

int HeapTree::SolCocukIndeks(int dugumIndeks){
	return 2*dugumIndeks + 1;
}
int HeapTree::SagCocukIndeks(int dugumIndeks){
	return 2*dugumIndeks + 2;
}
int HeapTree::EbeveynDugumIndeks(int dugumIndeks){
	return (dugumIndeks-1)/2;
}
HeapTree::HeapTree(int kapasite){
	elemanlar = new string[kapasite];
	dugumSayisi = 0;
	this->kapasite = kapasite;
}
bool HeapTree::Bosmu(){
	return (dugumSayisi == 0);
}
string HeapTree::puss()
{
    return elemanlar[0];
}
void HeapTree::HeapYukari(int dugumIndeks){
    Sayi *s1= new Sayi;
	int ebeveynIndeks;
	string tmpVeri;

	if(dugumIndeks != 0){
		ebeveynIndeks = EbeveynDugumIndeks(dugumIndeks);
		buyuk=s1->Karsilastir(elemanlar[ebeveynIndeks],elemanlar[dugumIndeks]);
		if(buyuk==elemanlar[ebeveynIndeks]){
			tmpVeri = elemanlar[ebeveynIndeks];
			elemanlar[ebeveynIndeks] = elemanlar[dugumIndeks];
			elemanlar[dugumIndeks] = tmpVeri;
			HeapYukari(ebeveynIndeks);
		}
	}
}

void HeapTree::HeapAsagi(int dugumIndeks){
	int solCocukIndeks,sagCocukIndeks, enKucukIndeks;
	string tmpVeri;
    Sayi *s1;
	solCocukIndeks = SolCocukIndeks(dugumIndeks);
	sagCocukIndeks = SagCocukIndeks(dugumIndeks);

	if(sagCocukIndeks >= dugumSayisi){
		if(solCocukIndeks >= dugumSayisi) return;
		else
			enKucukIndeks = solCocukIndeks;
	}
	else{
        buyuk=s1->Karsilastir(elemanlar[solCocukIndeks],elemanlar[sagCocukIndeks]);
        if(buyuk != elemanlar[solCocukIndeks])
			enKucukIndeks = solCocukIndeks;
		else
			enKucukIndeks = sagCocukIndeks;
	}
	buyuk=s1->Karsilastir(elemanlar[dugumIndeks],elemanlar[enKucukIndeks]);
	if(elemanlar[dugumIndeks]==buyuk){
		tmpVeri = elemanlar[enKucukIndeks];
		elemanlar[enKucukIndeks] = elemanlar[dugumIndeks];
		elemanlar[dugumIndeks] = tmpVeri;
		HeapAsagi(enKucukIndeks);
	}
}

void HeapTree::Ekle(string sayi)throw(string){
	if(dugumSayisi == kapasite) throw string("Dizi tasma hatasi");
	elemanlar[dugumSayisi] = sayi;
	dugumSayisi++;
	HeapYukari(dugumSayisi-1);
}

string HeapTree::EnKucuguCikar()throw(string){
	if(Bosmu()) throw string("Heap bos");
	string enKucuk = elemanlar[0];
	elemanlar[0] = elemanlar[dugumSayisi - 1];
	dugumSayisi--;
	if(dugumSayisi > 0) HeapAsagi(0);
    return enKucuk;
}

HeapTree::~HeapTree(){
	delete[] elemanlar;
}
