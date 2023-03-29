#include "list_int.h"

// METODI AGGIUNTI PRECEDENTEMENTE
List_int::List_int() {
    h = nullptr;
}

List_int::List_int(const List_int& source) {
    Pcell pc = source.h;
    h = nullptr;
    while(pc != nullptr){
        append(pc->info);
        pc = pc->next;
    }
}

List_int::~List_int(){
    Pcell pc = h;
    while(pc != nullptr){
        h = h->next;
        delete pc;
        pc = h;
    }
}

void List_int::prepend(int eL) {
    Pcell nuova = new Cell;
    nuova->info = eL;
    nuova->next = h;
    h = nuova;
}

void List_int::pre_pend(Pcell l, int el) {
    Pcell nuova = new Cell;
    nuova->info = el;
    nuova->next = h;
    h = nuova;
}

void List_int::append(int el) { // funzione cappello
    append_ric(h, el);
}

void List_int::append_ric(Pcell& testa, int el) {
    if(testa == nullptr){
        pre_pend(testa, el);
    }
    else{
        append_ric(testa->next, el);
    }
}

bool List_int::isempty() const {
    return (h == nullptr);
}

int& List_int::head() {
    return h->info;
}

const int& List_int::head() const {
    return h->info;
}

void List_int::print() const {
    print_ric(h);
}

void List_int::print_ric(Pcell testa) const{
    if(testa != nullptr){
        std::cout<<testa->info;
        print_ric(testa->next);
    }
}

int List_int::size() const{
    int res = 0;
    Pcell p = h;
    while(p != nullptr){
        res++;
        p = p->next;
    }
    return res;
}

// METODI AGGIUNTI POSTERIORMENTE
int List_int::deleteLast(int n) {
    return eliminaFondoRic(h,n);
}

int List_int::eliminaFondoRic(Pcell &l, int n) {
    if(l == nullptr) return 0;
    else{
        int deleted = eliminaFondoRic(l->next, n);
        if(deleted < n){
            delete l;
            l = nullptr;
            return deleted + 1;
        }
        else return n;


    }
}

void List_int::ribalta_ric(Pcell &p) {
    if(p != nullptr && p->next != nullptr){
        Pcell supp = p->next;
        ribalta_ric(supp);
        p->next->next = p;
        p->next = nullptr;
        p = supp;
    }
}