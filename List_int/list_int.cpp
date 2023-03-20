//
// Created by Simone Dinato on 20/03/23.
//

#include "list_int.h"

List_int::List_int() {
    h = nullptr;
}
void List_int::prepend(int l) {
    Cell* nuova = new Cell;
    nuova->info = l;
    nuova->next = h;
    h = nuova;
}

List_int::~List_int(){
    Cell* pc = h;
    while(pc != nullptr){
        h = h->next;
        delete pc;
        pc = h;
    }
}

List_int::List_int(const List_int &s) {
    Cell* pc = s.h;
    h = nullptr;
    while(pc != nullptr){
        append(pc->info);
        pc = pc->next;
    }
}