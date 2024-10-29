/**
* \file
*/
#ifndef WIDOK_H
#define WIDOK_H
#include<iostream>
#include<string>
#include<list>
using namespace std;

/** \brief Funkcja wyswietlaj�ca na ekranie instrukcj� obs�ugi.
* 
* Jest implementowana w razie otwarcia programu ze z�� liczb� argument�w lub gdy prze��czniki nie zostan� prawid�owo wczytane.\n
* Nie przyjmuje parametrow.\n
* Jest wywo�ywana we wszystkich momentach, w kt�rych program natrafia na b��d.\n
* Nie zwraca warto�ci, lecz wypisuje na ekran.
*/
void instrukcja_obslugi();

/** \brief Funkcja sprawdzaj�ca ilo�� prze��cznik�w podanych przez u�ytkownika podczas uruchamiania.
* 
* Jest wywo�ywana na pocz�tku programu w celu wykrycia ewentualnych b��d�w.
* @param args ilo�� prze��cznik�w podanych w wierszu polece�.
* @return prawda je�li podano odpowiedni� ilo�� prze��cznik�w lub fa�sz je�li nie.
*/
bool ilosc_przelacznikow(const int& args);

/** \brief Funkcja znajduj�ca w�r�d podanych prze��cznik�w jeden konkretny i zapisuj�ca go do zmiennej b�d�cej ci�giem znak�w.
* 
* Jest wywo�ywana na pocz�tku programu w celu pobrania danych i wykrycia ewentualnych b��d�w.
* @param params[] tablica prze��cznik�w pobrana z wiersza polece�.
* @param przelacznik odpowiedni przelacznik ze zbioru {"-i","-o","-w","-p","-k","-r"}.
* @param wyjscie zmienna, w kt�rej zostanie zapisana �cie�ka do odpowiedniego pliku.
* @return prawda je�li odpowiedni prze��cznik zosta� znaleziony lub fa�sz je�li nie.
*/
bool pobierz_przelacznik(char* params[], const string& przelacznik, string& wyjscie);

/**\brief Funkcja sprawdzaj�ca czy prze��czniki {"-w","-p","-k","-r"} wpisano w odpowiedniej postaci.
* 
* Funkcja sprawdza czy prze��czniki "-k" oraz "-p" zosta�y podane przez u�ytkownika jako liczby ca�kowite dodatnie przy pomocy funkcji czy_int(),
* a tak�e czy prze��czniki "-w" oraz "-r" zosta�y podane przez u�ytkownika jako liczby zmiennoprzecinkowe przy pomocy funkcji czy_double().\n
* Jest implementowana po pobraniu prze��cznik�w z wiersza polece�, ale przed rozpocz�ciem dzia�a� na nich.
* @param pe zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-p"
* @param ka zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-k"
* @param wu zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-w"
* @param er zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-r"
* @return prawda je�li wszystkie prze��czniki s� zapisane prawid�owo lub fa�sz je�li kt�ry� nie jest.
*/
bool sprawdz_poprawnosc_przelacznikow(const string& pe, const string& ka, const string& wu, const string& er);

/** \brief Funkcja sprawdzaj�ca czy pliki wej�ciowe zosta�y otwarte.
*
* Jest wywo�ywana po utworzeniu strumieni plikowych ze �cie�kami, kt�re podano tu jako argumenty.\n
* Je�li kt�rykolwiek z plik�w nie zosta� otwarty prawid�owo, wypisuje stosown� informacj� na ekran i przyjmuje warto�� fa�sz.\n
* Je�li wszystko jest w porz�dku przyjmuje warto�� prawda.
* @param file_in strumie� wej�ciowy do sprawdzenia.
* @param file_out strumie� wyj�ciowy do sprawdzenia
* @return Prawda je�li pliki zosta�y otwarte prawid�owo lub fa�sz je�li nie.
*/
bool sprawdz_otwarcie(ifstream& file_in, ofstream& file_out);

/**\brief Funkcja wypisuj�ca populacj� przechowywan� w li�cie na ekran.
* 
* By�a u�ywana przez pisz�cego program w celach testowych i pozwala�a orientowa� si� w tym, na jakim etapie jest program.
* \warning Obecnie nie jest nigdzie wywo�ywana i pozostawiono j� wy��cznie w razie ch�ci przetestowania programu przez oceniaj�cego.
*/
void wypisz_populacje(list<list<int>>& lista_list);

/** \brief Funkcja wy�wietlaj�ca na ekranie informacj� o b��dzie w podanym pliku wej�ciowym.
* 
* Stworzona dla odr�nienia od podstawowej instrukcji obs�ugi, gdy� dotyczy wzgl�dnie szczeg�lnego przypadku niezwi�zanego
* bezpo�rednio z podaniem argumentu wiersza polece�, a z samym plikiem, kt�ry zosta� poprawnie wczytany, lecz zawiera b��d.\n
* Nie przyjmuje parametr�w.\n
* Nie zwraca warto�ci, lecz wypisuje na ekran.\n
* Jest wywo�ywana, gdy program wykryje b��d strumienia wczytuj�cego z pliku (inny ni� ten zwi�zany z ko�cem).
* \see wczytaj_z_pliku();
*/
void litera_w_pliku();
#endif 
