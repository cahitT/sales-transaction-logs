#include "Musteri.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Kontrol.h"

string isimlerListesi[] = { "Ahmet","Osman","Ali","Mehmet","Veli","Sarp","Emrah","Eser","Erbil","Oguz","Can","Murat","Sinan","Mert","Mete","Sait","Ervah","Cihat","Orhan","Fatih","Binnur","Bilge","Candan","Cahide","Bengisu","Demet","Deste","Gizem","Ece","Elanur","Fatma","Fidan","Gamze","Hale","Hilal","Irmak","Jale","Kader","Kamile","Lale" };
string soyisimlerListesi[] = { "KANDEMIR","ORHON","VURAL","YAVUZ","UZ","ERDEM","DEDE","UYANIK","ASLAN","ERKURAN","BOSTANCI","DAL","KARAKUM","YILMAZ","TAHTACI","KAYA","ERGE","ONUK","TOPAL","BEDER" };


Musteri::Musteri() 
{
	int isimIndex = rand() % 40; //0 ile 40 arasinda random bir deger uretiliyor.
	int soyisimIndex = rand() % 20; //0 ile 20 arasinda random bir deger uretiliyor.

	mIsim = isimlerListesi[isimIndex]; //Bu uretilen random deger isimlerListesi adli diziden uretilen degere gore bir isim belirleniyor ve mIsim degiskenine aktariliyor.
	mSoyisim = soyisimlerListesi[soyisimIndex]; //Uretilen rastgele deger soyisimlerListesi adli diziden donen rastgele sayiya gore birsoyad belirleyip mSoyisim degiskenine atiyor.

	mTcno = tcnouret(); //mTcno degerine tcnouret fonksiyonundan dondurulen deger aktariliyor.
	mTelno = telnoUret(); //mTelno degerine telnouret fonksiyonundan dondurulen deger aktariliyor.
}

string Musteri::tcnoGetir() //mTcno'yu cagiriyor.
{
	return mTcno;
}

string Musteri::telnoGetir() //mTelno degerini donduruyor.
{
	return mTelno;
}

string Musteri::isimGetir() //Private alanda tanimlanan mIsim degerini cagiriyor.
{
	return mIsim;
}

string Musteri::soyisimGetir() //Soyisim degerini donduruyor.
{
	return mSoyisim;
}

void Musteri::isimAta(string isim) //Verilen degere gore mIsim degiskenine aktariyor.
{
	mIsim = isim;
}

void Musteri::telnoAta(string telno) //Verilen degeri mTelno degiskenine aktariyor.
{
	mTelno = telno;
}

void Musteri::tcnoAta(string tcno) //Gelen tcno degerini mTcno degerine aktariyor.
{
	mTcno = tcno;
}

void Musteri::soyisimAta(string soyisim) //Gelen soyisim degerini mSoyisim degerine aktariyor.
{
	mSoyisim = soyisim;
}

string Musteri::tcnouret() //4 haneli bir tc numarasi uretiyor.
{
	string tcno = "";

	for (int i = 0; i < 4; i++)
	{
		tcno += '1' + rand() % 9;
	}
	return tcno;
}

string Musteri::telnoUret() //10 haneli bir tel no uretiliyor.
{
	string telno = "";
	for (int i = 0; i < 10; i++)
	{
		telno += '0' + rand() % 10;
	}
	return telno;
}