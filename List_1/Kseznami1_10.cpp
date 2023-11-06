#include <iostream>

using namespace std;

/*
    10. Napiši funkcije za delo z vrsto tipa FIFO (first in, first out) za:
            a) dodajanje elementa v vrsto
            b) brisanje elementa 
            c) štetje elementov
//vedno dodajamo na začetek seznama, brišemo vedno zadnji element seznama
//komponente seznama sami podajte 
*/

struct El {
    int x;
    struct El *prev, *next;
} *start = nullptr, *konc = nullptr;

void Push_front(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) { //seznam je prazen
        start = tmp;
        konc = tmp;
        start->prev = nullptr;
        start->next = nullptr;
    }
    else { //seznam ni prazen
        tmp->next = start;
        start->prev = tmp;
        start = tmp;
        start->prev = nullptr;
    }
}

void Pop_back() {
    struct El *t = konc;
    if(start == nullptr) { //seznam je prazen
        cout << "Seznam je prazen!\n";
    }
    else if(start == konc) { //v seznamu je en element
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

    Push_front(23);
    izpis();
    Push_front(3);
    izpis();
    Push_front(6);
    izpis();
    Push_front(1);
    izpis();
    Push_front(69);
    izpis();
    Pop_back(); cout << "Pop!\n";
    izpis();
    cout << "V seznamu je " << stetjeEl() << " elementov.\n";
    Pop_back(); cout << "Pop!\n";
    izpis();


    return 0;
}