#include "Urun.h"
#include <fstream>
#include <iostream>
using namespace std;

string urunListesi[] = { "Ekran_karti","Ses_Karti","Islemci","Klavye","Mouse","Monitor","32gb_Ram","Sabit_Disk","Hoparlor","SSD_Disk","Notebook","Flash_Bellek","Flash_Disk","Tablet","Cep_Telefonu","Kulaklik","Yazici","Scanner","Optik_Okuyucu","Tv_Karti" };

Urun::Urun()
{
	int urunIndex = rand() % 20;

	mUrunAdi = urunListesi[urunIndex];
	mUrunKodu = urunKoduUret();

	mFiyat = fiyatUret();
}

string Urun::urunAdiGetir()
{
	return mUrunAdi;
}

string Urun::urunKoduGetir()
{
	return mUrunKodu;
}

string Urun::fiyatGetir()
{
	return mFiyat;
}

void Urun::urunAdiAta(string urunAdi)
{
	mUrunAdi = urunAdi;
}

void Urun::urunKoduAta(string urunkodu)
{
	mUrunKodu = urunkodu;
}

void Urun::silinecekUrun()
{
	string silUrun = "";
	cout << "Urun Kodu Girin..:";
	cin >> silUrun;
	fstream urunSil, geciciUrun;
	string urunKodu, urunAdi, urunFiyat;
	geciciUrun.open("Geciciurun.txt", ios::out);
	urunSil.open("Urun.txt", ios::in);
	if (urunSil.is_open() == true)
	{
		while (urunSil >> urunKodu >> urunAdi >> urunFiyat)
		{
			if (urunKodu != silUrun)
				geciciUrun << urunKodu << " " << urunAdi << " " << urunFiyat << endl;
		}
	}
	urunSil.close();
	geciciUrun.close();
	remove("Urun.txt");
	rename("Geciciurun.txt", "Urun.txt");
}

string Urun::urunKoduUret()
{
	string urunKodu = "";

	for (int i = 0;i < 4;i++)
		urunKodu += '0' + rand() % 10;

	return urunKodu;
}

string Urun::fiyatUret()
{
	string urunFiyat = "";

	for (int i = 0;i < 3;i++)
		urunFiyat += '0' + rand() % 10;

	return urunFiyat;
}