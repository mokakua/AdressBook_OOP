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

void KsiazkaAdresowa::wyswietlMenu() {
    if (!uzytkownikManager.czyUzytkownikZalogowany()) {
        KsiazkaAdresowa::wyswietlMenuStartowe();
        KsiazkaAdresowa::wywolajFunkcjeStartowe();
    } else {
        KsiazkaAdresowa::wyswietlMenuGlowne();
        KsiazkaAdresowa::wywolajFunkcjeGlowne();
    }
}

void KsiazkaAdresowa::wyswietlMenuStartowe() {
    system("cls");
    cout << "1. Logowanie" <<endl;
    cout << "2. Rejestracja" <<endl;
    cout << "9. Zamknij program" <<endl <<endl;
    cout << "Twoj wybor: ";
}
void KsiazkaAdresowa::wywolajFunkcjeStartowe() {
    char wybor;
    wybor = pobierzZnak();
    switch(wybor) {
    case '1': {
        logowanieUzytkownika();
    }
    break;
    case '2': {
        rejestracjaUzytkownika();
    }
    break;
    case '9': {
        system("cls");
        exit(0);
    }
    break;
    }
}

void KsiazkaAdresowa::wyswietlMenuGlowne() {
    //int ileOsob = osoby.end()-osoby.begin();
    system("cls");
    cout << "KSIAZKA ADRESOWA" <<endl;
    //cout << "(Zarejestrowanych wpisow: " << ileOsob <<')' <<endl;
    cout << "1. Dodaj adresata." <<endl;
    cout << "2. Wyszukaj po imieniu." <<endl;
    cout << "3. Wyszukaj po nazwisku." <<endl;
    cout << "4. Wyswietl wszystkich adresatow." <<endl;
    cout << "5. Usun adresata." <<endl;
    cout << "6. Edytuj adresata." <<endl;
    cout << "7. Zmien haslo." <<endl;
    cout << "9. Wyloguj" <<endl <<endl;
    cout << "Twoj wybor: ";
}


void KsiazkaAdresowa::wywolajFunkcjeGlowne() {
    char wybor;
    wybor = pobierzZnak();
    switch(wybor) {
    case '1': {
        dodajAdresata();
    }
    break;
    case '2': {
        //znajdzPoImieniu(osoby);
    }
    break;
    case '3': {
        //znajdzPoNazwisku(osoby);
    }
    break;
    case '4': {
        //wypiszListe(osoby);
    }
    break;
    case '5': {
        //usunAdresata(osoby, ostatnieUzyteIdOsoby);
    }
    break;
    case '6': {
        //edytujAdresata(osoby);
    }
    break;
    case '7': {
        zmianaHaslaZalogowanegoUzytkownika();
    }
    break;
    case '9': {
        wylogowanieUzytkownika();
    }
    break;
    }
}

char KsiazkaAdresowa::pobierzZnak() {
    string wejscie = "";
    getline(cin,wejscie);
    char znak = 0;
    if (wejscie.length() == 1) {
        znak = wejscie[0];
    } else {
        cout << "Za duzo znakow. Podaj prawidlowa liczbe."<<endl;
        Sleep(1000);
    }
    return znak;
}

