#ifndef PLIKTEKSTOWY
#define PLIKTEKSTOWY

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy{
protected:
    const string NAZWA_PLIKU;

public:
    PlikTekstowy(string nazwaPliku);
    bool czyPlikJestPusty(fstream& plikTekstowy);
};
#endif

