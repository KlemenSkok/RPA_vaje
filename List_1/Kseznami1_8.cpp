#include <iostream>

using namespace std;

/*
Napišite zaporedje ukazov, ki ustvarijo enostransko povezan seznam
s ključi elementov {12, 4, 5, 19, 13} in iz seznama izbrišejo element s ključem {4}
*/

struct El {
    int x;
    struct El *next;
} *start = nullptr;

void Dodaj_zadaj(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) { //prazen seznam
        start = tmp;
        start->next = nullptr;
    }
    else {
        struct El *t = start;
        while(t->next != nullptr) {
            t = t->next;
        }
        t->next = tmp;
        tmp->next = nullptr;
    }
}

void Brisi_kljuc(int a) {
    struct El *prev = nullptr, *curr = start;
    if(start == nullptr)
        cout << "Seznam je prazen!\n";
    else {
        while(curr != nullptr && curr->x != a) {
            prev = curr;
            curr = curr->next;
        }
        if(curr != nullptr) { //element je v seznamu
            if(curr == start) { //element je na zacetku seznama
                start = start->next;
                delete curr;
            }
            else {
                prev->next = curr->next;
                delete curr;
            }
        }
        else { //elementa ni v seznamu
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
    Brisi_kljuc(4);
    izpis();


    return 0;
}