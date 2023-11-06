#include <iostream>

using namespace std;

struct El {
    char a;
    struct El *next;
} *start = nullptr;

void Push(char a) {
    struct El *tmp = new struct El;
    tmp->a = a;
    if(start == nullptr) {
        tmp->next = nullptr;
        start = tmp;
    }
    else {
        tmp->next = start;
        start = tmp;
    }
}

void Pop() {
    struct El *tmp = start;
    if(start == nullptr)
        cout << "Seznam je prazen!\n";
    else {
        start = start->next;
        delete tmp;
    }
}

void Pop_n(int x) { //brisanje iz dolocenega indeksa (1-indexed)
    struct El *tmp = start, *prev = nullptr;
    int n = 1;
    if(start == nullptr)
        return;
    while(n < x && tmp != nullptr) {
        prev = tmp;
        tmp = tmp->next;
        n++;
    }
    if(tmp == nullptr) // elementa ni v tabeli
        return;
    prev->next = tmp->next;
    delete tmp;
}

int st_znakov() {
    struct El *tmp = start;
    int n = 0;
    if(start == nullptr)
        return 0;
    while(tmp != nullptr) {
        n++;
        tmp = tmp->next;
    }
    return n;
}

void izpis() {
    struct El *tmp = start;
    while(tmp != nullptr) {
        cout << tmp->a << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
//3.b
bool isci(char q) {
    struct El *tmp = start;
    while(tmp != nullptr) {
        if(tmp->a == q)
            return true;
        tmp = tmp->next;
    }
    return false;
}
//3.a
void izpis_obratno(struct El *tmp) {
    if(tmp->next != nullptr)
        izpis_obratno(tmp->next);
    cout << tmp->a << " ";
}

int main() {

    char vnos;
    for(int i = 0; i < 10; i++) {
        cin >> vnos;
        Push(vnos);
    }
    izpis();
    cout << "Znak 'X' " << ((isci('X')) ? "je" : "ni") << " v seznamu!\n\n"; 
    cout << "OBRATEN IZPIS: \n";
    izpis_obratno(start);
    cout << "\n\n";
    Pop_n(5);
    izpis();
    Pop_n(5);
    izpis();
    while(st_znakov() > 0) {
        Pop();
        izpis();
    }

    system("pause");
    return 0;
}