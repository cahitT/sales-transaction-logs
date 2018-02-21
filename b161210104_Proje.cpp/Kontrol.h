#pragma once
#include<string>
using namespace std;
class Kontrol //Kontrol sinifinin uye metodlarinin protoype tanimlamalari yapildi.
{
public:
	void anapanel();

	void musteriPanel();

	void yoneticiPanel();

	void musteriKayitPanel();

	void urunKayitPanel();

	void urunPanel();

	void tavanCiz(int genislik); //Tavan ciziyor.

	void zeminCiz(int genislik); //Zemin cizimi.

	void araCiz(int genislik, string yazi); //Ara kisimi ciziyor.

	void ayracCiz(int genislik); //Ayrac Ciziyor.

	void anaMenuCiz(int genislik); //Ana menuyu ekrana cikartiyor.

	void musteriMenuCiz(int genislik); //Musteri panelini ciziyor.

	void yoneticiMenuCiz(int genislik); //Yonetici panelini ciziyor.

	void memberList(int genislik); //Musteri listesini ekrana cikartiyor.

	void merchandiseList(int genislik); //Urun listesini ekrana cikartiyor.

	void deleteOp(); //Yapilan islemleri siliyor.

	void deleteMember(); //Var olan bir musteriyi siliyor.

	void tcgirilen(); //Tcnogir degiskeninin girilmesini sagliyor.

	string tcDondur(); //girelen tc degerini donduruyor.

	void urunKayit(int genislik); //Urun kaydi yapilmasini sagliyor.

	void musteriKayit(int genislik); //Musteri kaydinin yapilmasini sagliyor.
private: //Butun degiskenler private olarak tanimlandi.
	string number_Tc = "";
	char DUZCIZGI = 205;
	char SOLUSTKOSE = 201;
	char SAGUSTKOSE = 187;
	char DIKEYCIZGI = 186;
	char ASAGIAYRAC = 203;
	char SOLALTKOSE = 200;
	char SAGALTKOSE = 188;
	char YUKARIAYRAC = 202;
	char YATAYSAGAAYRAC = 204;
	char YATAYSOLAAYRAC = 185;
};