#ifndef UZYTKOWNIKMANAGER_H
#define UZYTKOWNIKMANAGER_H
#include <iostream>
#include <vector>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzytkownikManager{

    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

public:

    UzytkownikManager(string nazwaPlikuKsiazkiAdresowej);
    void wczytajUzytkownikowZPliku();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();

};
#endif
