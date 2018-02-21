#pragma once
#include<string>
using namespace std;

class Musteri //Musterilerin isim soyisim gibi degerlerinin bulundugu musteri sinifi olusturuluyor.
{
public:
	Musteri(); //Yapici fonksiyonun tanimlamasi yapiliyor.

	string	tcnoGetir(); //TC numarasini cagiriyor.
	string	telnoGetir(); //Telefon numarasini cagiriyor.
	string	isimGetir(); //Musterinin ismini donduruyor.
	string	soyisimGetir(); //Musterinin soyisim degerini donduruyor.


	void isimAta(string isim); //Verilen degere gore isim,soyisim,tc,tel no ataniyor.
	void telnoAta(string telno);
	void tcnoAta(string tcno);
	void soyisimAta(string soyisim);

	string	tcnouret(); //Tc numarasi uretiliyor.
	string	telnoUret(); //Tel numarasi uretiliyor.
private:
	string mIsim; //Musterilerin isim, soyisim gibi onemli gizli degerleri private icerisinde tanimlandi.
	string mSoyisim;
	string mTcno;
	string mTelno;
};