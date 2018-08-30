// Þablon baðýl liste
#ifndef BAGILLISTE_HPP
#define BAGILLISTE_HPP

#include "ListeGezici.hpp"

template <typename Nesne>
class CiftYonluBagilListe{
	private:
		Dugum<Nesne> *basDugum; // içinde eleman olmayan sadece listenin baþýný tutan düðüm.
		int elemanSayisi;
		
		ListeGezici<Nesne> OncekiniKonumuIleBul(int konum) const throw(Tasma){
			if(konum<0 || konum > Uzunluk()) throw Tasma();
			int indeks=0;
			Dugum<Nesne> *gezici = basDugum;
			while(gezici->ileri != NULL && konum != indeks++) gezici = gezici->ileri;
			return ListeGezici<Nesne>(gezici);
		}
	public:
		CiftYonluBagilListe(){
			basDugum = new Dugum<Nesne>(); // Boþ bir düðüm oluþturuluyor	
			elemanSayisi=0;			
		}
		bool Bosmu() const{
			return basDugum->ileri == NULL;
		}
		int Uzunluk() const{
			return elemanSayisi;
		}		
		/// Listenin ilk düðümünü döndürür
		ListeGezici<Nesne> Ilk() const throw(ListeBos){
			if(Bosmu()) throw ListeBos();
			return ListeGezici<Nesne>(basDugum->ileri);
		}
		/// Listenin ilk elemanýný döndürür
		const Nesne& IlkEleman() const throw(ListeBos){
			if(Bosmu()) throw ListeBos();
			return basDugum->ileri->eleman;
		}
		/// Listenin son elemanýný döndürür
		const Nesne& SonEleman() const throw(ListeBos){
			if(Bosmu()) throw ListeBos();
			ListeGezici<Nesne> gezici = OncekiniKonumuIleBul(elemanSayisi-1);
			
			return gezici.simdiki->ileri->eleman;
		}
		/// Listenin sonuna verilen elemaný ekler
		void Ekle(const Nesne& yeni){
			Ekle(yeni,Uzunluk());
		}
		/// Listenin istenen konumuna verilen elemaný ekler
		void Ekle(const Nesne& yeni,int konum) throw(Tasma){
			ListeGezici<Nesne> gezici;
			try{
				gezici = OncekiniKonumuIleBul(konum);
			}
			catch(Tasma ts){
				throw ts;
			}
			
			Dugum<Nesne> *geciciGeri = gezici.simdiki->ileri;
			gezici.simdiki->ileri = new Dugum<Nesne>(yeni,gezici.simdiki->ileri,gezici.simdiki);
			if(geciciGeri != NULL) geciciGeri->geri = gezici.simdiki->ileri;
			elemanSayisi++;
		}
		/// Verilen elemaný listede bulur ve siler.
		void Sil(const Nesne& aranan) throw(ElemanYok){			
			try{
				int konum = KonumuBul(aranan);
				KonumdakiniSil(konum);
			}
			catch(ElemanYok ey){
				throw ey;
			}
		}
		void KonumdakiniSil(int konum) throw(Tasma){
			try{
				ListeGezici<Nesne> gezici = OncekiniKonumuIleBul(konum);
				Dugum<Nesne> *sil = gezici.simdiki->ileri;
				gezici.simdiki->ileri = gezici.simdiki->ileri->ileri;
				if(gezici.simdiki->ileri != NULL) gezici.simdiki->ileri->geri = gezici.simdiki;
				delete sil;
				elemanSayisi--;
			}
			catch(Tasma ts){
				throw ts;
			}
		}
		bool ElemanBul(const Nesne& aranan) const{
			if(Bosmu()) return false;
			for(ListeGezici<Nesne> gezici(basDugum->ileri);!gezici.SonaGeldimi();gezici.ilerle()){
				if(gezici.Getir() == aranan) return true;
			}
			return false;
		}
		int KonumuBul(const Nesne& aranan) const throw(ElemanYok){
			if(Bosmu()) throw ElemanYok();
			int indeks=0;
			for(ListeGezici<Nesne> gezici(basDugum->ileri);!gezici.SonaGeldimi();gezici.ilerle()){
				if(gezici.Getir() == aranan) return indeks;
				indeks++;
			}
			throw ElemanYok();
		}
		/// Listedeki elemanlarý temizler
		void Temizle(){
			while(!Bosmu())
				Sil(Ilk().Getir());
		}
		~CiftYonluBagilListe(){
			Temizle();
			delete basDugum;
		}
		friend ostream& operator<<(ostream& ekran, CiftYonluBagilListe &sag){
			if(sag.Bosmu()) ekran<<"Liste bos";
			ListeGezici<Nesne> gezici = sag.Ilk();
			for(;!gezici.SonaGeldimi();gezici.ilerle())
				ekran<<gezici.Getir()<<" ";
			ekran<<endl;
			return ekran;
		}
};
#endif