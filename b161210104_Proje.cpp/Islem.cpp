#include "Islem.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Kontrol.h"

Islem::Islem()
{
	mIslemKodu = islemKoduUret();
}

string Islem::urunKoduGetir()
{
	return mUrunKodu;
}

string Islem::tcNoGetir()
{
	return mMusteriTcNo;
}

string Islem::islemKoduGetir()
{
	return mIslemKodu;
}

void Islem::urunKoduAta(string kod)
{
	mIslemKodu = kod;
}

void Islem::tcNoAta(string tcno)
{
	mMusteriTcNo = tcno;
}

void Islem::kaydet()
{
	fstream islemKayit, kayitUrunKodu, kayitTc, islemListele, islemtxtsil, islemtemp;
	string isim, soyisim, tcno, tel, uKod, uAdi, uFiyat;
	string kaydetTc = "", urunkodugir = "";
	string listeKod, listeTc, listeIslem;
	string silKod, silTcno, silIslem;
	Kontrol islemKontrol;
	int secimMusteri;

	islemKontrol.tcgirilen();
	kaydetTc = islemKontrol.tcDondur();

	islemKontrol.tavanCiz(30);
	islemKontrol.araCiz(30, "MUSTERI PANELI");
	islemKontrol.zeminCiz(30);
	islemKontrol.musteriMenuCiz(30);

	cout << "Secim: ";
	cin >> secimMusteri;

	switch (secimMusteri)
	{
	case 1:
		kayitUrunKodu.open("Urun.txt", ios::in);
		kayitTc.open("Musteriler.txt", ios::in);
		islemKayit.open("Islem.txt", ios::in | ios::out | ios::app);
		islemKontrol.tavanCiz(31);
		islemKontrol.araCiz(31, "URUN LISTESI");
		islemKontrol.zeminCiz(31);
		islemKontrol.merchandiseList(31);
		cout << "Urun Kodu Girin: ";
		cin >> urunkodugir;
		if (islemKayit.is_open() == true)
		{
			islemKayit << islemKoduGetir() << " ";
		}

		if (kayitUrunKodu.is_open() == true)
		{
			while (kayitUrunKodu >> uKod >> uAdi >> uFiyat)
			{
				if (urunkodugir == uKod)
					islemKayit << uKod << " ";
			}
		}
		if (kayitTc.is_open() == true)
		{
			while (kayitTc >> isim >> soyisim >> tcno >> tel)
			{
				if (kaydetTc == tcno)
					islemKayit << tcno << endl;
			}
		}
		kayitUrunKodu.close();
		kayitTc.close();
		islemKayit.close();
		break;
	case 2:
		islemListele.open("Islem.txt", ios::in);
		if (islemListele.is_open() == true)
		{
			while (islemListele >> listeIslem >> listeKod >> listeTc)
			{
				if (kaydetTc == listeTc)
					cout << listeIslem << endl;
			}
		}
		islemListele.close();
		break;
	case 3:
		islemKontrol.deleteOp();
		break;
	case 4:
		cout << "Geri cikmak icin herhangi bir tusa basiniz." << endl;
		break;
	default:
		cout << "Yanlis bir tusa bastiniz!!!!!!!!!!!!!!!!!!" << endl;
		break;
	}
}

string Islem::islemKoduUret()
{
	string islemkodu = "";

	for (int i = 0; i < 4; i++)
	{
		islemkodu += '0' + rand() % 10;
	}
	return islemkodu;
}
