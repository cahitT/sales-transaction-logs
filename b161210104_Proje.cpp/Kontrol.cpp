#include "Kontrol.h"
#include <iostream>
#include<iomanip>
#include<Windows.h>
#include"Musteri.h"
#include <fstream>
#include "Urun.h" //Header dosyalari ve gerekli dosyalar include edildi.

using namespace std;


enum RENKLER //Renkler gosterildi.
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHTGRAY = 7,
	DARKGRAY = 8,
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};
void renkAta(int yazirenk) //Rengin degismesini saglayan fonksiyon.
{
	int arkaplan = 0;

	int sonRenk;

	sonRenk = (16 * arkaplan) + yazirenk;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sonRenk);
}
void karakterCikar(RENKLER renk) //Rengi tekrar beyaza donduren fonksiyon.
{
	renkAta(renk);
	renkAta(WHITE);
}


void Kontrol::anapanel()
{
	tavanCiz(30);
	araCiz(30,"ANA MENU");
	zeminCiz(30);
	anaMenuCiz(30);
}

void Kontrol::musteriPanel()
{
	tavanCiz(31); //Musteri listesinin paneli ciziliyor.
	araCiz(31, "MUSTERI LISTESI");
	zeminCiz(31);
	memberList(31);//Musteri listesi ekrana cikariliyor.
}

void Kontrol::yoneticiPanel()
{
	tavanCiz(30); //eger secim 2 ise;
	araCiz(30, "YONETICI KONTROL PANELI"); //Yonetici paneli ciziliyor.
	zeminCiz(30);
	yoneticiMenuCiz(30); //Yonetici menusu ekrana cikartiliyor.
}

void Kontrol::musteriKayitPanel()
{
	tavanCiz(30);
	araCiz(30, "KAYIT EDILEN MUSTERI;");
	zeminCiz(30);
	musteriKayit(30); //Kayit edilen musteri ekrana cikartiliyor.
}

void Kontrol::urunKayitPanel()
{
	tavanCiz(30);
	araCiz(30, "KAYIT EDILEN URUN;");
	zeminCiz(30);
	urunKayit(30); //Kayit edilen urun ekrana cikartiliyor.
}

void Kontrol::urunPanel()
{
	tavanCiz(31);
	araCiz(31, "URUN LISTESI");
	zeminCiz(31);
	merchandiseList(31); //Var olan urunlerin listesi ekrana cikartiliyor.
}


void Kontrol::tavanCiz(int genislik)
{
	renkAta(2); //Rengin yesil olmasini sagliyor.
	 
	cout << SOLUSTKOSE;

	for (int i = 0; i < genislik; i++) //Verilen genislik degeri kadar duz cizgi koyuyor.
		cout << DUZCIZGI;

	cout << SAGUSTKOSE;

	cout << endl;

}

void Kontrol::zeminCiz(int genislik) //Girilen genislik degeri sayesinde zemin ciziyor.
{
	cout << YATAYSAGAAYRAC;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << YATAYSOLAAYRAC;

	cout << endl;
}
void Kontrol::araCiz(int genislik, string yazi) //Girilen genislik degeri ve girilen yazi ile ara kisim cizdiriliyor.
{
	cout << DIKEYCIZGI;

	karakterCikar(WHITE); //Rengin tekrar beyaz olmasini sagliyor.

	cout << std::left << setw(genislik) << yazi; //Genislik kadar bosluk birakip sola dayali bir sekilde yaziyi yaziyor.
	renkAta(2); //Renk -> Yesil.
	cout << DIKEYCIZGI;

	cout << endl;
}

void Kontrol::ayracCiz(int genislik)
{
	cout << YATAYSAGAAYRAC;

	for (int i = 0; i < genislik; i++) //Genislik degerince duz cizgi koyuyor.
		cout << DUZCIZGI;

	cout << YATAYSOLAAYRAC;

	cout << endl;
}

void Kontrol::anaMenuCiz(int genislik) //Genislik degeri sayesinde ana menuyu ciziyor ve secenkleri ekrana cikartiyor.
{
	cout << DIKEYCIZGI;

	karakterCikar(WHITE); //renk -> Beyaz

	cout << std::left << setw(genislik) << "1.Musteri Paneli";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "2.Yonetici Paneli";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "3.Cikis";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;

	karakterCikar(WHITE);
}
 
void Kontrol::musteriMenuCiz(int genislik) //Verilen genislik degeri sayesinde musteri panelini ciziyor.
{
	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "1.Urun Al"; //Secenekler ekrana cikartiliyor.
	renkAta(2); //Renk -> Yesil
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "2.Islemleri Listele";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE); //Renk -> Beyaz

	cout << std::left << setw(genislik) << "3.Islem Sil";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "4.Geri";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;
	karakterCikar(WHITE); //Son olarak renk tekrar beyaza donduruluyor.

}

void Kontrol::yoneticiMenuCiz(int genislik) //Genislik degeri buyuklugunde yonetici panelini ciziyor.
{
	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "1.Musteri Ekle";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "2.Musteri Listele"; //Secenekler ekrana cikartiliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "3.Musteri Sil";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "4.Urun Ekle";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "5.Urunleri Listele";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << DIKEYCIZGI;

	karakterCikar(WHITE);

	cout << std::left << setw(genislik) << "6.Urun Sil";
	renkAta(2);
	cout << DIKEYCIZGI << endl;

	cout << SOLALTKOSE;

	for (int i = 0; i < genislik; i++)
		cout << DUZCIZGI;

	cout << SAGALTKOSE;

	cout << endl;
	karakterCikar(WHITE);

}

void Kontrol::memberList(int genislik) //Musteri listesi ekrana cikiyor.
{
	fstream listele;
	string isim, soyisim, tc, tel; //Dosyadan okunacak degerlerin degiskenleri belirtiliyor.
	listele.open("Musteriler.txt", ios::in);
	if (listele.is_open() == true) //Eger dosya acildi ise islemler yapilmaya baslaniyor.
	{
		while (listele >> tc >> tel >> isim >> soyisim) //listele'den degerler okunuyor.
		{
			renkAta(2); //Renk -> Yesil
			cout << DIKEYCIZGI;
			karakterCikar(WHITE); //Renk -> Beyaz
			cout << isim << " " << soyisim << " " << tc << " " << tel; //Okunan degerler sirasi ile ekrana cikartiliyor.
			renkAta(2);
			cout << "\t" << DIKEYCIZGI << endl;
			cout << YATAYSAGAAYRAC;
			for (int i = 0;i < genislik;i++)
				cout << DUZCIZGI;
			cout << YATAYSOLAAYRAC << endl;
		}

	}
	listele.close();
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << setw(genislik) << "LISTE SONU"; //Liste sonu belirtiliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl;
	cout << SOLALTKOSE;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << SAGALTKOSE << endl;
	karakterCikar(WHITE);
}
void Kontrol::tcgirilen() //Girilen TC degeri tcnogir degiskenine aktariliyor.
{
	cout << "Tc Girin:";

	cin >> number_Tc;
}

string Kontrol::tcDondur() //Girilen tc no degeri cagiriliyor.
{
	return number_Tc;
}

void Kontrol::merchandiseList(int genislik) //Urun listesi ekrana cikartiliyor.
{
	fstream urunListe;
	string urunKodu, urunAdi; //Dosyadan okunacak degerlerin degiskenleri belirtiliyor. 
	int fiyat;
	urunListe.open("Urun.txt", ios::in);
	if (urunListe.is_open() == true) //urunListele dosyasi acilip acilmadigi kontrol ediliyor.
	{
		while (urunListe >> urunKodu >> urunAdi >> fiyat)
		{
			renkAta(2);
			cout << DIKEYCIZGI;
			karakterCikar(WHITE);
			cout << urunKodu << " " << urunAdi << " " << fiyat; //okunan degerler sirasi ile ekrana cikartiliyor.
			renkAta(2);
			cout << "\t\t" << DIKEYCIZGI << endl;
			cout << YATAYSAGAAYRAC;
			for (int i = 0;i < genislik;i++)
				cout << DUZCIZGI;
			cout << YATAYSOLAAYRAC << endl;
		}

	}
	urunListe.close(); //Acilan dosyalar  kapatiliyor.
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << setw(genislik) << "LISTE SONU";
	renkAta(2);
	cout << DIKEYCIZGI << endl;
	cout << SOLALTKOSE;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << SAGALTKOSE << endl;
	karakterCikar(WHITE); //Renk son olarak beyaza donduruluyor.
}

void Kontrol::deleteOp() //musterilerin yaptigi islemler siliniyor.
{
	fstream islemtxtsil, islemtemp;
	string silIslem, islemsilKod, islemsilTcno, islemTc = ""; //Dosyadan okunacak degerlerin degiskenleri belitiliyor.
	islemTc = tcDondur();
	islemtxtsil.open("Islem.txt", ios::in); //Okuma modunda Islem.txt dosyasi aciliyor.
	islemtemp.open("Temp.txt", ios::out); //Temp.txt adinda gecici bir dosya aciliyorve silinecek deger haric digerleri bu dosyaya kayit ediliyor.
	if (islemtxtsil.is_open() == true && islemtemp.is_open() == true)
	{
		while (islemtxtsil >> silIslem >> islemsilKod >> islemsilTcno)
		{
			if (islemTc != islemsilTcno) //Girilen TC no'su dosyadaki TC no'suna esit olmadigi surece gecici dosyaya okunan degerler aktariliyor.
			{
				islemtemp << silIslem << " " << islemsilKod << " " << islemsilTcno << endl;
			}
		}
	}
	islemtxtsil.close(); //Acilan dosyalar kapatiliyor.
	islemtemp.close();
	remove("Islem.txt"); //Islem.txt dosyasi siliniyor.
	rename("Temp.txt", "Islem.txt"); //Silinecek olan deger bu gecici dosyaya alinmadigi icin bu dosyanin adini degistirip asil dosyamiz yapiyoruz. Boylece istedigimiz deger silinmis oluyor.
}
void Kontrol::deleteMember() //TC'si girilen musterilerin silinmesini saglayan fonksiyon.
{
	string deleteTc = ""; //Silinmek istenen TC degeri Bu degiskene aktariliyor.
	deleteTc = tcDondur();
	fstream musteri, geciciMusteri;
	string isim, soyisim, tc, tel; //Dosyadan okunacak degerler icin degiskenler tanimlaniyor.
	geciciMusteri.open("Musteritemp.txt", ios::out); //Gecici Musteri dosyasi aciliyor. 
	musteri.open("Musteriler.txt", ios::in); //Sadece okuma modunda Musteri dosyasi aciliyor.
	if (musteri.is_open() == true)
	{
		while (musteri >> isim >> soyisim >> tc >> tel)
		{
			if (tc != deleteTc) //Silinmesini istedigimiz TC dosyadaki TC'ye esit olmadigi surece degerleri gecici musteri dosyasina aktariyor.
				geciciMusteri << isim << " " << soyisim << " " << tc << " " << tel << endl;
		}
	}
	musteri.close(); //Acilan dosyalar kapatiliyor.
	geciciMusteri.close();
	remove("Musteriler.txt"); //Eski Musteriler.txt dosyasi siliniyor.
	rename("MusteriTemp.txt", "Musteriler.txt");  //Silinmesini istedigimiz musteri bu dosyaya yazilmadigi icin bu dosyanin adini degistiriyoruz ve artik yeni Musteriler.txt dosyamiz bu dosya oluyor.
}


void Kontrol::urunKayit(int genislik) //Urunler rastgele ekleniyor.
{
	Urun urunKaydet;
	fstream urunKayit;
	urunKayit.open("Urun.txt", ios::in | ios::out | ios::app); //Yeni kayit edilecek urun app komutu sayesinde bu dosyanin devamina yazdiriliyor.
	if (urunKayit.is_open() == true) //urunKayit dosyasinin acilip acilmadigi kontrol ediliyor.
	{
		urunKayit << urunKaydet.urunKoduGetir() << " " << urunKaydet.urunAdiGetir() << " " << urunKaydet.fiyatGetir() << endl;//Eger acildi ise urunKayit dosyasina urun Adi, Fiyati ve odu ile beraber kayit ediliyor.
	}
	renkAta(2); //Renk -> Yesil
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "Urun adi: " << setw(genislik - 10) << urunKaydet.urunAdiGetir(); //urunun adi cagiriliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << YATAYSAGAAYRAC;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << YATAYSOLAAYRAC << endl;
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "Urun Kodu: " << setw(genislik - 11) << urunKaydet.urunKoduGetir(); //Urunun kodu cagiriliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << YATAYSAGAAYRAC;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << YATAYSOLAAYRAC << endl;
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "Urun Fiyati: " << setw(genislik - 13) << urunKaydet.fiyatGetir(); //Urunun fiyati cagiriliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << SOLALTKOSE;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << SAGALTKOSE << endl;
	karakterCikar(WHITE);


}

void Kontrol::musteriKayit(int genislik) //Yoneticinin verdigi komuta gore yeni musteri kayiti yapiliyor.
{
	Musteri musteriKayit;
	fstream kayit;
	kayit.open("Musteriler.txt", std::fstream::in | std::fstream::out | std::fstream::app); //Yeni musteriler bu dosyaya kayit ediliyor.
	if (kayit.is_open() == true) //Kayit dosyasinin acilip acilmadigi kontrol ediliyor.
	{
		kayit << musteriKayit.isimGetir() << " " << musteriKayit.soyisimGetir() << " " << musteriKayit.tcnoGetir() << " " << musteriKayit.telnoGetir() << " " << endl;
	}
	kayit.close(); //kayit dosyasi kapatiliyor.
	renkAta(2);
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "Ad....: " << setw(genislik - 8) << musteriKayit.isimGetir(); //musterinin ismi cagiriliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << YATAYSAGAAYRAC;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << YATAYSOLAAYRAC << endl;
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "Soyad.: " << setw(genislik - 8) << musteriKayit.soyisimGetir(); //musterinin soyismi cagiriliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << YATAYSAGAAYRAC;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << YATAYSOLAAYRAC << endl;
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "TC....: " << setw(genislik - 8) << musteriKayit.tcnoGetir(); //Musterinin TC'si Getirtiliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << YATAYSAGAAYRAC;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << YATAYSOLAAYRAC << endl;
	cout << DIKEYCIZGI;
	karakterCikar(WHITE);
	cout << "Tel...: " << setw(genislik - 8) << musteriKayit.telnoGetir(); //Musterinin telefon numarasi cagiriliyor.
	renkAta(2);
	cout << DIKEYCIZGI << endl << SOLALTKOSE;
	for (int i = 0;i < genislik;i++)
		cout << DUZCIZGI;
	cout << SAGALTKOSE << endl;
	karakterCikar(WHITE); //Renk son olarak beyaza donduruluyor.
}