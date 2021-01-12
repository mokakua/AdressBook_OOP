#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>

using namespace std;

class MetodyPomocnicze {

public:

    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static bool czyPlikJestPusty(fstream& plikTekstowy);
    static string wczytajLinie();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);

};
#endif
