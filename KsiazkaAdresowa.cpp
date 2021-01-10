#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami):
    uzytkownikManager(nazwaPlikuZUzytkownikami),
    adresatManager(nazwaPlikuZAdresatami){
    uzytkownikManager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzytkownikManager.logowanieUzytkownika();
    adresatManager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikManager.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}


void KsiazkaAdresowa::wyswietlIdZalogowanegoUzytkownika(){
    cout << "Zalogowany nr: " << uzytkownikManager.pobierzIdZalogowanegoUzytkownika() <<endl;
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatManager.dodajAdresata(uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow(){
    adresatManager.wyswietlWszystkichAdresatow();
}
