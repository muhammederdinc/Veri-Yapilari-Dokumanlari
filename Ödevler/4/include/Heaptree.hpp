#ifndef HEAPTREE_HPP
#define HEAPTREE_HPP

#include <iostream>
#include <string>
#include "Sayi.hpp"
using namespace std;

// Küçükten büyüge sıralayan (Min Heap Tree)
class HeapTree{
	private:
		string *elemanlar;
		string buyuk;
		int dugumSayisi;
		int kapasite;
        int SolCocukIndeks(int);
		int SagCocukIndeks(int);
		int EbeveynDugumIndeks(int);
		void HeapYukari(int);
		void HeapAsagi(int);
	public:
		HeapTree(int);
		bool Bosmu();
		string puss();
		void Ekle(string)throw(string);
		string EnKucuguCikar()throw(string);
		~HeapTree();
};

#endif
