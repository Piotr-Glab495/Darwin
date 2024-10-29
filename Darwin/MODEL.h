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

/** \brief Funkcja sprawdzaj¹ca, czy podany ci¹g znaków zawiera liczbê ca³kowit¹.
* 
* Funkcja dzia³a w oparciu o pêtlê przebiegaj¹c¹ przez ci¹g znakowy i sprawdzaj¹c¹, czy ka¿dy znak jest cyfr¹.\n
* Jeœli natrafi na znak nie spe³niaj¹cy tego warunku to funkcja przyjmuje wartoœæ fa³sz.
* Jest wywo³ywana do sprawdzenia czy u¿ytkownik poda³ prze³¹czniki w prawid³owy sposób.\n
* \see czy_double()
* @param przelacznik_calkowitoliczbowy ci¹g znakowy zawieraj¹cy jedn¹ ze zmiennych u¿ywanych w zadaniu, która MUSI byæ liczb¹ ca³kowit¹.
* @return prawda jeœli prze³¹cznik zosta³ odpowiednio podany lub fa³sz jeœli nie.
*/
bool czy_int(const string& przelacznik_calkowitoliczbowy);

/** \brief Funkcja sprawdzaj¹ca, czy podany ci¹g znakowy zawiera liczbê zmiennoprzecinkow¹.
* 
* Funkcja dzia³a w oparciu o dwie pêtle przebiegaj¹ce przez ci¹g znakowy.\n
* Jedna zlicza iloœæ przecinków w ci¹gu, a druga sprawdza czy ka¿dy znak jest liczb¹ lub przecinkiem.\n
* Je¿eli iloœæ przecinków w liczbie by³a ró¿na od 1 lub jakiœ znak nie by³ ani cyfr¹ ani przecinkiem, to funkcja przyjmuje wartoœæ fa³sz.\n
* Jest wywo³ywana do sprawdzenia czy u¿ytkownik poda³ prze³¹czniki w prawid³owy sposób.\n
* \see czy_int()
* @param przelacznik_zmiennoprzecinkowy £añcuh znakowy zawieraj¹cy jedn¹ ze zmiennych u¿ywanych w zadaniu, która MUSI byæ liczb¹ zmiennoprzecinkow¹.
* @return prawda jeœli prze³¹cznik zosta³ podany prawid³owo lub fa³sz jeœli nie.
*/
bool czy_double(const string& przelacznik_zmiennoprzecinkowy);

/** \brief Funkcja konwertuj¹ca prze³¹czniki bêd¹ce liczbami z ci¹gów znakowych na odpowiedni typ.
* 
* Dzia³a w oparciu o funkcje stoi oraz stod.\n
* Jest wywo³ywana po sprawdzeniu czy prze³¹czniki s¹ zapisane w poprawny sposób.\n
* Nie zwraca ¿adnej wartoœci.
* @param pe zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-p".
* @param ka zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-k".
* @param wu zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-w".
* @param er zmienna bêd¹ca ci¹giem znaków zawieraj¹ca prze³¹cznik "-r".
* @param p zmienna bêd¹ca nieujemn¹ liczb¹ ca³kowit¹, w której ma zostaæ zapisany prze³¹cznik "-p" podany przez u¿ytkownika.
* @param k zmienna bêd¹ca nieujemn¹ liczb¹ ca³kowit¹, w której ma zostaæ zapisany prze³¹cznik "-k" podany przez u¿ytkownika.
* @param w zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹, w której ma zostaæ zapisany prze³¹cznik "-w" podany przez u¿ytkownika.
* @param r zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹, w której ma zostaæ zapisany prze³¹cznik "-r" podany przez u¿ytkownika.
*/
void konwertuj_przelaczniki(const string& pe, const string& ka, const string& wu, const string& er, unsigned int& p, unsigned int& k, double& w, double& r);

/** \brief Funkcja dopisuj¹ca znak nowej linii w pliku wejœciowym.
* 
* Dzia³anie mo¿na opisaæ nastêpuj¹co: otwiera plik o œcie¿ce podanej w argumentach jako strumieñ wyjœciowy, dopisuje znak koñca linii, 
* a nastêpnie zamyka plik.\n
* Nie ingeruje w inne wartoœci podane w pliku przez u¿ytkownika.\n
* Jest wywo³ywana, gdy funkcja sprawdz_koniec() wykryje, ¿e w pliku brak na koñcu pustej linii, która jest konieczna do prawid³owego 
* dzia³ania funkcji .eof() z biblioteki fstream, przy pomocy której wczytywane s¹ dane z pliku.\n
* Nie zwraca ¿adnej wartoœci.
* @param sciezka_pliku zmienna bêd¹ca ci¹giem znaków zawieraj¹ca œcie¿kê do pliku, w którym ma byæ dokonana zmiana.
*/
void dopisz_enter(const string& sciezka_pliku);

/** \brief Funkcja doprowadzaj¹ca strumieñ plikowy do stanu umo¿liwiaj¹cego dalsze wczytywanie.
* 
* Funkcja sprawdza, czy stan podanego w argumentach strumienia jest niepoprawny. W razie potrzeby czyœci flagi b³êdów oraz bufor.\n
* Jest wywo³ywana, gdy funkcja sprawdz_koniec() wykryje, ¿e w pliku znajduje siê na koñcu pusta linia konieczna do prawid³owego 
* dzia³ania funkcji .eof() z biblioteki fstream, przy pomocy której wczytywane s¹ dane z pliku. Koniecznoœæ naprawy strumienia wynika ze sposobu 
* dzia³ania funkcji sprawdz_koniec().
* @param file_in strumieñ wejœciowy, z którego czytane by³y dane, a w którym wyst¹pi³ b³¹d.
*/
void naprawa_strumienia(ifstream& file_in);

/** \brief Funkcja sprawdzaj¹ca czy w pliku, z którego wczytywane s¹ dane, znajduje siê na koñcu pusta linia konieczna do prawid³owego 
* wczytywania danych przy pomocy funkcji .eof() z biblioteki fstream.
* 
* Funkcja najpierw zmienia miejsce wczytywania na -2 w stosunku do koñca pliku, a nastêpnie wczytuje jeden znak. Jeœli natrafi na 
* liczbê to wywo³uje funkcjê dopisz_enter(sciezka_pliku), a jeœli na znak koñca pliku, to funkcje naprawa_strumienia(file_in).\n
* Jest wywo³ywana przed rozpoczêciem wczytywania danych z pliku.
* @param file_in strumieñ wejœciowy, który ma byæ poddany sprawdzeniu.
* @param sciezka_pliku zmienna bêd¹ca ci¹giem znaków zawieraj¹ca œcie¿kê do pliku, który ma byæ poddany sprawdzeniu.
*/
void sprawdz_koniec(ifstream& file_in,const string& sciezka_pliku);

/** \brief Funkcja wczytuj¹ca dane z pliku wejœciowego do listy reprezentuj¹cej populacjê.
* 
* Dzia³anie mo¿na omówiæ nastêpuj¹co:\n
* Funkcja tworzy odpowiednie zmienne lokalne i sprawdza format pliku wejœciowego funkcj¹ sprawdz_koniec() 
* (która go modyfikuje w razie potrzeby przy pomocy innych funkcji).\n
* Nastêpnie dopóki plik siê nie skoñczy³ kolejno: pobiera jedn¹ liniê, zamienia j¹ na strumieñ, wczytuje ze strumienia 
* (w razie napotkania w nim litery przyjmuje wartoœæ fa³sz i koñczy dzia³anie) i zapisuje do populacji po drodze usuwaj¹c zbêdne 
* elementy pojawiaj¹ce siê w wyniku stosowania w pêtlach funkcji .eof() z bibliotek fstream oraz sstream.\n
* Jeœli ca³oœæ przebieg³a pomyœlnie przyjmuje wartoœæ prawda.\n
* Jest wywo³ywana po sprawdzeniu czy pliki podane przez u¿ytkownika zosta³y prawid³owo otwarte.
* @param file_in strumieñ wejœciowy, z którego maj¹ byæ wczytywane dane.
* @param populacja lista reprezentuj¹ca populacjê, do której maj¹ byæ wczytywane dane.
* @param sciezka_pliku œcie¿ka do pliku, z którego wczytywane s¹ dane (do podania do funkcji sprawdz_koniec() )
* @return prawda jeœli operacja wczytania przebieg³a prawid³owo lub fa³sz jeœli po drodze wyst¹pi³y b³êdy.
*/
bool wczytaj_z_pliku(ifstream& file_in, list<list<int>>& populacja, const string& sciezka_pliku);

/** \brief Funkcja losuj¹ca dwa osobniki do krzy¿owania zgodnie z za³o¿eniami tematu.
* 
* Funkcja losuje dwie liczby z przedzia³u bêd¹cego odbiciem iloœci osobników w populacji, a nastêpnie inkrementuje licznik krzy¿owañ w pokoleniu.\n
* Zawiera ochronê przed wylosowaniem danego osobnika do krzy¿owania z nim samym.\n
* Jest wywo³ywana przez funkcjê krzy¿uj¹c¹ osobniki w pokoleniu.\n
* Nie zwraca wartoœci.
* @param populacja lista reprezentuj¹ca populacjê, z której maj¹ byæ losowane osobniki.
* @param pierwszy zmienna bêd¹ca liczb¹ ca³kowit¹, w której bêdzie przechowywany indeks jednego z chromosomów wybranych do krzy¿owania.
* @param drugi zmienna bêd¹ca liczb¹ ca³kowit¹, w której bêdzie przechowywany indeks drugiego z chromosomów wybranych do krzy¿owania.
* @param licznik_losowan zmienna bêd¹ca liczb¹ ca³kowit¹, która przechowuje iloœæ krzy¿owañ dokonanych w pokoleniu.
*/
void losuj_pare(list<list<int>>& populacja, int& pierwszy, int& drugi, int& licznik_losowan);

/** \brief Funkcja odnajduj¹ca w populacji chromosom, który ma byæ krzy¿owany.
* 
* Jest wywo³ywana przez funkcjê krzy¿uj¹c¹ osobniki w pokoleniu po wylosowaniu, które to maj¹ byæ (funkcj¹ losuj_pare()).\n
* Nie zwraca wartoœci.
* \note Jest wywo³ywana dwa razy dla ka¿dego krzy¿owania!
* @param populacja lista reprezentuj¹ca populacjê, w której szukamy chromosomu.
* @param chromosom_krzyzowany indeks chromosomu w populacji, który ma byæ znaleziony.
* @param chromosom_szukany lista reprezentuj¹ca osobnika, który ma byæ znaleziony.
*/
void znajdz_krzyzowany(const list<list<int>>& populacja, int& chromosom_krzyzowany, list<int>& chromosom_szukany);

/** \brief Funkcja zwracaj¹ca listê bêd¹c¹ czêœci¹ chromosomu.
* 
* Funkcja losuje miejsce przerwania jednego z chromosomów krzy¿owanych i pobiera do listy wartoœci genów tego chromosomu 
* za miejscem przerwania, aby mo¿na je by³o póŸniej do³¹czyæ do drugiego krzy¿owanego chromosomu.\n
* Jest wywo³ywana przez funkcjê krzy¿uj¹c¹ osobniki w pokoleniu po "uzyskaniu dostêpu" do konkretnego chromosomu (funkcj¹ znajdz_krzyzowany())
* \note Jest wywo³ywana dwa razy dla ka¿dego krzy¿owania!
* @param populacja lista reprezentuj¹ca populacjê, w której znajduje siê chromosom przerywany.
* @param miejsce_przerwania zmienna bêd¹ca liczb¹ ca³kowit¹, w której bêdzie przechowywana informacja na temat miejsca przerwania chromosomu.
* @param aktualny_chromosom lista reprezentuj¹ca chromosom osobnika, który bêdzie przerywany.
* @return Fragment chromosomu, który ma byæ przeniesiony w skutek krzy¿owania.
*/
list<int> pobierz_koncowke(list<list<int>>& populacja, int& miejsce_przerwania, list<int>& aktualny_chromosom);

/** \brief Funkcja usuwaj¹ca niepotrzebn¹ czêœæ chromosomu.
* 
* Funkcja usuwa wszystkie elementy za miejscem przerwania (znalezionym w funkcji pobierz_koncowke()) z chromosomu, który ma byæ krzy¿owany, 
* po to, aby móc w ich miejsce wpisaæ czêœæ drugiego z pary krzy¿owanych chromosomów.\n
* Jest wywo³ywana przez funkcjê krzy¿uj¹ca osobniki w pokoleniu po skopiowaniu danych za miejscem przerwania funkcj¹ pobierz_koncowke().\n
* \note Jest wywo³ywana dwa razy dla ka¿dego krzy¿owania!
* Nie zwraca wartoœci.
* @param miejsce_przerwania zmienna bêd¹ca liczb¹ ca³kowit¹, w której przechowywana jest informacja na temat miejsca przerwania chromosomu.
* @param aktualny_chromosom chromosom osobnika, który ma byæ poddany operacji.
*/
void usun_skopiowane(const int& miejsce_przerwania, list<int>& aktualny_chromosom);

/** \brief Funkcja ³¹cz¹ca odpowiednie elementy chromosomów krzy¿owanych.
* 
* Funkcja do³¹cza do chromosomu, który przyjê³a jako argument fragment drugiego. \attention Ca³a operacja odbywa siê na elementach odpowiednio 
* przygotowanych innymi funkcjami (znajdz_krzyzowany(), pobierz_koncowke(), usun_skopiowane()).
* Jest wywo³ywana przez funkcjê krzy¿uj¹c¹ osobniki na etapie posiadania w pamiêci elementów chromosomów, które maj¹ byæ po³¹czone.
* \note Jest wywo³ywana dwa razy dla ka¿dego krzy¿owania!
* @param fragment_dolaczany fragment pobrany z koñca chromosomu jednego osobnika w celu do³¹czenia do drugiego.
* @param aktualny_chromosom lista reprezentuj¹ca chromosom osobnika, do którego dodane maj¹ byæ dane w wyniku krzy¿owania.
*/
void scal_chromosomy(const list<int>& fragment_dolaczany, list<int>& aktualny_chromosom);

/** \brief Funkcja wpisuj¹ca do populacji osobniki po krzy¿owaniu w miejsce tych z przed krzy¿owania.
* 
* Dok³adnie rzecz bior¹c funkcja zamienia w populacji listy osobników wybranych do losowania 
* z listami lokalnymi, które w chwili wywo³ania funkcji zawieraj¹ ju¿ dane osobników po dokonaniu krzy¿owania.
* \note Jest wywo³ywana dwa razy dla ka¿dego krzy¿owania!
* @param populacja lista reprezentuj¹ca populacjê, na której dokonywane s¹ zmiany.
* @param chromosom lista reprezentuj¹ca osobnika, który bêdzie wpisany do populacji.
* @param zmienna bêd¹ca liczb¹ ca³kowit¹, która przechowuje indeks jednego z chromosomów wybranych do krzy¿owania.
*/
void zamien_z_kopia(list<list<int>>& populacja, list<int>& chromosom, const int& miejsce);

/** \brief Funkcja wykonuj¹ca wszystkie krzy¿owania w danym pokoleniu.
* 
* Operuje na pêtli sprawdzaj¹cej iloœæ wykonanych krzy¿owañ. Wewn¹trz tej pêtli tworzone s¹ zmienne lokalne, a wykonywane nastêpnie 
* instrukcje mo¿na opisaæ nastêpuj¹co:\n
* losowanie obu chromosomów do krzy¿owania, zapisanie kopii jednego z nich do zmiennej, kopiowanie danych za losowym miejscem w 
* chromosomie do krzy¿owania, usuniêcie elementów ju¿ skopiowanych z chromosomu, wykonanie ostatnich trzech kroków dla drugiego chromosomu, 
* scalenie pocz¹tku jednego chromosomu z koñcem drugiego i odwrotnie, wstawienie kopii (skrzy¿owane chromosomy) do edytowanej populacji 
* w miejsce tych pobranych na pocz¹tku.\n
* Nie zwraca ¿adnej wartoœci.\n
* Jest wywo³ywana przez funkcjê modyfikuj_przez_pokolenia wykonuj¹c¹ za³o¿enia programu.
* \note Wszystkie dzia³ania wymienione po przecinku odbywaj¹ siê przy pomocy zagnie¿dzonych funkcji, których dokumentacjê umieszczono w 
* sekcji "zobacz równie¿".
* \see losuj_pare(), znajdz_krzyzowany(), pobierz_koncowke(), usun_skopiowane(), scal_chromosomy(), zamien_z_kopia().
* @param populacja lista reprezentuj¹ca populacjê, której osobniki maj¹ byæ krzy¿owane.
* @param k zmienna bêd¹ca liczb¹ ca³kowit¹ przechowuj¹ca iloœæ krzy¿owañ zadanych przez u¿ytkownika do wykonania w ka¿dym pokoleniu.
*/
void krzyzuj_pokolenie(list<list<int>>& populacja, const int& k);

/** \brief Funkcja wyliczaj¹ca najwy¿sz¹ wartoœæ funkcji dopasowania wœród osobników w populacji.
* 
* Funkcja liczy wartoœci funkcji dopasowania dla osobników w populacji i zapisuje najwiêksza z nich do zmiennej.\n
* Jest wywo³ywana przez funkcjê sprawdz_dopasowanie() w celu umo¿liwienia jej liczenia wartoœci funkcji dopasowania dla wszystkich elementów.\n
* Nie zwraca ¿adnej wartoœci.\n
* @param populacja lista reprezentuj¹ca populacjê osobników, której osobniki maj¹ wyliczan¹ wartoœæ funkcji dopasowania.
* @param najwieksza_srednia zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹, która ma przechowywaæ najwy¿sz¹ wartoœæ funkcji dopasowania.
*/
void znajdz_najwieksza_srednia(const list<list<int>>& populacja, double& najwieksza_srednia);

/** \brief Funkcja tworz¹ca nowe pokolenie na podstawie wartoœci funkcji dopasowania osobników w populacji.
* 
* Funkcja porównuje wartoœæ funkcji dopasowania podanego jej poprzez argumenty osobnika z wartoœciami wspó³czynników "w" oraz "r" podanymi 
* przez u¿ytkownika, a nastêpnie w razie potrzeby dodaje osobnika (raz lub dwa razy) do listy reprezentuj¹cej nowe pokolenie 
* populacji po wykonaniu krzy¿owañ dla danego pokolenia.\n
* Jest wywo³ywana przez funkcjê sprawdz_dopasowanie() po wyliczeniu wartoœci funkcji dopasowania dla konkretnego osobnika.\n
* Nie zwraca ¿adnej wartoœci.
* @param nowe_pokolenie lista reprezentuj¹ca pokolenie osobników tworzone zgodnie z za³o¿eniami zadania.
* @param osobnik lista reprezentuj¹ca chromosom osobnika poddawanego testom.
* @param srednia zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ funkcji dopasowania osobnika poddawanego testom.
* @param wsp_w zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ wspó³czynnika "w" podan¹ przez u¿ytkownika.
* @param wsp_r zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ wspó³czynnika "r" podan¹ przez u¿ytkownika.
* \attention Po wykonaniu funkcji zmienna przyjêta jako osobnik przechowuje populacjê zmodyfikowan¹ zgodnie ze wszystkimi za³o¿eniami zadania 
* dla jednego pokolenia.
*/
void tworz_nowe_pokolenie(list<list<int>>& nowe_pokolenie, list<int>& osobnik, const double& srednia, const double& wsp_w, const double& wsp_r);

/** \brief Funkcja licz¹ca wartoœci dopasowania dla ca³ego pokolenia.
* 
* Po utworzeniu zmiennych lokalnych wywo³uje funkcje znajdz_najwieksza_srednia() w celu umo¿liwienia sobie liczenia wartoœci 
* funkcji dopasowania dla wszystkich elementów. Nastêpnie przebiega przy pomocy pêtli przez populacjê i liczy wartoœci funkcji dopasowania 
* dla kolejnych osobników, po drodze przypisuj¹c wartoœci¹ wiêkszym od jeden wartoœæ 1 (dla usystematyzowania przedzia³u wartoœci) i dla 
* ka¿dego osobnika wywo³uje funkcjê tworz_nowe_pokolenie() tym samym buduj¹c stopniowo nowe pokolenie populacji.\n
* Jest wywo³ywana przez funkcje konfrontuj_pokolenie_ze_srodowiskiem zaraz po utworzeniu zmiennych lokalnych.\n
* Nie zwraca ¿adnej wartoœci.
* @param populacja lista reprezentuj¹ca pokolenie osobników rozwijan¹ zgodnie z za³o¿eniami zadania.
* @param nowe_pokolenie lista reprezentuj¹ca nowe pokolenie tworzone na podstawie populacji wejœciowej.
* @param wsp_w zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ wspó³czynnika "w" podan¹ przez u¿ytkownika podawana, by umo¿liwiæ wywo³anie funkcji tworz_nowe_pokolenie().
* @param wsp_r zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ wspó³czynnika "r" podan¹ przez u¿ytkownika podawana, by umo¿liwiæ wywo³anie funkcji tworz_nowe_pokolenie().
*/
void sprawdz_dopasowanie(const list<list<int>>& populacja, list<list<int>>& nowe_pokolenie, const double& wsp_w, const double& wsp_r);

/** \brief Funkcja sprawdzaj¹ca dopasowania i zapisuj¹ca do populacji nowe pokolenie.
* 
* Tworzy lokaln¹ zmienn¹, dla której wywo³uje funkcjê sprawdz_dopasowanie(). Po uzyskaniu wyników posiada ju¿ nowe pokolenie po 
* dokonaniu zmian opisanych zadaniem, wiêc czyœci star¹ populacjê i zapisuje do niej nowe pokolenie uzyskane z konfrontacji ze œrodowiskiem.\n
* Jest wywo³ywana przez funkcjê modyfikuj_przez_pokolenia na etapie, w którym zosta³y ju¿ wykonane konieczne krzy¿owania.\n
* Nie zwraca ¿adnej wartoœci.
* @param populacja lista reprezentuj¹ca populacjê osobników rozwijan¹ zgodnie z za³o¿eniami zadania.
* @param wsp_w  zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ wspó³czynnika "w" podan¹ przez u¿ytkownika podawana, by umo¿liwiæ wywo³anie funkcji sprawdz_dopasowanie().
* @param wsp_r zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wartoœæ wspó³czynnika "r" podan¹ przez u¿ytkownika podawana, by umo¿liwiæ wywo³anie funkcji sprawdz_dopasowanie().
*/
void konfrontuj_pokolenie_ze_srodowiskiem(list<list<int>>& populacja, const double& wsp_w, const double& wsp_r);

/** \brief Funkcja wykonuj¹ca zamys³ programu przez wszystkie zadane pokolenia.
* 
* Funkcja u¿ywa pêtli iteruj¹cej przez pokolenia wewn¹trz której wywo³ywane s¹ funkcje odpowiednialne za krzy¿owanie oraz testowanie 
* dopasowania, a wiêc krzyzuj_pokolenie() oraz konfrontuj_pokolenie_ze_srodowiskiem().\n
* Jest wywo³ywana w funkcji main jako funkcja odpowiedzialna za wykonanie ca³ego zadania.\n
* Nie zwraca ¿adnej wartoœci.
* \note W³aœciwie stworzona g³ównie po to, aby zminimalizowaæ iloœæ kodu w funkcji main odpowiedzialnego za implementacjê warunków zadania 
* do jednej funkcji.
* @param populacja lista reprezentuj¹ca populacjê osobników pobran¹ z pliku wejœciowego.
* @param p zmienna bêd¹ca liczb¹ ca³kowit¹ przechowuj¹ca iloœæ pokoleñ podan¹ przez u¿ytkownika.
* @param k zmienna bêd¹ca liczb¹ ca³kowit¹ przechowuj¹ca iloœæ krzy¿owañ do wykonania w danych pokoleniu podan¹ przez u¿ytkownika.
* @param w zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wspó³czynnik wymierania w.
* @param r zmienna bêd¹ca liczb¹ zmiennoprzecinkow¹ przechowuj¹ca wspó³czynnik rozmna¿ania r.
*/
void modyfikuj_przez_pokolenia(list<list<int>>& populacja, const int& p, const int& k, const double& w, const double& r);

/** \brief Funkcja wypisuj¹ca dane z populacji (po odpowiednich modyfikacjach) do pliku wyjœciowego.
* 
* U¿ywa pêtli zagnie¿d¿onej w pêtli do wypisywania chromosomów osobników populacji w formie zgodnej z za³o¿eniami zadania.\n
* Jest wywo³ywana po wszystkich modyfikacjach populacji.\n
* Nie zwraca ¿adnej wartoœci.
*/
void wypisz_do_pliku(ofstream& file_out, const list<list<int>>& populacja);

#endif