#include "Huffman.hpp"

int main(){
	int secilen = 0;
	cout<<"1-Dosyayi Sýkýstýr\n2-Sýkýstýrýlmýs Dosyayý Ekrana Yaz";
	
	
	
	Huffman *huffman = new Huffman("deneme.txt");
	huffman->Kodla();
	cout<<*huffman;
	delete huffman;
	return 0;
}
