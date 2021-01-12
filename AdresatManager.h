#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatManager {

    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);

public:
    AdresatManager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika);
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

};
#endif
