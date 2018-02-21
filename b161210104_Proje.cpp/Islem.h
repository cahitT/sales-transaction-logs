#pragma once
#include <string>

using namespace std;
class Islem
{
public:
	Islem();

	string	urunKoduGetir();

	string	tcNoGetir();

	string	islemKoduGetir();

	void	urunKoduAta(string kod);

	void	tcNoAta(string tcno);

	void	kaydet();

	string islemKoduUret();
private:
	string  mIslemKodu;
	string	mUrunKodu;
	string  mMusteriTcNo;
};