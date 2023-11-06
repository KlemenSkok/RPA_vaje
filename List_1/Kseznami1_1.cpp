#include <iostream>
#include <ctime>

using namespace std;

struct El {
    int x;
    struct El *next;
} *start = nullptr;

void Dodaj_zadaj(int a) {
    struct El *tmp = new struct El;
    tmp->next = nullptr;
    tmp->x = a;
    if(start == nullptr)
        start = tmp;    
    else {
        struct El *t = start;
        while(t->next != nullptr)
            t = t->next;
        t->next = tmp;
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

float povpr() {
    struct El *tmp = start;
    int sum = 0;
    while(tmp != nullptr) {
        sum += tmp->x;
        tmp = tmp->next;
    }
    return (float)sum / 10.0;
}

int izbris() {
    struct El *tmp = start;
    if(start == nullptr)
        return 1;
    start = start->next;
    delete tmp;
    return 0;
}

int main() {

    srand(time(NULL));
    for(int i = 0; i < 10; i++)
        Dodaj_zadaj(rand()%35 + 21); // (20, 55] -> [21, 56)
    izpis();

    cout << "Povprecje elementov v tabeli je " << povpr() << endl;

    while(!izbris());
    izpis();

    system("pause");
    return 0;
}