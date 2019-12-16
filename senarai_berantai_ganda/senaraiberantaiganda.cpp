#include <iostream>
#include <conio.h>

using namespace std;
class Simpul{
	
	public:
		double dData;
		Simpul*pb;//simpul beriktnya pada senarai
		Simpul*ps;//simpul stelahnya pada senarai
		
	public:
		Simpul(double dd)://konstruktor
		dData(dd),pb(NULL),ps(NULL){
		}
		
		void tampilSenarai(){
			cout<<dData<<" ";
		}
};
class SenaraiBerantaiGanda{
	
	private:
		Simpul*pPertama;//pointer ke item pertama
		Simpul*pAkhir;//pointer ke item akhir
		
	public:
		SenaraiBerantaiGanda()://konstruktor
		pPertama(NULL),pAkhir(NULL){
		}
		~SenaraiBerantaiGanda(){//destruktor
		Simpul*psk = pPertama;
		while(psk!=NULL){
			Simpul*plm = psk;
			psk = psk->pb;
			delete plm;
		}
		}
		
		bool apaKosong(){
			return pPertama==NULL;
		}
		//menyisipkan di awal senarai
		void sisipPertama(double dd ){
			Simpul*pSimpulBaru = new Simpul(dd);
			
			if(apaKosong())
			pAkhir = pSimpulBaru;
			else
			pPertama->ps=pSimpulBaru;
			pSimpulBaru->pb=pPertama;
			pPertama = pSimpulBaru;
		}
		
		void sisipAkhir(double dd){
			Simpul*pSimpulBaru = new Simpul(dd);
			if(apaKosong())
			pPertama=pSimpulBaru;
			else{
				pAkhir-> pb = pSimpulBaru;
				pSimpulBaru->ps = pAkhir;
			}
			pAkhir = pSimpulBaru;
		}
		
		void hapusPertama(){
			Simpul*pTemp = pPertama;
			
			if(pPertama->pb==NULL)
			pAkhir=NULL;
			else
			pPertama->pb->ps=NULL;
			pPertama = pPertama->pb;
			delete pTemp;
		}
		void hapusAkhir(){
			Simpul*pTemp = pAkhir;
			
			if(pPertama->pb==NULL)
			pPertama=NULL;
			else
			pAkhir->ps->pb =NULL;
			pAkhir = pAkhir->ps;
			delete pTemp;
		}
		
		//menyispkan tepat setelah kunci
		bool sisipSetelah(double kunci, double dd){
			Simpul*psk = pPertama;
			while(psk-> dData!=kunci){
				psk = psk->pb;
				if(psk==NULL)
				return false;
			}
			
			Simpul*pSimpulBaru = new Simpul(dd);
			
			if(psk==pAkhir){
				pSimpulBaru-> pb=NULL;
				pAkhir = pSimpulBaru;
			}
			else{
				pSimpulBaru->pb = psk->pb;
				psk-> pb -> ps = pSimpulBaru;
				
			}
			pSimpulBaru->ps = psk;
				psk->pb =pSimpulBaru;
				return true; 
			}
			
			bool hapusKunci(double kunci){
				Simpul*psk = pPertama;
				while(psk-> dData!=kunci){
					psk = psk->pb;
					if(psk==NULL)
					return false;
				}
				
				if(psk==pPertama)
				pPertama = psk->pb;
				else
				psk->ps->pb = psk->pb;
				
				if(psk == pAkhir)
				pAkhir = psk-> ps;
				else
				psk->pb->ps = psk->ps;
				delete psk;
				
				return true;
			}
			void tampilMaju(){
				
				cout<<"Senarai(pertama-->akhir):";
				Simpul*psk = pPertama;
				while (psk!=NULL){
					psk->tampilSenarai();
					psk=psk->pb;
				}
				cout<<endl;
			}
			void tampilMundur(){
				
				cout<<"Senarai(Akhir-->pertama):";
					Simpul*psk = pAkhir;
				while (psk!=NULL){
					psk->tampilSenarai();
					psk=psk->ps;
				}
				cout<<endl;
			}
};

int main(){
	SenaraiBerantaiGanda senarai;
	
	senarai.sisipPertama(22); 
	senarai.sisipPertama(44); 
	senarai.sisipPertama(66);
	
	senarai.sisipAkhir(11);  
	senarai.sisipAkhir(33);
	senarai.sisipAkhir(55);
	
	senarai.tampilMaju();
	senarai.tampilMundur();
	
	cout<<" Menghapus simpul pertama, simpul akhir, dan 11"<<endl;
	
	senarai.hapusPertama();
	senarai.hapusAkhir();
	senarai.hapusKunci(11);
	
	senarai.tampilMaju();
	
	cout<<" Menyisipkan 77 setelah simpul 22, dan 88 setelah 33"<<endl;
	
	senarai.sisipSetelah(22,77);
	senarai.sisipSetelah(33,88);
	senarai.tampilMaju();
	
	getch();
	return 0;
}
 

