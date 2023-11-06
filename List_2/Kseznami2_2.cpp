#include <iostream>

using namespace std;

/*
    2. Napiši funkcije za delo z vrsto tipa FILO (first in, last out) za:
        ◦ dodajanje znakov (ti se naj berejo s tipkovnice) v vrsto
        ◦ brisanje znakov s prvega mesta seznama
        ◦ brisanje znakov iz določenega mesta v seznamu
        ◦ štetje znakov
Opomba: vedno dodajamo na začetek seznama, komponente seznama na koncu še izbrišite iz pomnilnika
*/

/*
FILO == stack; dodaš in brišeš spredaj
*/

struct El {
    char x;
    struct El *prev, *next;
} *start = nullptr, *konc = nullptr;

void addEl(char a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) { //prazen seznam
        start = tmp;
        konc = tmp;
        start->prev = nullptr;
        start->next = nullptr;
    }
    else {
        start->prev = tmp;
        tmp->next = start;
        start = tmp;
        start->prev = nullptr;
    }
}

void brisZacetek() {
    struct El *t = start;
    if(start == nullptr) { //seznam je prazen
        cout << "Seznam je prazen!\n";
    }
    else if(start == konc) { //edini v seznamu
        start = nullptr;
        konc = nullptr;
        delete t;
    }
    else {
        start = start->next;
        start->prev = nullptr;
        delete t;
    }
}

void brisMesto(int indeks) {
    struct El *t = start;
    if(start == nullptr) {
        cout << "Prazen seznam!\n";
    }
    else {
        while(t != nullptr && indeks > 1){
            t = t->next;
            indeks--;
        }
        if(t != nullptr) { //element najden
            if(t == start) { //prvi element
                if(start == konc) { //edini element
                    start = nullptr;
                    konc = nullptr;
                    delete t;
                }
                else { // ni edini
                    start = start->next;
                    start->prev = nullptr;
                    delete t;
                }
            }
            else if(t == konc) { //zadnji element
                konc = konc->prev;
                konc->next = nullptr;
                delete t;
            }   
            else {
                t->next->prev = t->prev;
                t->prev->next = t->next;
                delete t;
            }
        }
        else {
            cout << "Ni elementa s tem indeksom.\n";
        }
    }
}

int stetjeEl() {
    struct El *tmp = start;
    int n = 0;
    while(tmp != nullptr) {
        n++;
        tmp = tmp->next;
    }
    return n;
}

void izpis() {
    struct El *tmp = start;
    while(tmp != nullptr) {
        cout << tmp->x << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {

    addEl('A');
    addEl('B');
    addEl('C');
    addEl('D');
    addEl('E');
    addEl('F');
    izpis();
    //brisZacetek();
    //izpis();
    brisMesto(6);
    izpis();

    return 0;
}