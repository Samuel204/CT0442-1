#include "list_int.h"

List_int::List_int() {
    h = nullptr;
}

List_int::List_int(const List_int& s) {
    Pcell pc = s.h;
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

void List_int::prepend(int e) {
    Pcell nuova = new Cell;
    nuova->info = e;
    nuova->next = h;
    h = nuova;
}

void List_int::append(int e) { // funzione cappello
    append_ric(h, e);
}

void List_int::append_ric(Pcell& testa, int e) {
    if(testa == nullptr){
        testa = new Cell;
        testa->info = e;
        testa->next = nullptr;
    }
    else{
        append_ric(testa->next, e);
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