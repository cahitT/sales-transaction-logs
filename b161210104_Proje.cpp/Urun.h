#pragma once
#include<string>
using namespace std;

class Urun
{
public:
	Urun();

	string urunAdiGetir();
	string urunKoduGetir();
	string fiyatGetir();

	void urunAdiAta(string urunAdi);
	void urunKoduAta(string urunkodu);
	void silinecekUrun();

	string urunKoduUret();
	string fiyatUret();
private:

	string mUrunKodu;
	string mUrunAdi;
	string mFiyat;
};