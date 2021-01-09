#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "KsiazkaAdresowa.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
    //ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    //ksiazkaAdresowa.wyswietlIdZalogowanegoUzytkownika();
    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
