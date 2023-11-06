#include <iostream>
#include <cstring>

using namespace std;

// 6. Napiši program, ki ustvari enostransko povezani urejen seznam iz elementov, ki vsebujejo ime, priimek in višino.

struct El {
    char ime[20], priimek[30];
    int visina;
    struct El *next;
} *start = nullptr;

void Urejen(struct El a) { // od manjsega proti vecjemu
    struct El *tmp = new struct El;
    *tmp = a;
    if(start == nullptr) {
        start = tmp;
        tmp->next = nullptr;
    }
    else {
        struct El *prev = nullptr, *curr = start;
        while(curr != nullptr && curr->visina < tmp->visina) {
            prev = curr;
            curr = curr->next;
        }
        if(curr == start) {
            tmp->next = start;
            start = tmp;
        }
        else {   
            tmp->next = curr;
            prev->next = tmp;
        }
    }
}

void Izpis() {
    struct El *tmp = start;
    while(tmp != nullptr) {
        cout << tmp->visina << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int stetjeEl();
bool iskanjeEl();
void brisanjeEl();

int main() {

    brisanjeEl();
    for(int i = 0; i < 10; i++) {
        struct El x;
        cin >> x.visina;
        //fgets(x.ime, 20, stdin);
        //fgets(x.priimek, 30, stdin);
        Urejen(x);
    }
    Izpis();
    cout << "Stevilo elementov: " << stetjeEl() << endl;
    brisanjeEl();
    Izpis();
    cout << "Stevilo elementov: " << stetjeEl() << endl;
    
    //system("pause");
    return 0;
}
   
//      7. Za program iz prejšnje naloge napiši funkcije za:
//        ◦ štetje elementov
//        ◦ iskanje elementa (preveri, če se nahaja v seznamu)
//        ◦ brisanje tistih elementov, ki imajo vrednost večjo od 170

int stetjeEl() {
    struct El *tmp = start;
    int n = 0;
    while(tmp != nullptr) {
        n++;
        tmp = tmp->next;
    }
    return n;
}

bool iskanjeEl(int iskano) { // po visini
    struct El *tmp = start;
    while(tmp != nullptr) {
        if(tmp->visina == iskano)
            return true;
        tmp = tmp->next;
    }
    return false;
}

void brisanjeEl() { // po visini, vse vecje od 170
    struct El *prev = nullptr, *curr = start;
    if(start == nullptr) {
        cout << "Seznam je prazen!\n";
    }
    else {
        while(curr != nullptr) {
            if(curr->visina > 170) { //brisi
                if(curr == start) { //je na zacetku seznama
                    start = start->next;
                    delete curr;
                    curr = start;
                }
                else { //je drugje v seznamu
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
            }
            else { //premakni se naprej
                prev = curr;
                curr = curr->next;
            }
        }
    }
}