#ifndef ADRESATMANAGER_H
#define ADRESATMANAGER_H
#include <iostream>
#include <vector>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatManager{

    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata;

    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

public:
    AdresatManager(string nazwaPlikuZAdresatami);
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);

};
#endif
