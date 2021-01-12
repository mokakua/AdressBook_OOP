#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "Uzytkownik.h"
#include "UzytkownikManager.h"
#include "Adresat.h"
#include "AdresatManager.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikManager uzytkownikManager;
    AdresatManager *adresatManager;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);
    ~KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    void wyswietlIdZalogowanegoUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

};
#endif
