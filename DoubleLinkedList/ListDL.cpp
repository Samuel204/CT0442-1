#include "ListDL.h"

ListDL::ListDL() {
    head = nullptr;
    tail = nullptr;
}

ListDL::ListDL(const ListDL& s) {
    copy(s.head, s.tail);
}

void ListDL::copy(ListDL::Pcell h, ListDL::Pcell t) {
    head = nullptr;
    tail = nullptr;
    while(h != nullptr){
        append(h->info);
        h = h->next;
    }
}
void ListDL::append(int e) {
    Pcell nuova = new Cell;
    nuova->info = e;
    nuova->next = nullptr;
    nuova->prev = tail;
    if(tail != nullptr)
        tail->next = nuova;
    else
        head = nuova;
    tail = nuova;
}

void ListDL::print() const{
    Pcell pc = head;
    while(head != nullptr){
        std::cout<<pc->info<<std::endl;
        pc = pc->next;
    }
}

int& ListDL::at(int pos){
    if(pos >= 0){
        Pcell pc = head;
        while(pc != nullptr && pos > 0){
            pc = pc->next;
            pos--;
        }
        if(pc != nullptr)
            return pc->info;
        else
            throw std::out_of_range("posizione non valida"); // lancia eccezione
    }
    else{
        pos = -pos - 1;
        Pcell pc = tail;
        while(pc != nullptr && pos > 0){
            pc = pc->prev;
            pos--;
        }
        if(pc != nullptr)
            return pc->info;
        else
            throw std::out_of_range("posizione non valida"); // lancia eccezione
    }
}

bool ListDL::operator==(const ListDL& l) const{
    Pcell pc1 = head;
    Pcell pc2 = l.head;
    bool uguali = true;
    while(pc1 != nullptr && pc2 != nullptr && uguali){
        if(pc1->info != pc2->info)
            uguali = false;
        else{
            pc1 = pc1->next;
            pc2 = pc2->next;
        }
    }
    return (pc1 == pc2);
}

const ListDL ListDL::operator=(const ListDL &l) {
    if(this != &l){
        Pcell pc = head;
        while(pc != nullptr){
            pc = pc->next;
            delete head;
            head = pc;
        }
        head = nullptr;
        tail = nullptr;
        pc = l.head;
        while(pc != nullptr){
            append(pc->info);
            pc = pc->next;
        }
    }
    return *this;
}

ListDL ListDL::operator+(const ListDL &l) const {
    ListDL ris;
    Pcell pc = head;
    while(pc != nullptr){
        ris.append(pc->info);
        pc = pc->next;
    }
    pc = l.head;
    while(pc != nullptr){
        ris.append(pc->info);
        pc = pc->next;
    }
    return ris;
}

ListDL ListDL::operator*(unsigned int n) const{
    ListDL ris;
    for(int i = 0; i < n; i++){
        Pcell pc = head;
        while(pc!= head){
            ris.append(pc->info);
            pc = pc->next;
        }
    }
    return ris;
}


int main(){
    ListDL l1,l2;
    l1.append(2);
    l2.append(2);
    if(l1 == l2)
        std::cout<<"sono uguali"<<std::endl;
    else
        std::cout<<"sono diverse"<<std::endl;
}



