#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>

#include "Uzytkownik.h"
#include "UzytkownikManager.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikManager uzytkownikManager;

public:

    KsiazkaAdresowa(string nazwaPlikuKsiazkiAdresowej);
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
#endif
