#include "Huffman.hpp"

int main(){
	int secilen = 0;
	cout<<"1-Dosyayi S�k�st�r\n2-S�k�st�r�lm�s Dosyay� Ekrana Yaz";
	
	
	
	Huffman *huffman = new Huffman("deneme.txt");
	huffman->Kodla();
	cout<<*huffman;
	delete huffman;
	return 0;
}
