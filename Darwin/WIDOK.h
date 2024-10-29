/**
* \file
*/
#ifndef WIDOK_H
#define WIDOK_H
#include<iostream>
#include<string>
#include<list>
using namespace std;

/** \brief Funkcja wyswietlaj¹ca na ekranie instrukcjê obs³ugi.
* 
* Jest implementowana w razie otwarcia programu ze z³¹ liczb¹ argumentów lub gdy prze³¹czniki nie zostan¹ prawid³owo wczytane.\n
* Nie przyjmuje parametrow.\n
* Jest wywo³ywana we wszystkich momentach, w których program natrafia na b³¹d.\n
* Nie zwraca wartoœci, lecz wypisuje na ekran.
*/
void instrukcja_obslugi();

/** \brief Funkcja sprawdzaj¹ca iloœæ prze³¹czników podanych przez u¿ytkownika podczas uruchamiania.
* 
* Jest wywo³ywana na pocz¹tku programu w celu wykrycia ewentualnych b³êdów.
* @param args iloœæ prze³¹czników podanych w wierszu poleceñ.
* @return prawda jeœli podano odpowiedni¹ iloœæ prze³¹czników lub fa³sz jeœli nie.
*/
bool ilosc_przelacznikow(const int& args);

/** \brief Funkcja znajduj¹ca wœród podanych prze³¹czników jeden konkretny i zapisuj¹ca go do zmiennej bêd¹cej ci¹giem znaków.
* 
* Jest wywo³ywana na pocz¹tku programu w celu pobrania danych i wykrycia ewentualnych b³êdów.
* @param params[] tablica prze³¹czników pobrana z wiersza poleceñ.
* @param przelacznik odpowiedni przelacznik ze zbioru {"-i","-o","-w","-p","-k","-r"}.
* @param wyjscie zmienna, w której zostanie zapisana œcie¿ka do odpowiedniego pliku.
* @return prawda jeœli odpowiedni prze³¹cznik zosta³ znaleziony lub fa³sz jeœli nie.
*/
bool pobierz_przelacznik(char* params[], const string& przelacznik, string& wyjscie);

/**\brief Funkcja sprawdzaj¹ca czy prze³¹czniki {"-w","-p","-k","-r"} wpisano w odpowiedniej postaci.
* 
* Funkcja sprawdza czy prze³¹czniki "-k" oraz "-p" zosta³y podane przez u¿ytkownika jako liczby ca³kowite dodatnie przy pomocy funkcji czy_int(),
* a tak¿e czy prze³¹czniki "-w" oraz "-r" zosta³y podane przez u¿ytkownika jako liczby zmiennoprzecinkowe przy pomocy funkcji czy_double().\n
* Jest implementowana po pobraniu prze³¹czników z wiersza poleceñ, ale przed rozpoczêciem dzia³añ na nich.
* @param pe zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-p"
* @param ka zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-k"
* @param wu zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-w"
* @param er zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-r"
* @return prawda jeœli wszystkie prze³¹czniki s¹ zapisane prawid³owo lub fa³sz jeœli któryœ nie jest.
*/
bool sprawdz_poprawnosc_przelacznikow(const string& pe, const string& ka, const string& wu, const string& er);

/** \brief Funkcja sprawdzaj¹ca czy pliki wejœciowe zosta³y otwarte.
*
* Jest wywo³ywana po utworzeniu strumieni plikowych ze œcie¿kami, które podano tu jako argumenty.\n
* Jeœli którykolwiek z plików nie zosta³ otwarty prawid³owo, wypisuje stosown¹ informacjê na ekran i przyjmuje wartoœæ fa³sz.\n
* Jeœli wszystko jest w porz¹dku przyjmuje wartoœæ prawda.
* @param file_in strumieñ wejœciowy do sprawdzenia.
* @param file_out strumieñ wyjœciowy do sprawdzenia
* @return Prawda jeœli pliki zosta³y otwarte prawid³owo lub fa³sz jeœli nie.
*/
bool sprawdz_otwarcie(ifstream& file_in, ofstream& file_out);

/**\brief Funkcja wypisuj¹ca populacjê przechowywan¹ w liœcie na ekran.
* 
* By³a u¿ywana przez pisz¹cego program w celach testowych i pozwala³a orientowaæ siê w tym, na jakim etapie jest program.
* \warning Obecnie nie jest nigdzie wywo³ywana i pozostawiono j¹ wy³¹cznie w razie chêci przetestowania programu przez oceniaj¹cego.
*/
void wypisz_populacje(list<list<int>>& lista_list);

/** \brief Funkcja wyœwietlaj¹ca na ekranie informacjê o b³êdzie w podanym pliku wejœciowym.
* 
* Stworzona dla odró¿nienia od podstawowej instrukcji obs³ugi, gdy¿ dotyczy wzglêdnie szczególnego przypadku niezwi¹zanego
* bezpoœrednio z podaniem argumentu wiersza poleceñ, a z samym plikiem, który zosta³ poprawnie wczytany, lecz zawiera b³¹d.\n
* Nie przyjmuje parametrów.\n
* Nie zwraca wartoœci, lecz wypisuje na ekran.\n
* Jest wywo³ywana, gdy program wykryje b³¹d strumienia wczytuj¹cego z pliku (inny ni¿ ten zwi¹zany z koñcem).
* \see wczytaj_z_pliku();
*/
void litera_w_pliku();
#endif 
