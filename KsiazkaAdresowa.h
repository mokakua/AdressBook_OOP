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
    AdresatManager adresatManager;

public:

    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    void podajIdZalogowanegoUzytkownika();  //testing
    void dodajAdresata();

};
#endif
