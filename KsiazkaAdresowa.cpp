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
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzytkownikManager.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}


void KsiazkaAdresowa::podajIdZalogowanegoUzytkownika(){
    cout << "Zalogowany: " << uzytkownikManager.podajIdZalogowanegoUzytkownika() <<endl;
}

void KsiazkaAdresowa::dodajAdresata(){
    adresatManager.dodajAdresata(uzytkownikManager.podajIdZalogowanegoUzytkownika());
}
