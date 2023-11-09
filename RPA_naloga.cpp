#include <iostream>
#include <ctime>

using namespace std;

/*
Naloga od teorije
    Ustvari dvostransko povezani urejeni seznam, ki vsebuje podatke o računalnikih.
    Ti podatki so naziv, hitrost in velikost RAM.
    Dodaj funkcijo, ki pobriše vse računalnike, ki imajo manj RAM od prebranega števila.
    Seznam na bo urejen po velikosti RAM naraščajoče
*/

struct Rac {
    string naziv;
    float RAM, hitrost;
};

struct El {
    struct Rac x;
    struct El *prev, *next;
} *start = nullptr, *konc = nullptr;

void Urejen(struct Rac a) {
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
        while(t != nullptr && tmp->x.RAM > t->x.RAM)
            t = t->next;
        if(t == start) { //na zacetku
            tmp->next = start;
            start->prev = tmp;
            start = tmp;
            start->prev = nullptr;
        }
        else if(t == nullptr) { //na koncu
            tmp->prev = konc;
            konc->next = tmp;
            konc = tmp;
            konc->next = nullptr;
        }
        else { //nekje vmes
            tmp->next = t;
            tmp->prev = t->prev;
            tmp->prev->next = tmp;
            tmp->next->prev = tmp;
        }
    }
}

void Brisi_po_RAM(float a) {
    struct El *t = start;
    if(start == nullptr)
        cout << "Prazen seznam!\n";
    else {
        while(t != nullptr) {
            if(t->x.RAM < a) { //brisi ce je RAM manjsi od a
                if(t == start) {
                    if(start != konc) {
                        start = start->next;
                        start->prev = nullptr;
                        delete t;
                        t = start; //postavi nazaj na zacetek za nadaljevanje
                    }
                    else {
                        start = nullptr;
                        konc = nullptr;
                        delete t;
                        t = nullptr; //seznam je prazen, zato gre zapusti loop
                    }
                }
                else if(t == konc) { // je na koncu
                    konc = konc->prev;
                    konc->next = nullptr;
                    delete t;
                    t = nullptr; //dosegel konec seznama, zato zapusti loop
                }
                else { //je nekje vmes
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    struct El *tmp_ptr = t->next;
                    delete t;
                    t = tmp_ptr;
                }
            }
            else { //drugace se premakni naprej
                t = t->next;
            }
        }
    }
}

void Brisi_po_GHz(float a) {
    struct El *t = start;
    if(start == nullptr)
        cout << "Prazen seznam!\n";
    else {
        while(t != nullptr) {
            if(t->x.hitrost < a) { //brisi ce je RAM manjsi od a
                if(t == start) {
                    if(start != konc) {
                        start = start->next;
                        start->prev = nullptr;
                        delete t;
                        t = start; //postavi nazaj na zacetek za nadaljevanje
                    }
                    else {
                        start = nullptr;
                        konc = nullptr;
                        delete t;
                        t = nullptr; //seznam je prazen, zato gre zapusti loop
                    }
                }
                else if(t == konc) { // je na koncu
                    konc = konc->prev;
                    konc->next = nullptr;
                    delete t;
                    t = nullptr; //dosegel konec seznama, zato zapusti loop
                }
                else { //je nekje vmes
                    t->prev->next = t->next;
                    t->next->prev = t->prev;
                    struct El *tmp_ptr = t->next;
                    delete t;
                    t = tmp_ptr;
                }
            }
            else { //drugace se premakni naprej
                t = t->next;
            }
        }
    }
}

// ta funkcija se premika po seznamu le dokler je v obsegu dolocenega parametra (manjsa od a) in izbrise vsak element
void Brisi_RAM_odZacetka(float l, float h) {
    struct El *t = start;
    if(start == nullptr)
        cout << "Prazen seznam\n";
    else if(l >= h)
        cout << "Nepravilni parametri!\n";
    else {
        while(t != nullptr && t->x.RAM < h) {
            if(t->x.RAM > l) {
                if(t == start) {
                    if(start != konc) {
                        start = start->next;
                        start->prev = nullptr;
                        delete t;
                        t = start;                    
                    }
                    else { // edini element
                        start = nullptr;
                        konc = nullptr;
                        delete t;
                        t = nullptr; //da zapusti loop
                    }
                }
                else if(t == konc) { //na koncu
                    konc = konc->prev;
                    konc->next = nullptr;
                    delete t,
                    t = nullptr;
                }
                else { //nekje vmes
                    t->next->prev = t->prev;
                    t->prev->next = t->next;
                    struct El *tmp_ptr = t->next;
                    delete t;
                    t = tmp_ptr;
                }
            }
            else { //ni še dosegel želenega intervala, premakni se naprej
                t = t->next;
            }
        }
    }
}

void izpis() {
    struct El *tmp = start;
    while(tmp != nullptr) {
        cout << tmp->x.RAM << ", ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {

    float stevilo1, stevilo2;
    cin >> stevilo1;
    cin >> stevilo2;
    srand(time(NULL));

    for(int i = 0; i < 15; i++)
        Urejen({"AA", (float)(rand()%1000+1), (float)(rand()%1000+1)});

    izpis();
    //Brisi_po_RAM(stevilo);
    Brisi_RAM_odZacetka(stevilo1, stevilo2);
    izpis();

    system("pause");
    return 0;
}