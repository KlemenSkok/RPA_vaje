#include <iostream>

using namespace std;

struct El {
    int x;
    struct El *prev, *next;
} *start = nullptr, *konc = nullptr;

void addFront(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) {
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

void addBack(int a) {
    struct El *tmp = new struct El;
    if(start == nullptr) {
        start = tmp;
        konc = tmp;
        start->prev = nullptr;
        start->next = nullptr;
    }
    else {
        konc->next = tmp;
        tmp->prev = konc;
        konc = tmp;
        konc->next = nullptr;
    }
}

void Urejeni(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) {
        start = tmp;
        konc = tmp;
        start->prev = nullptr;
        start->next = nullptr;
    }
    else {
        struct El *t = start;
        while(t != nullptr && tmp->x > t->x) 
            t = t->next;
        if(t == start) { //na koncu
            start->prev = tmp;
            tmp->next = start;
            start = tmp;
            start->prev = nullptr;
        }
        else if(t == nullptr) { //na koncu
            konc->next = tmp;
            tmp->prev = konc;
            konc = tmp;
            konc->next = nullptr;
        }
        else {
            tmp->next = t;
            tmp->prev = t->prev;
            tmp->next->prev = tmp;
            tmp->prev->next = tmp;
        }
    }
}

void Brisi(int a) { //eno vrednost, enako a
    if(start == nullptr) 
        cout << "Seznam je prazen!\n";
    else {
        struct El *t = start;
        while(t != nullptr && t->x != a)
            t = t->next;
        if(t == start) {//na zacetku
            if(start == konc) {//edini element
                start = nullptr;
                konc = nullptr;
                delete t;
            }
            else {//ni edini
                start = start->next;
                start->prev = nullptr;
                delete t;
            }
        }
        else if(t == konc) {//na koncu
            konc = konc->prev;
            konc->next = nullptr;
            delete t;
        }
        else if(t != nullptr) {//drugje v seznamu
            t->prev->next = t->next;
            t->next->prev = t->prev;
            delete t;
        }
        else
            cout << "elementa ni v seznamu!\n";
    }
}

int main() {



    return 0;
}