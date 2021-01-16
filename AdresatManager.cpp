#include "AdresatManager.h"

AdresatManager::AdresatManager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika):
    plikZAdresatami(nazwaPlikuZAdresatami),
    ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
}

void AdresatManager::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat)) {
        cout << "Pomyslnie dodano adresata." << endl;
    } else {
        cout << "Nie udalo sie dodac adresata." << endl;
    }
}

Adresat AdresatManager::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}

string AdresatManager::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }
    return tekst;
}

void AdresatManager::wyswietlWszystkichAdresatow() {

    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatManager::wyswietlDaneAdresata(Adresat adresat) {

    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdresatManager::znajdzPoImieniu() {
    int znalezionychOsob = 0;
    string szukaneImie;
    system("cls");
    cout << "Podaj imie szukanej osoby: ";
    getline(cin,szukaneImie);
    cout << endl;
    szukaneImie = zamienPierwszaLitereNaDuzaAPozostaleNaMale(szukaneImie);
    for (vector<Adresat>::iterator osoba = adresaci.begin(), zaOstatniaOsoba = adresaci.end(); osoba!=zaOstatniaOsoba; osoba++) {
        if (osoba->pobierzImie() == szukaneImie) {
            znalezionychOsob ++;
            wyswietlDaneAdresata(*osoba);
        }
    }
    cout << "Znalezionych wynikow: " <<znalezionychOsob << '.' <<endl;
    system("pause");
}

void AdresatManager::znajdzPoNazwisku() {
    int znalezionychOsob = 0;
    string szukaneNazwisko;
    system("cls");
    cout << "Podaj nazwisko szukanej osoby: ";
    getline(cin,szukaneNazwisko);
    cout << endl;
    szukaneNazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(szukaneNazwisko);
    for (vector<Adresat>::iterator osoba = adresaci.begin(), zaOstatniaOsoba = adresaci.end(); osoba!=zaOstatniaOsoba; osoba++) {
        if (osoba->pobierzNazwisko() == szukaneNazwisko) {
            znalezionychOsob ++;
            wyswietlDaneAdresata(*osoba);
        }
    }
    cout << "Znalezionych wynikow: " <<znalezionychOsob << '.' <<endl;
    system("pause");
}

int AdresatManager::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdresatManager::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzId() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl <<"Zamierzasz usunac:" <<endl;
            wyswietlDaneAdresata(*itr);
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("p       ause");
                return;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

void AdresatManager::edytujAdresata()
{
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    //int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl;
            wyswietlDaneAdresata(adresaci[i]);

            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                //adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                plikZAdresatami.edytujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                //adresaci[i].ustawnazwisko = zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko());
                plikZAdresatami.edytujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.edytujDaneWybranegoAdresata(adresaci[i]);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatManager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
