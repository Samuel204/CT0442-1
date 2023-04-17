#include "DL String 1.cpp"

ListStrings& ListStrings::operator=(const ListStrings& ls) {
    if(this != &ls){
        Cell* pc = head;
        while(head){
            head = head->next;
            delete pc;
            pc = head;
        }
        head = nullptr;
        tail = nullptr;
        Cell* supp = ls.head;
        while(supp){
            pc = new Cell;
            pc->info = supp->info;
            pc->next = nullptr;
            pc->prev = tail;
            if(tail != nullptr){
                tail->next = pc;
            }
            else{
                head = pc;
            }
            tail = pc;
            supp = supp->next;
        }
    }
    return *this;
}