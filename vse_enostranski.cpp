#include <iostream>

using namespace std;

struct El {
    int x;
    struct El *next;
} *start = nullptr;

void addFront(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) {
        start = tmp;
        start->next = nullptr;
    }
    else {
        tmp->next = start;
        start = tmp;
    }
}

void addBack(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) {
        start = tmp;
        start->next = nullptr;
    }
    else {
        struct El *t = start;
        while(t->next != nullptr) 
            t = t->next;
        t->next = tmp;
        tmp->next = nullptr;
    }
}

void Urejeni(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) {
        start = tmp;
        start->next = nullptr;
    } 
    else {
        struct El *curr = start, *prev = nullptr;
        while(curr != nullptr && tmp->x > curr->x) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == start) { //na zacetku
            tmp->next = start;
            start = tmp;
        }   
        else { //drugje
            tmp->next = curr;
            prev->next = tmp;
        }
    }
}

void Brisanje(int i) { //elementov manjsih od i
    if(start == nullptr) 
        cout << "Seznam je prazen!\n";
    else {
        struct El *curr = start, *prev = nullptr;
        while(curr != nullptr) {
            if(curr->x < i) { //bris
                if(curr == start) {
                    start = start->next;
                    delete curr;
                    curr = start;
                }
                else {
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }
            else {
                prev = curr; 
                curr = curr->next;
            }
        }
    }
}

int main() {



    return 0;
}