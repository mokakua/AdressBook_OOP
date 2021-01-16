#ifndef PLIKTEKSTOWY
#define PLIKTEKSTOWY

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
protected:
    const string NAZWA_PLIKU;

    bool czyPlikJestPusty(fstream& plikTekstowy);
public:
    PlikTekstowy(string nazwaPliku);

};
#endif

