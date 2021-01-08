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
    ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
    //ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.wylogowanieUzytkownika();
    ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.dodajAdresata();
    ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika();

    //ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    return 0;
}
