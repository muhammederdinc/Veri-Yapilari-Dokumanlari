#include "CiftYonluBagilListe.hpp"

int main(){
	CiftYonluBagilListe<string> *isimler = new CiftYonluBagilListe<string>();
	int sec=0;
	string isim;
	do{
		system("CLS");
		cout<<"1.Isim Ekle"<<endl;
		cout<<"2.Isim Sil"<<endl;
		cout<<"3.Konumdan Isim Sil"<<endl;
		cout<<"4.Konuma Isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.Isim Sayisi"<<endl;
		cout<<"7.Ilk Isim"<<endl;
		cout<<"8.Son Isim"<<endl;
		cout<<"9.Isimleri Listele"<<endl;
		cout<<"10.Isimleri Temizle"<<endl;
		cout<<"Secim:";
		cin>>sec;
		system("CLS");
		switch(sec){
			case 1:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->Ekle(isim);
			break;
			case 2:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				try{
					isimler->Sil(isim);				
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 3:
				try{
					int konum;
					cout<<"Konum:";
					cin>>konum;
					isimler->KonumdakiniSil(konum);				
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.ignore();
					cin.get();
				}
			break;
			case 4:
				try{
					string isim;
					int konum;
					cout<<"Konum:";
					cin>>konum;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					isimler->Ekle(isim,konum);
				}
				catch(Tasma &tasma){
					cout<<endl<<tasma.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 5:
				try{
					string isim;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					cout<<"Konum:"<<isimler->KonumuBul(isim);
					cin.get();
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 6:			
				cout<<"Isim Sayisi:"<<isimler->Uzunluk()<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 7:
				try{
					cout<<"Ilk Isim:"<<isimler->IlkEleman()<<endl;
					cin.ignore();
					cin.get();
				}
				catch(ListeBos &listeBos){
					cout<<endl<<listeBos.Mesaj()<<endl;
					cin.get();
				}
			break;	
			case 8:
				try{
					cout<<"Son Isim:"<<isimler->SonEleman()<<endl;
					cin.ignore();
					cin.get();
				}
				catch(ListeBos &listeBos){
					cout<<endl<<listeBos.Mesaj()<<endl;
					cin.get();
				}
			break;	
			case 9:			
				cout<<"ISIMLER"<<endl;
				cout<<*isimler<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 10:
				isimler->Temizle();
				cout<<endl<<"Tum isimler silindi."<<endl;
				cin.ignore();
				cin.get();
			break;
			case 0:
			break;
			default:
				cout<<endl<<"Yanlis tercih!"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		system("CLS");
	}while(sec != 0);
	delete isimler;
}