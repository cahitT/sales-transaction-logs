#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Kontrol.h"
#include "Musteri.h"
#include "Urun.h"
#include"Islem.h" //Header dosyalari ve gerekli olan dosyalar include ediliyor.

using namespace std;

//Program ilk basladiginda hicbir musteri ve urun kayitli degildir.
//Programi kullanan kisinin yonetici panelinden musteri ve urun kaydi yapmasi gerekmektedir.

void hosgeldin(int gen,string yazi)
{
	for (int i = 0;i < gen;i++)
		cout << "*";
	cout << endl;
	cout << "*" <<"      "<<std::left <<setw(gen-8)<<yazi << "*" << endl;
	for (int i = 0;i < gen;i++)
		cout << "*";
	cout << endl;
}
int main()
{

	int secim = 0; //Secim degikeni belirlenip ilk deger olarak 0 atandi.


	hosgeldin(30,"HOSGELDINIZ!!!!!");



	while (secim < 3) //Secim degeri 3 veya 3'ten buyuk olana kadar dongu devam ediyor.
	{
		srand(time(0)); //Random sayilarin, degerlerin surekli degisik degerler almasýný sagliyor.

		Kontrol panel; //Kontrol sinifindan panel adli nesne olusturuluyor.
		Musteri member;  //Musteri adli sýnýftan member nesnesi olusturuluyor.
		Urun merchandise;  //Urun sinifindan merchandise adli nesne olusturuluyor.
		Islem islem; //Islem sinifindan islem adli bir nesne olusturuluyor.
		int secimYonetici; //int bir degisken tanimlaniyor.
		
		
		panel.anapanel();
		cout << "Secim..: "; //Secim yazisi ekrana cikartiliyor.
		cin >> secim; //Klavyeden bir deger girilmesi isteniyor.
		cout << endl;



		if (secim == 3) //Eger secim '3' olursa program ekrana belirtilen mesaji cikartip sonlaniyor.
		{
			cout << "Gorusmek Uzere!!" << endl;
			return 0;
		}
		else
		{
			switch (secim) //Secim 3 degilse switch case'in icine giriyor ve yapilan secime gore islem yapiliyor.
			{
			case 1: //eger secim 1 ise; 
				panel.musteriPanel();
				islem.kaydet();  //Musterinin islemleri kayit ediliyor.
				break;
			case 2:
				panel.yoneticiPanel();
				cout << "Secim..: "; //Yoneticinin bir secim yapmasi bekleniyor.
				cin >> secimYonetici;
				cout << endl;
				switch (secimYonetici)
				{
				case 1: //Eger yonetici secimi 1 ise;
					panel.musteriKayitPanel();
					break;
				case 2://eger yonetici secimi 2 ise;
					panel.musteriPanel();
					break;
				case 3: //Eger secim 3 ise;
					panel.musteriPanel();
					panel.tcgirilen(); //Girilen TC'ye gore kisi siliniyor.
					panel.deleteMember();
					panel.deleteOp(); //Silinen kisinin yaptigi butun islemler siliniyor.
					break;
				case 4: //Eger secim 4 ise;
					panel.urunKayitPanel();
					break;
				case 5: //Eger secim 5 ise;
					panel.urunPanel();
					break;
				case 6: //Eger secim 6 ise;
					panel.urunPanel();
					merchandise.silinecekUrun();
					break;
				default://Eger secim 6'dan buyuk ise default deger donduruluyor.
					cout << "Yanlis bir tercih yaptiniz :(" << endl; 
					break;
				}
				break;
			default: //Eger secim 3'ten buyuk ise default deger donduruluyor.
				cout << "Yanlis Bir Tercih Yaptiniz Lutfen Tekrar Deneyiniz!!" << endl;
				break;
			}
		}
		system("pause"); //Klavyeden bir degere basilana kadar program duruyor.
	}
	return 0; //Programimizin basari ile sonlandigini belirityor.
}