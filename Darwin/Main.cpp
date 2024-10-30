/**
* \file
*/
#include"WIDOK.h"
#include"MODEL.h"
using namespace std;

int main(int args,char * params[])
{
	string file_in,file_out, pe, ka, wu,er;
	unsigned int p, k;
	double w, r;
	list<list<int>> populacja;
	srand(time(0));

	while (!ilosc_przelacznikow(args) ||
		!pobierz_przelacznik(params, "-i", file_in) || 
		!pobierz_przelacznik(params, "-o", file_out)|| 
		!pobierz_przelacznik(params, "-w", wu) || 
		!pobierz_przelacznik(params, "-r", er) || 
		!pobierz_przelacznik(params, "-p", pe)|| 
		!pobierz_przelacznik(params, "-k", ka))
	{
		instrukcja_obslugi();
		return 0;
	}

	if (sprawdz_poprawnosc_przelacznikow(pe, ka, wu, er))
		konwertuj_przelaczniki(pe,ka,wu,er,p,k,w,r);
	else
	{
		instrukcja_obslugi();
		return 0;
	}

	ifstream File_In(file_in,ios::binary);
	ofstream File_Out(file_out);
	if (!sprawdz_otwarcie(File_In, File_Out))
	{
		instrukcja_obslugi();
		return 0;
	}

	if (!wczytaj_z_pliku(File_In, populacja, file_in))
	{
		litera_w_pliku();
		return 0;
	}
	File_In.close();

	for (auto i : populacja) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}

	if (!populacja.empty() && populacja.size() > 1)
	{
		modyfikuj_przez_pokolenia(populacja, p, k, w, r);
		wypisz_do_pliku(File_Out, populacja);
	}
	File_Out.close();

	return 0;
}