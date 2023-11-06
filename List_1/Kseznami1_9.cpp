#include <iostream>

using namespace std;

/*
Napiši program, ki ustvari dvostransko povezani seznam s ključi
(vrednostmi) elementov {12, 4,5, 19, 13} in izbriše element s ključem 5.
*/

struct El {
    int x;
    struct El *prev, *next;
} *start = nullptr, *konec = nullptr;

void Dodaj_zadaj(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) { //seznam je prazen
        start = tmp;
        konec = tmp;
        start->next = nullptr;
        start->prev = nullptr;
    }
    else { //seznam ni prazen
        konec->next = tmp;
        tmp->prev = konec;
        tmp->next = nullptr;
        konec = tmp;
    }
}

void Brisi_vrednost(int a) {
    struct El *t = start;
    if(start == nullptr) { //seznam je prazen
        cout << "Seznam je prazen!\n";
    }
    else {
        while(t != nullptr && t->x != a) {
            t = t->next;
        }
        if(t == start) { //na zacetku seznama
            if(start == konec) { //edini element v seznamu
                start = nullptr;
                konec = nullptr;
                delete t;
            }
            else { //ni edini
                start = start->next;
                start->prev = nullptr;
                delete t;
            }
        }
        else if(t == konec) { // na koncu seznama
            konec = konec->prev;
            konec->next = nullptr;
            delete t;
        }
        else if(t != nullptr) { //drugje v seznamu
            t->prev->next = t->next;
            t->next->prev = t->prev;
            delete t;
        }
        else { //element ni bil najden
            cout << "Elementa ni v seznamu!\n";
        }
    }
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

    Dodaj_zadaj(12);
    Dodaj_zadaj(4);
    Dodaj_zadaj(5);
    Dodaj_zadaj(19);
    Dodaj_zadaj(13);
    izpis();
    Brisi_vrednost(5);
    izpis();

    return 0;
}