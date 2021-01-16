#include "PlikTekstowy.h"

PlikTekstowy::PlikTekstowy(string nazwaPliku)
:NAZWA_PLIKU(nazwaPliku){}


bool PlikTekstowy::czyPlikJestPusty(fstream& plikTekstowy) {
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}
