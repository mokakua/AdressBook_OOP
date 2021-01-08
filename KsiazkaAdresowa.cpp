#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuKsiazkiAdresowej):
    uzytkownikManager(nazwaPlikuKsiazkiAdresowej) {
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
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikManager.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}


void KsiazkaAdresowa::podajIdZalogowanegoUzytkownika(){
    uzytkownikManager.podajIdZalogowanegoUzytkownika();
}
