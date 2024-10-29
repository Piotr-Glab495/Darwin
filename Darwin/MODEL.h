/**
* \file
*/
#ifndef MODEL_H
#define MODEL_H
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<list>
#include<ctime>
#include<cstdlib>
using namespace std;

/** \brief Funkcja sprawdzaj�ca, czy podany ci�g znak�w zawiera liczb� ca�kowit�.
* 
* Funkcja dzia�a w oparciu o p�tl� przebiegaj�c� przez ci�g znakowy i sprawdzaj�c�, czy ka�dy znak jest cyfr�.\n
* Je�li natrafi na znak nie spe�niaj�cy tego warunku to funkcja przyjmuje warto�� fa�sz.
* Jest wywo�ywana do sprawdzenia czy u�ytkownik poda� prze��czniki w prawid�owy spos�b.\n
* \see czy_double()
* @param przelacznik_calkowitoliczbowy ci�g znakowy zawieraj�cy jedn� ze zmiennych u�ywanych w zadaniu, kt�ra MUSI by� liczb� ca�kowit�.
* @return prawda je�li prze��cznik zosta� odpowiednio podany lub fa�sz je�li nie.
*/
bool czy_int(const string& przelacznik_calkowitoliczbowy);

/** \brief Funkcja sprawdzaj�ca, czy podany ci�g znakowy zawiera liczb� zmiennoprzecinkow�.
* 
* Funkcja dzia�a w oparciu o dwie p�tle przebiegaj�ce przez ci�g znakowy.\n
* Jedna zlicza ilo�� przecink�w w ci�gu, a druga sprawdza czy ka�dy znak jest liczb� lub przecinkiem.\n
* Je�eli ilo�� przecink�w w liczbie by�a r�na od 1 lub jaki� znak nie by� ani cyfr� ani przecinkiem, to funkcja przyjmuje warto�� fa�sz.\n
* Jest wywo�ywana do sprawdzenia czy u�ytkownik poda� prze��czniki w prawid�owy spos�b.\n
* \see czy_int()
* @param przelacznik_zmiennoprzecinkowy �a�cuh znakowy zawieraj�cy jedn� ze zmiennych u�ywanych w zadaniu, kt�ra MUSI by� liczb� zmiennoprzecinkow�.
* @return prawda je�li prze��cznik zosta� podany prawid�owo lub fa�sz je�li nie.
*/
bool czy_double(const string& przelacznik_zmiennoprzecinkowy);

/** \brief Funkcja konwertuj�ca prze��czniki b�d�ce liczbami z ci�g�w znakowych na odpowiedni typ.
* 
* Dzia�a w oparciu o funkcje stoi oraz stod.\n
* Jest wywo�ywana po sprawdzeniu czy prze��czniki s� zapisane w poprawny spos�b.\n
* Nie zwraca �adnej warto�ci.
* @param pe zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-p".
* @param ka zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-k".
* @param wu zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-w".
* @param er zmienna b�d�ca ci�giem znak�w zawieraj�ca prze��cznik "-r".
* @param p zmienna b�d�ca nieujemn� liczb� ca�kowit�, w kt�rej ma zosta� zapisany prze��cznik "-p" podany przez u�ytkownika.
* @param k zmienna b�d�ca nieujemn� liczb� ca�kowit�, w kt�rej ma zosta� zapisany prze��cznik "-k" podany przez u�ytkownika.
* @param w zmienna b�d�ca liczb� zmiennoprzecinkow�, w kt�rej ma zosta� zapisany prze��cznik "-w" podany przez u�ytkownika.
* @param r zmienna b�d�ca liczb� zmiennoprzecinkow�, w kt�rej ma zosta� zapisany prze��cznik "-r" podany przez u�ytkownika.
*/
void konwertuj_przelaczniki(const string& pe, const string& ka, const string& wu, const string& er, unsigned int& p, unsigned int& k, double& w, double& r);

/** \brief Funkcja dopisuj�ca znak nowej linii w pliku wej�ciowym.
* 
* Dzia�anie mo�na opisa� nast�puj�co: otwiera plik o �cie�ce podanej w argumentach jako strumie� wyj�ciowy, dopisuje znak ko�ca linii, 
* a nast�pnie zamyka plik.\n
* Nie ingeruje w inne warto�ci podane w pliku przez u�ytkownika.\n
* Jest wywo�ywana, gdy funkcja sprawdz_koniec() wykryje, �e w pliku brak na ko�cu pustej linii, kt�ra jest konieczna do prawid�owego 
* dzia�ania funkcji .eof() z biblioteki fstream, przy pomocy kt�rej wczytywane s� dane z pliku.\n
* Nie zwraca �adnej warto�ci.
* @param sciezka_pliku zmienna b�d�ca ci�giem znak�w zawieraj�ca �cie�k� do pliku, w kt�rym ma by� dokonana zmiana.
*/
void dopisz_enter(const string& sciezka_pliku);

/** \brief Funkcja doprowadzaj�ca strumie� plikowy do stanu umo�liwiaj�cego dalsze wczytywanie.
* 
* Funkcja sprawdza, czy stan podanego w argumentach strumienia jest niepoprawny. W razie potrzeby czy�ci flagi b��d�w oraz bufor.\n
* Jest wywo�ywana, gdy funkcja sprawdz_koniec() wykryje, �e w pliku znajduje si� na ko�cu pusta linia konieczna do prawid�owego 
* dzia�ania funkcji .eof() z biblioteki fstream, przy pomocy kt�rej wczytywane s� dane z pliku. Konieczno�� naprawy strumienia wynika ze sposobu 
* dzia�ania funkcji sprawdz_koniec().
* @param file_in strumie� wej�ciowy, z kt�rego czytane by�y dane, a w kt�rym wyst�pi� b��d.
*/
void naprawa_strumienia(ifstream& file_in);

/** \brief Funkcja sprawdzaj�ca czy w pliku, z kt�rego wczytywane s� dane, znajduje si� na ko�cu pusta linia konieczna do prawid�owego 
* wczytywania danych przy pomocy funkcji .eof() z biblioteki fstream.
* 
* Funkcja najpierw zmienia miejsce wczytywania na -2 w stosunku do ko�ca pliku, a nast�pnie wczytuje jeden znak. Je�li natrafi na 
* liczb� to wywo�uje funkcj� dopisz_enter(sciezka_pliku), a je�li na znak ko�ca pliku, to funkcje naprawa_strumienia(file_in).\n
* Jest wywo�ywana przed rozpocz�ciem wczytywania danych z pliku.
* @param file_in strumie� wej�ciowy, kt�ry ma by� poddany sprawdzeniu.
* @param sciezka_pliku zmienna b�d�ca ci�giem znak�w zawieraj�ca �cie�k� do pliku, kt�ry ma by� poddany sprawdzeniu.
*/
void sprawdz_koniec(ifstream& file_in,const string& sciezka_pliku);

/** \brief Funkcja wczytuj�ca dane z pliku wej�ciowego do listy reprezentuj�cej populacj�.
* 
* Dzia�anie mo�na om�wi� nast�puj�co:\n
* Funkcja tworzy odpowiednie zmienne lokalne i sprawdza format pliku wej�ciowego funkcj� sprawdz_koniec() 
* (kt�ra go modyfikuje w razie potrzeby przy pomocy innych funkcji).\n
* Nast�pnie dop�ki plik si� nie sko�czy� kolejno: pobiera jedn� lini�, zamienia j� na strumie�, wczytuje ze strumienia 
* (w razie napotkania w nim litery przyjmuje warto�� fa�sz i ko�czy dzia�anie) i zapisuje do populacji po drodze usuwaj�c zb�dne 
* elementy pojawiaj�ce si� w wyniku stosowania w p�tlach funkcji .eof() z bibliotek fstream oraz sstream.\n
* Je�li ca�o�� przebieg�a pomy�lnie przyjmuje warto�� prawda.\n
* Jest wywo�ywana po sprawdzeniu czy pliki podane przez u�ytkownika zosta�y prawid�owo otwarte.
* @param file_in strumie� wej�ciowy, z kt�rego maj� by� wczytywane dane.
* @param populacja lista reprezentuj�ca populacj�, do kt�rej maj� by� wczytywane dane.
* @param sciezka_pliku �cie�ka do pliku, z kt�rego wczytywane s� dane (do podania do funkcji sprawdz_koniec() )
* @return prawda je�li operacja wczytania przebieg�a prawid�owo lub fa�sz je�li po drodze wyst�pi�y b��dy.
*/
bool wczytaj_z_pliku(ifstream& file_in, list<list<int>>& populacja, const string& sciezka_pliku);

/** \brief Funkcja losuj�ca dwa osobniki do krzy�owania zgodnie z za�o�eniami tematu.
* 
* Funkcja losuje dwie liczby z przedzia�u b�d�cego odbiciem ilo�ci osobnik�w w populacji, a nast�pnie inkrementuje licznik krzy�owa� w pokoleniu.\n
* Zawiera ochron� przed wylosowaniem danego osobnika do krzy�owania z nim samym.\n
* Jest wywo�ywana przez funkcj� krzy�uj�c� osobniki w pokoleniu.\n
* Nie zwraca warto�ci.
* @param populacja lista reprezentuj�ca populacj�, z kt�rej maj� by� losowane osobniki.
* @param pierwszy zmienna b�d�ca liczb� ca�kowit�, w kt�rej b�dzie przechowywany indeks jednego z chromosom�w wybranych do krzy�owania.
* @param drugi zmienna b�d�ca liczb� ca�kowit�, w kt�rej b�dzie przechowywany indeks drugiego z chromosom�w wybranych do krzy�owania.
* @param licznik_losowan zmienna b�d�ca liczb� ca�kowit�, kt�ra przechowuje ilo�� krzy�owa� dokonanych w pokoleniu.
*/
void losuj_pare(list<list<int>>& populacja, int& pierwszy, int& drugi, int& licznik_losowan);

/** \brief Funkcja odnajduj�ca w populacji chromosom, kt�ry ma by� krzy�owany.
* 
* Jest wywo�ywana przez funkcj� krzy�uj�c� osobniki w pokoleniu po wylosowaniu, kt�re to maj� by� (funkcj� losuj_pare()).\n
* Nie zwraca warto�ci.
* \note Jest wywo�ywana dwa razy dla ka�dego krzy�owania!
* @param populacja lista reprezentuj�ca populacj�, w kt�rej szukamy chromosomu.
* @param chromosom_krzyzowany indeks chromosomu w populacji, kt�ry ma by� znaleziony.
* @param chromosom_szukany lista reprezentuj�ca osobnika, kt�ry ma by� znaleziony.
*/
void znajdz_krzyzowany(const list<list<int>>& populacja, int& chromosom_krzyzowany, list<int>& chromosom_szukany);

/** \brief Funkcja zwracaj�ca list� b�d�c� cz�ci� chromosomu.
* 
* Funkcja losuje miejsce przerwania jednego z chromosom�w krzy�owanych i pobiera do listy warto�ci gen�w tego chromosomu 
* za miejscem przerwania, aby mo�na je by�o p�niej do��czy� do drugiego krzy�owanego chromosomu.\n
* Jest wywo�ywana przez funkcj� krzy�uj�c� osobniki w pokoleniu po "uzyskaniu dost�pu" do konkretnego chromosomu (funkcj� znajdz_krzyzowany())
* \note Jest wywo�ywana dwa razy dla ka�dego krzy�owania!
* @param populacja lista reprezentuj�ca populacj�, w kt�rej znajduje si� chromosom przerywany.
* @param miejsce_przerwania zmienna b�d�ca liczb� ca�kowit�, w kt�rej b�dzie przechowywana informacja na temat miejsca przerwania chromosomu.
* @param aktualny_chromosom lista reprezentuj�ca chromosom osobnika, kt�ry b�dzie przerywany.
* @return Fragment chromosomu, kt�ry ma by� przeniesiony w skutek krzy�owania.
*/
list<int> pobierz_koncowke(list<list<int>>& populacja, int& miejsce_przerwania, list<int>& aktualny_chromosom);

/** \brief Funkcja usuwaj�ca niepotrzebn� cz�� chromosomu.
* 
* Funkcja usuwa wszystkie elementy za miejscem przerwania (znalezionym w funkcji pobierz_koncowke()) z chromosomu, kt�ry ma by� krzy�owany, 
* po to, aby m�c w ich miejsce wpisa� cz�� drugiego z pary krzy�owanych chromosom�w.\n
* Jest wywo�ywana przez funkcj� krzy�uj�ca osobniki w pokoleniu po skopiowaniu danych za miejscem przerwania funkcj� pobierz_koncowke().\n
* \note Jest wywo�ywana dwa razy dla ka�dego krzy�owania!
* Nie zwraca warto�ci.
* @param miejsce_przerwania zmienna b�d�ca liczb� ca�kowit�, w kt�rej przechowywana jest informacja na temat miejsca przerwania chromosomu.
* @param aktualny_chromosom chromosom osobnika, kt�ry ma by� poddany operacji.
*/
void usun_skopiowane(const int& miejsce_przerwania, list<int>& aktualny_chromosom);

/** \brief Funkcja ��cz�ca odpowiednie elementy chromosom�w krzy�owanych.
* 
* Funkcja do��cza do chromosomu, kt�ry przyj�a jako argument fragment drugiego. \attention Ca�a operacja odbywa si� na elementach odpowiednio 
* przygotowanych innymi funkcjami (znajdz_krzyzowany(), pobierz_koncowke(), usun_skopiowane()).
* Jest wywo�ywana przez funkcj� krzy�uj�c� osobniki na etapie posiadania w pami�ci element�w chromosom�w, kt�re maj� by� po��czone.
* \note Jest wywo�ywana dwa razy dla ka�dego krzy�owania!
* @param fragment_dolaczany fragment pobrany z ko�ca chromosomu jednego osobnika w celu do��czenia do drugiego.
* @param aktualny_chromosom lista reprezentuj�ca chromosom osobnika, do kt�rego dodane maj� by� dane w wyniku krzy�owania.
*/
void scal_chromosomy(const list<int>& fragment_dolaczany, list<int>& aktualny_chromosom);

/** \brief Funkcja wpisuj�ca do populacji osobniki po krzy�owaniu w miejsce tych z przed krzy�owania.
* 
* Dok�adnie rzecz bior�c funkcja zamienia w populacji listy osobnik�w wybranych do losowania 
* z listami lokalnymi, kt�re w chwili wywo�ania funkcji zawieraj� ju� dane osobnik�w po dokonaniu krzy�owania.
* \note Jest wywo�ywana dwa razy dla ka�dego krzy�owania!
* @param populacja lista reprezentuj�ca populacj�, na kt�rej dokonywane s� zmiany.
* @param chromosom lista reprezentuj�ca osobnika, kt�ry b�dzie wpisany do populacji.
* @param zmienna b�d�ca liczb� ca�kowit�, kt�ra przechowuje indeks jednego z chromosom�w wybranych do krzy�owania.
*/
void zamien_z_kopia(list<list<int>>& populacja, list<int>& chromosom, const int& miejsce);

/** \brief Funkcja wykonuj�ca wszystkie krzy�owania w danym pokoleniu.
* 
* Operuje na p�tli sprawdzaj�cej ilo�� wykonanych krzy�owa�. Wewn�trz tej p�tli tworzone s� zmienne lokalne, a wykonywane nast�pnie 
* instrukcje mo�na opisa� nast�puj�co:\n
* losowanie obu chromosom�w do krzy�owania, zapisanie kopii jednego z nich do zmiennej, kopiowanie danych za losowym miejscem w 
* chromosomie do krzy�owania, usuni�cie element�w ju� skopiowanych z chromosomu, wykonanie ostatnich trzech krok�w dla drugiego chromosomu, 
* scalenie pocz�tku jednego chromosomu z ko�cem drugiego i odwrotnie, wstawienie kopii (skrzy�owane chromosomy) do edytowanej populacji 
* w miejsce tych pobranych na pocz�tku.\n
* Nie zwraca �adnej warto�ci.\n
* Jest wywo�ywana przez funkcj� modyfikuj_przez_pokolenia wykonuj�c� za�o�enia programu.
* \note Wszystkie dzia�ania wymienione po przecinku odbywaj� si� przy pomocy zagnie�dzonych funkcji, kt�rych dokumentacj� umieszczono w 
* sekcji "zobacz r�wnie�".
* \see losuj_pare(), znajdz_krzyzowany(), pobierz_koncowke(), usun_skopiowane(), scal_chromosomy(), zamien_z_kopia().
* @param populacja lista reprezentuj�ca populacj�, kt�rej osobniki maj� by� krzy�owane.
* @param k zmienna b�d�ca liczb� ca�kowit� przechowuj�ca ilo�� krzy�owa� zadanych przez u�ytkownika do wykonania w ka�dym pokoleniu.
*/
void krzyzuj_pokolenie(list<list<int>>& populacja, const int& k);

/** \brief Funkcja wyliczaj�ca najwy�sz� warto�� funkcji dopasowania w�r�d osobnik�w w populacji.
* 
* Funkcja liczy warto�ci funkcji dopasowania dla osobnik�w w populacji i zapisuje najwi�ksza z nich do zmiennej.\n
* Jest wywo�ywana przez funkcj� sprawdz_dopasowanie() w celu umo�liwienia jej liczenia warto�ci funkcji dopasowania dla wszystkich element�w.\n
* Nie zwraca �adnej warto�ci.\n
* @param populacja lista reprezentuj�ca populacj� osobnik�w, kt�rej osobniki maj� wyliczan� warto�� funkcji dopasowania.
* @param najwieksza_srednia zmienna b�d�ca liczb� zmiennoprzecinkow�, kt�ra ma przechowywa� najwy�sz� warto�� funkcji dopasowania.
*/
void znajdz_najwieksza_srednia(const list<list<int>>& populacja, double& najwieksza_srednia);

/** \brief Funkcja tworz�ca nowe pokolenie na podstawie warto�ci funkcji dopasowania osobnik�w w populacji.
* 
* Funkcja por�wnuje warto�� funkcji dopasowania podanego jej poprzez argumenty osobnika z warto�ciami wsp�czynnik�w "w" oraz "r" podanymi 
* przez u�ytkownika, a nast�pnie w razie potrzeby dodaje osobnika (raz lub dwa razy) do listy reprezentuj�cej nowe pokolenie 
* populacji po wykonaniu krzy�owa� dla danego pokolenia.\n
* Jest wywo�ywana przez funkcj� sprawdz_dopasowanie() po wyliczeniu warto�ci funkcji dopasowania dla konkretnego osobnika.\n
* Nie zwraca �adnej warto�ci.
* @param nowe_pokolenie lista reprezentuj�ca pokolenie osobnik�w tworzone zgodnie z za�o�eniami zadania.
* @param osobnik lista reprezentuj�ca chromosom osobnika poddawanego testom.
* @param srednia zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� funkcji dopasowania osobnika poddawanego testom.
* @param wsp_w zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� wsp�czynnika "w" podan� przez u�ytkownika.
* @param wsp_r zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� wsp�czynnika "r" podan� przez u�ytkownika.
* \attention Po wykonaniu funkcji zmienna przyj�ta jako osobnik przechowuje populacj� zmodyfikowan� zgodnie ze wszystkimi za�o�eniami zadania 
* dla jednego pokolenia.
*/
void tworz_nowe_pokolenie(list<list<int>>& nowe_pokolenie, list<int>& osobnik, const double& srednia, const double& wsp_w, const double& wsp_r);

/** \brief Funkcja licz�ca warto�ci dopasowania dla ca�ego pokolenia.
* 
* Po utworzeniu zmiennych lokalnych wywo�uje funkcje znajdz_najwieksza_srednia() w celu umo�liwienia sobie liczenia warto�ci 
* funkcji dopasowania dla wszystkich element�w. Nast�pnie przebiega przy pomocy p�tli przez populacj� i liczy warto�ci funkcji dopasowania 
* dla kolejnych osobnik�w, po drodze przypisuj�c warto�ci� wi�kszym od jeden warto�� 1 (dla usystematyzowania przedzia�u warto�ci) i dla 
* ka�dego osobnika wywo�uje funkcj� tworz_nowe_pokolenie() tym samym buduj�c stopniowo nowe pokolenie populacji.\n
* Jest wywo�ywana przez funkcje konfrontuj_pokolenie_ze_srodowiskiem zaraz po utworzeniu zmiennych lokalnych.\n
* Nie zwraca �adnej warto�ci.
* @param populacja lista reprezentuj�ca pokolenie osobnik�w rozwijan� zgodnie z za�o�eniami zadania.
* @param nowe_pokolenie lista reprezentuj�ca nowe pokolenie tworzone na podstawie populacji wej�ciowej.
* @param wsp_w zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� wsp�czynnika "w" podan� przez u�ytkownika podawana, by umo�liwi� wywo�anie funkcji tworz_nowe_pokolenie().
* @param wsp_r zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� wsp�czynnika "r" podan� przez u�ytkownika podawana, by umo�liwi� wywo�anie funkcji tworz_nowe_pokolenie().
*/
void sprawdz_dopasowanie(const list<list<int>>& populacja, list<list<int>>& nowe_pokolenie, const double& wsp_w, const double& wsp_r);

/** \brief Funkcja sprawdzaj�ca dopasowania i zapisuj�ca do populacji nowe pokolenie.
* 
* Tworzy lokaln� zmienn�, dla kt�rej wywo�uje funkcj� sprawdz_dopasowanie(). Po uzyskaniu wynik�w posiada ju� nowe pokolenie po 
* dokonaniu zmian opisanych zadaniem, wi�c czy�ci star� populacj� i zapisuje do niej nowe pokolenie uzyskane z konfrontacji ze �rodowiskiem.\n
* Jest wywo�ywana przez funkcj� modyfikuj_przez_pokolenia na etapie, w kt�rym zosta�y ju� wykonane konieczne krzy�owania.\n
* Nie zwraca �adnej warto�ci.
* @param populacja lista reprezentuj�ca populacj� osobnik�w rozwijan� zgodnie z za�o�eniami zadania.
* @param wsp_w  zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� wsp�czynnika "w" podan� przez u�ytkownika podawana, by umo�liwi� wywo�anie funkcji sprawdz_dopasowanie().
* @param wsp_r zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca warto�� wsp�czynnika "r" podan� przez u�ytkownika podawana, by umo�liwi� wywo�anie funkcji sprawdz_dopasowanie().
*/
void konfrontuj_pokolenie_ze_srodowiskiem(list<list<int>>& populacja, const double& wsp_w, const double& wsp_r);

/** \brief Funkcja wykonuj�ca zamys� programu przez wszystkie zadane pokolenia.
* 
* Funkcja u�ywa p�tli iteruj�cej przez pokolenia wewn�trz kt�rej wywo�ywane s� funkcje odpowiednialne za krzy�owanie oraz testowanie 
* dopasowania, a wi�c krzyzuj_pokolenie() oraz konfrontuj_pokolenie_ze_srodowiskiem().\n
* Jest wywo�ywana w funkcji main jako funkcja odpowiedzialna za wykonanie ca�ego zadania.\n
* Nie zwraca �adnej warto�ci.
* \note W�a�ciwie stworzona g��wnie po to, aby zminimalizowa� ilo�� kodu w funkcji main odpowiedzialnego za implementacj� warunk�w zadania 
* do jednej funkcji.
* @param populacja lista reprezentuj�ca populacj� osobnik�w pobran� z pliku wej�ciowego.
* @param p zmienna b�d�ca liczb� ca�kowit� przechowuj�ca ilo�� pokole� podan� przez u�ytkownika.
* @param k zmienna b�d�ca liczb� ca�kowit� przechowuj�ca ilo�� krzy�owa� do wykonania w danych pokoleniu podan� przez u�ytkownika.
* @param w zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca wsp�czynnik wymierania w.
* @param r zmienna b�d�ca liczb� zmiennoprzecinkow� przechowuj�ca wsp�czynnik rozmna�ania r.
*/
void modyfikuj_przez_pokolenia(list<list<int>>& populacja, const int& p, const int& k, const double& w, const double& r);

/** \brief Funkcja wypisuj�ca dane z populacji (po odpowiednich modyfikacjach) do pliku wyj�ciowego.
* 
* U�ywa p�tli zagnie�d�onej w p�tli do wypisywania chromosom�w osobnik�w populacji w formie zgodnej z za�o�eniami zadania.\n
* Jest wywo�ywana po wszystkich modyfikacjach populacji.\n
* Nie zwraca �adnej warto�ci.
*/
void wypisz_do_pliku(ofstream& file_out, const list<list<int>>& populacja);

#endif