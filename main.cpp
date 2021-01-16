#include <iostream>
#include "KsiazkaAdresowa.h"

#include "AdresatManager.h"
#include "PlikZAdresatami.h"
#include "Adresat.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "KsiazkaAdresowa.txt");
    while (true) {
        ksiazkaAdresowa.wyswietlMenu();
    }
    return 0;
}

int maintest() {        //testowanie funkcji
    AdresatManager adresatManager("KsiazkaAdresowa.txt", 1);
    adresatManager.wyswietlWszystkichAdresatow();
    adresatManager.usunAdresata();
    adresatManager.edytujAdresata();
    adresatManager.wyswietlWszystkichAdresatow();
    //adresatManager.dodajAdresata();

    return 0;
}

int main123() { //testowanie funkcji

    PlikZAdresatami plik("uzytkownicy_testowe.txt");
    Adresat adresat(1,5,"Jan","Kowalski","111555888","gmail.com","Warszawa");
    plik.dopiszAdresataDoPliku(adresat);
    return 0;
}
