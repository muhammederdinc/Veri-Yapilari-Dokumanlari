#include "Huffman.hpp"

int main(){
	int secilen = 0;
	cout<<"1-Dosyayi Sıkıstır\n2-Sıkıstırılmıs Dosyayı Ekrana Yaz";
	
	
	
	Huffman *huffman = new Huffman("deneme.txt");
	huffman->Kodla();
	cout<<*huffman;
	delete huffman;
	return 0;
}
