#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include <windows.h>

#include "Uzytkownik.h"
#include "UzytkownikManager.h"
#include "Adresat.h"
#include "AdresatManager.h"
#include "MetodyPomocnicze.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlIdZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    void wyswietlMenuStartowe();
    void wywolajFunkcjeStartowe();
    void wyswietlMenuGlowne();
    void wywolajFunkcjeGlowne();

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);
    ~KsiazkaAdresowa();
    void wyswietlMenu();
    /*
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlIdZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    void wyswietlMenuStartowe();
    void wywolajFunkcjeStartowe();
    void wyswietlMenuGlowne();
    void wywolajFunkcjeGlowne();
    */

};
#endif
