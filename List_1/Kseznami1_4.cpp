#include <iostream>

using namespace std;

struct El {
    int x;
    struct El *next;
} *start = nullptr;

void Push(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    tmp->next = start;
    start = tmp;
}

void DodajKonec(int a) {
    struct El *tmp = new struct El;
    tmp->x = a;
    if(start == nullptr) {
        start = tmp;
        tmp->next = nullptr;
    }
    else {
        struct El *t = start;
        while(t->next != nullptr)
            t = t->next;
        t->next = tmp;
        tmp->next = nullptr;
    }
}

void branje() {
    int vnos;
    while(true) {
        cin >> vnos;
        if(vnos == -1)
            break;
        else if(vnos == 0)
            Push(0);
        else Push(1);
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

int desetisko() {
    int multiplier = 1;
    int num = 0;
    struct El *tmp = start;
    while(tmp != nullptr) {
        num += tmp->x * multiplier;
        multiplier *= 2;
        tmp = tmp->next;
    }
    return num;
}

/* string osmisko() {
    struct El *tmp = start;
    int multiplier = 1, sum = 0;
    string num = "";
    for(int i = 0; tmp != nullptr; i++) {
        if(multiplier >= 3) {
            multiplier = 1;
            num += sum + '0';
            sum = 0;
        }
        sum += tmp->x * multiplier;
        tmp = tmp->next;
        multiplier++;
    }
    return num;
} */

int main() {

    branje();
    izpis();

    printf("Desetiska vrednost: %d\n", desetisko());
    //cout << "Osmiska vrednost: " << osmisko() << endl;

    system("pause");
    return 0;
}