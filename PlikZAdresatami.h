#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H
#include <iostream>
#include <fstream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami {

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI = "Adresaci_tymczasowo.txt";

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int pobierzZPlikuIdOstatniegoAdresata();
public:

    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI);
    bool dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdOstatniegoAdresata();
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
};
#endif
