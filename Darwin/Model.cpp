#include"MODEL.h"
using namespace std;

bool czy_int(const string& przelacznik_calkowitoliczbowy)
{
	for (char znak : przelacznik_calkowitoliczbowy)
		if (znak < '0' || znak > '9')
			return false;
	return true;
}

bool czy_double(const string& przelacznik_zmiennoprzecinkowy)
{
	int licznik_przecinkow = 0;
	for (char znak : przelacznik_zmiennoprzecinkowy)
		if (znak == '.')
			licznik_przecinkow++;
	for (char znak : przelacznik_zmiennoprzecinkowy)
		if ((znak < '0' || znak>'9') && znak != '.')
			return false;
	if (licznik_przecinkow != 1)
		return false;
	return true;
}

void konwertuj_przelaczniki(const string& pe, const string& ka, const string& wu, const string& er, unsigned int& p, unsigned int& k, double& w, double& r)
{
	p = stoi(pe);
	k = stoi(ka);
	w = stod(wu);
	r = stod(er);
}

void dopisz_enter(const string& sciezka_pliku)
{
	ofstream tymczasowo(sciezka_pliku,ios::app);
	tymczasowo << "\n";
	tymczasowo.close();
}

void naprawa_strumienia(ifstream& file_in)
{
	if (!file_in)
	{
		file_in.clear();
		file_in.ignore(1024, '\n');
	}
}

void sprawdz_koniec(ifstream& file_in,const string& sciezka_pliku)
{
	file_in.seekg(-2, ios::end);
	char temp;
	file_in >> temp;
	if (temp <= '9' && temp >= '0')	
	{
		dopisz_enter(sciezka_pliku);
		file_in.seekg(0, ios::beg);
	}
	else
	{
		naprawa_strumienia(file_in);
		file_in.seekg(0, ios::beg);
	}
}

bool wczytaj_z_pliku(ifstream& file_in, list<list<int>>& populacja, const string& sciezka_pliku)
{
	list<int> chromosom;
	int gen;
	string aktualny_chromosom;	
	sprawdz_koniec(file_in,sciezka_pliku);
	while (!file_in.eof())
	{
		getline(file_in,aktualny_chromosom);
		istringstream chromosom_strumien(aktualny_chromosom);
		while(!chromosom_strumien.eof())
		{
			chromosom_strumien >> gen;
			if (!chromosom_strumien && !chromosom_strumien.eof())
				return false;
			chromosom.push_back(gen);
		}
		chromosom.pop_back();
		if(chromosom.size() >= 2)	// just rejecting chromosomes too short to handle during the population interbreeding
			populacja.push_back(chromosom);
		chromosom.clear();
	}
	return true;
}


void losuj_pare(list<list<int>>& populacja, int& pierwszy, int& drugi, int& licznik_losowan)
{
		pierwszy = (rand() % populacja.size());
		drugi = (rand() % populacja.size());
		while (drugi == pierwszy)
			drugi = (rand() % populacja.size());
		licznik_losowan++;
}

void znajdz_krzyzowany(const list<list<int>>& populacja, int&chromosom_krzyzowany,list<int>& chromosom_szukany)
{
	list<list<int>>::const_iterator iterator_populacji = populacja.cbegin();
	for (int i = 0; i < chromosom_krzyzowany; i++)
		iterator_populacji++;
	chromosom_szukany = *iterator_populacji;
}

list<int> pobierz_koncowke(list<list<int>>& populacja,int& miejsce_przerwania,list<int>& aktualny_chromosom)
{
	list<int> szukany_fragment;

	list<int>::const_iterator iterator_chromosomu = aktualny_chromosom.cbegin();
	if (aktualny_chromosom.size() < 2)
		return szukany_fragment;
	miejsce_przerwania = 1 + (rand() % (aktualny_chromosom.size() - 1));
	for (int i = 0; i < miejsce_przerwania; i++)
		iterator_chromosomu++;
	for (   ; iterator_chromosomu != aktualny_chromosom.end(); iterator_chromosomu++)
		szukany_fragment.push_back(*iterator_chromosomu);
	return szukany_fragment;
}

void usun_skopiowane(const int& miejsce_przerwania, list<int>& aktualny_chromosom)
{
	for (int i = aktualny_chromosom.size()-miejsce_przerwania; i > 0; i--)
		aktualny_chromosom.pop_back();
}

void scal_chromosomy(const list<int>& fragment_dolaczany, list<int>& aktualny_chromosom)
{
	for (auto gen : fragment_dolaczany)
		aktualny_chromosom.push_back(gen);
}

void zamien_z_kopia(list<list<int>>& populacja, list<int>& chromosom, const int& miejsce)
{
	list<list<int>>::iterator iterator_populacji = populacja.begin();
	for (int i = 0; i < miejsce; i++)
		iterator_populacji++;
	chromosom.swap(*iterator_populacji);
}

void krzyzuj_pokolenie(list<list<int>>& populacja, const int& k)
{
	int licznik_losowan = 0;
	while (licznik_losowan < k)
	{
		list<int> fragment_za_peknieciem1, fragment_za_peknieciem2, chromosom_pierwszy, chromosom_drugi;
		int pierwszy_do_krzyzowania, drugi_do_krzyzowania, miejsce_przerwania = 0;
		losuj_pare(populacja, pierwszy_do_krzyzowania, drugi_do_krzyzowania, licznik_losowan);
		
		znajdz_krzyzowany(populacja, drugi_do_krzyzowania, chromosom_drugi);
		fragment_za_peknieciem1 = pobierz_koncowke(populacja, miejsce_przerwania, chromosom_drugi);
		usun_skopiowane(miejsce_przerwania, chromosom_drugi);

		znajdz_krzyzowany(populacja, pierwszy_do_krzyzowania, chromosom_pierwszy);
		fragment_za_peknieciem2 = pobierz_koncowke(populacja, miejsce_przerwania, chromosom_pierwszy);
		usun_skopiowane(miejsce_przerwania, chromosom_pierwszy);

		scal_chromosomy(fragment_za_peknieciem1, chromosom_pierwszy);
		scal_chromosomy(fragment_za_peknieciem2, chromosom_drugi);
		zamien_z_kopia(populacja, chromosom_pierwszy, pierwszy_do_krzyzowania);
		zamien_z_kopia(populacja, chromosom_drugi, drugi_do_krzyzowania);
	}
}

void znajdz_najwieksza_srednia(const list<list<int>>& populacja, double& najwieksza_srednia)
{
	unsigned int suma_chwilowa = 0;
	double srednia_chwilowa = 0;
	for (auto& osobnik : populacja)
	{
		for (auto gen : osobnik)
			suma_chwilowa += gen;
		srednia_chwilowa = suma_chwilowa / osobnik.size();
		if (srednia_chwilowa > najwieksza_srednia)
			najwieksza_srednia = srednia_chwilowa;
	}
}

void tworz_nowe_pokolenie(list<list<int>>& nowe_pokolenie, list<int>& osobnik, const double& srednia, const double& wsp_w, const double& wsp_r)
{
	if (srednia > wsp_w)
		nowe_pokolenie.push_back(osobnik);
	if (srednia > wsp_r)
		nowe_pokolenie.push_back(osobnik);
}

void sprawdz_dopasowanie(const list<list<int>>& populacja,list<list<int>>& nowe_pokolenie, const double& wsp_w, const double& wsp_r)
{
	double najwieksza_srednia=0;
	unsigned int suma = 0;
	znajdz_najwieksza_srednia(populacja, najwieksza_srednia);
	double srednia = 0;
	for (auto osobnik : populacja)
	{
		for (auto gen : osobnik)
			suma += gen;
		srednia = (suma / osobnik.size()) / najwieksza_srednia;
		if (srednia > 1)
			srednia = 1;
		tworz_nowe_pokolenie(nowe_pokolenie, osobnik, srednia, wsp_w, wsp_r);
	}
}

void konfrontuj_pokolenie_ze_srodowiskiem(list<list<int>>& populacja, const double& wsp_w, const double& wsp_r)
{
	list<list<int>> nowe_pokolenie;
	sprawdz_dopasowanie(populacja, nowe_pokolenie, wsp_w, wsp_r);
	populacja.clear();
	for (auto osobnik : nowe_pokolenie)
		populacja.push_back(osobnik);
}

void modyfikuj_przez_pokolenia(list<list<int>>& populacja, const int& p, const int& k, const double& w, const double& r)
{
	for (int i = 0; i < p; i++)
	{
		krzyzuj_pokolenie(populacja, k);
		konfrontuj_pokolenie_ze_srodowiskiem(populacja, w, r);
	}
}

void wypisz_do_pliku(ofstream& file_out, const list<list<int>>& populacja)
{
	for (auto Osobnik : populacja)
	{
		for (auto gen : Osobnik)
			file_out << gen << " ";
		file_out << endl;
	}
}