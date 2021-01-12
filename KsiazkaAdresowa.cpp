#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami):
    uzytkownikManager(nazwaPlikuZUzytkownikami),
    NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
    adresatManager = NULL;
}
KsiazkaAdresowa::~KsiazkaAdresowa() {
    delete  adresatManager;
    adresatManager = NULL;
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikManager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikManager.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {
    uzytkownikManager.logowanieUzytkownika();
    if (uzytkownikManager.czyUzytkownikZalogowany()) {
        adresatManager = new AdresatManager(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikManager.pobierzIdZalogowanegoUzytkownika());
    }

}

void KsiazkaAdresowa::wylogowanieUzytkownika() {
    uzytkownikManager.wylogowanieUzytkownika();
    delete adresatManager;
    adresatManager = NULL;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikManager.zmianaHaslaZalogowanegoUzytkownika();
}


void KsiazkaAdresowa::wyswietlIdZalogowanegoUzytkownika() {
    cout << "Zalogowany nr: " << uzytkownikManager.pobierzIdZalogowanegoUzytkownika() <<endl;
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzytkownikManager.czyUzytkownikZalogowany()) {
        adresatManager->dodajAdresata();
    } else {
        cout << "Aby dodac adresata, nalezy sie zalogowac." <<endl;
    }
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    if (uzytkownikManager.czyUzytkownikZalogowany()) {
        adresatManager->wyswietlWszystkichAdresatow();
    } else {
        cout << "Aby wyswietlic adresatow, nalezy sie zalogowac." <<endl;
    }
}
