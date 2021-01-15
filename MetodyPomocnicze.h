#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H
#include <iostream>
#include <algorithm>

using namespace std;

class MetodyPomocnicze {

public:

    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static bool czyPlikJestPusty(fstream& plikTekstowy);
    static string wczytajLinie();
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static int wczytajLiczbeCalkowita();
    static char wczytajZnak();
};
#endif
