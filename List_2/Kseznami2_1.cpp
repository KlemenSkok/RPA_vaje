#include <iostream>
#include <cstring>

using namespace std;

/*
Napiši program C/C++, ki ustvari FIFO vrsto telefonskega imenika tvojih sošolcev 
(podatki: ime, priimek, GSM številko ter email). V seznam vnašamo vrednosti vse dokler 
uporabnik za ime ne vnese tipke Esc.  Programu dodaj funkcijo za izpis vseh podatkov v pravilnem
in v obratnem vrstnem redu vnosa,  funkcijo za iskanje določenega sošolca po imenu in priimku ter funkcijo, 
ki izbriše celoten seznam iz spomina.

FIFO == dodaj spredaj, brisi zadaj
*/

struct El {
    char ime[20], 
    priimek[30], 
    email[60], 
    gsm[9];
    struct El *prev, *next;
} *start = nullptr, *konc = nullptr;

void Push_front(struct El x) {
    struct El *tmp = new struct El;
    *tmp = x;
    if(start == nullptr) { //prazen seznam
        start = tmp;
        konc = tmp;
        start->next = nullptr;
        start->prev = nullptr;
    }
    else {
        start->prev = tmp;
        tmp->next = start;
        start = tmp;
        start->prev = nullptr;
    }
}

void Pop_back() {
    struct El *t = konc;
    if(start == nullptr) { //prazen seznam
        cout << "Seznam je prazen!\n";
    }
    else if(start == konc) { //v seznamu je le en element
        start = nullptr;
        konc = nullptr;
        delete t;
    }
    else {
        konc = konc->prev;
        konc->next = nullptr;
        delete t;
    }
}

void IzpisEl(struct El x) {
    cout << x.ime << " " << x.priimek << endl;
    cout << "GSM: " << x.gsm << endl;
    cout << "email: " << x.email << endl << endl;
}

void izpis_naprej() {
    struct El *tmp = start;
    while(tmp != nullptr) {
        IzpisEl(*tmp);
        tmp = tmp->next;
    }
    cout << endl;
}

void izpis_nazaj() {
    struct El *tmp = konc;
    while(tmp != nullptr) {
        IzpisEl(*tmp);
        tmp = tmp->prev;
    }
    cout << endl;
}

bool iskanjeEl(char ime[], char priimek[])  {
    struct El *tmp = start;
    while(tmp != nullptr) {
        if(strcmp(tmp->ime, ime) && strcmp(tmp->priimek, priimek))
            return true;
        tmp = tmp->next;
    }
    return false;
}

void Izbrisi_seznam() {
    while(start == nullptr)
        Pop_back();
}

int main() {

    while(true) {
        struct El x;
        cout << "ime: ";
        cin >> x.ime;
        if(x.ime[0] == 27) //vnesen je ESC
            break;
        cout << "priimek: ";
        cin >> x.priimek;
        cout << "GSM: ";
        cin >> x.gsm;
        cout << "email: ";
        cin >> x.email;
        Push_front(x);
    }
    cout << "IZPIS NAPREJ:\n";
    izpis_naprej();
    cout << "IZPIS NAZAJ:\n";
    izpis_nazaj();
    char ime[10] = "Klemen", priimek[10] = "Skok";
    cout << "Oseba Klemen Skok SE" << ((iskanjeEl(ime, priimek)) ? "" : " NE") << " nahaja v seznamu!\n";
    Izbrisi_seznam();

    return 0;
}