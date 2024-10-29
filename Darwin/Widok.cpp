#include"WIDOK.h"
#include"MODEL.h"
using namespace std;

void instrukcja_obslugi()
{
	cout << "Wlaczyles program ze zla liczba / nieprawidlowymi parametrami wiersza polecen.\n";
	cout << "Sprawdz, czy pliki maja odpowiednie sciezki, a odpowiednie zmienne na pewno przyjmuja  taki format liczbowy, jaki powinny.\n";
	cout << "\nAby program zadzialal prawidlowo, musisz po nazwie programu podac odpowiednie przelaczniki.\n";
	cout << "Sa nimi: \n\n";
	cout << "'-i' - sciezka do pliku wejsciowego z populacja\n";
	cout << "'-o' - sciezka do pliku wyjsciowego z populacja\n";
	cout << "'-w' - wspolczynnik wymierania (liczba zmiennoprzecinkowa) z przedzialu <0,1>\n";
	cout << "'-r' - wspolczynnik rozmnazania (liczba zmiennoprzecinkowa) z przedzialu <0,1>\n";
	cout << "'-p' liczba pokolen (liczba calkowita)\n";
	cout << "'-k' liczba k par osobnikow losowanych do krzyzowania (liczba calkowita)\n\n";
	cout << "Kolejnosc przelacznikow jest dowolna.\n\n";
	cout << "\nTwoj program :-)" << endl;
	system("pause");
}

bool ilosc_przelacznikow(const int& args)
{
	if (args != 13)
		return false;
	else
		return true;
}

bool pobierz_przelacznik(char* params[],const string& przelacznik,string& wyjscie)
{
	for (int i = 0; i < 13; i++)
		if (params[i] == przelacznik)
		{
			wyjscie = params[i + 1];
			return true;
		}
	return false;
}

bool sprawdz_poprawnosc_przelacznikow(const string& pe, const string& ka, const string& wu, const string& er)
{																												
	if (!czy_int(pe) || !czy_int(ka) || !czy_double(wu) || !czy_double(er))
		return false;
	return true;
}

bool sprawdz_otwarcie(ifstream& file_in, ofstream& file_out)
{
	if (!file_in.is_open())
	{
		cout << "Nie otwarto pliku wejsciowego." << endl;
		system("pause");
		return false;
	}
	if (!file_out.is_open())
	{
		cout << "Nie otwarto pliku wyyjsciowego." << endl;
		system("pause");
		return false;
	}
	return true;
}

void wypisz_populacje(list<list<int>>& lista_list)
{
	list<list<int>>::iterator iterator_listy_list;

	for (iterator_listy_list = lista_list.begin(); iterator_listy_list != lista_list.end(); ++iterator_listy_list)
	{
		list<int>::iterator iterator_listy;
		list<int>& adres_listy = *iterator_listy_list;

		for (iterator_listy = adres_listy.begin(); iterator_listy != adres_listy.end(); iterator_listy++)
			cout << *iterator_listy << "\t";
		cout << endl;
	}
}

void litera_w_pliku()
{
	cout << "\n\nWlaczyles program z plikiem wejsciowym, w ktorym znajduje sie znak nie bedacy liczba calkowita\n";
	cout << "Prosze, edytuj plik, ktory podajesz jako wejsciowy i uruchom program ponownie.\n\n";
	system("pause");
}