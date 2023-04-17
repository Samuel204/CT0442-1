#include "DL String.h"

//Default constructor
ListStrings::ListStrings() {
  head = nullptr;
  tail = nullptr;
}


//Move constructor
ListStrings::ListStrings(ListStrings&& ls) {
      std::cout<<"Move costructor"<<endl;
      head = ls.head;
      tail = ls.tail;
      ls.head = nullptr;
      ls.tail = nullptr;
}

//stampa da head a tail
void ListStrings::print_forward() const{
  Cell* ptr=head;
  while (ptr) {
    cout<<ptr->info<<endl;
    ptr = ptr->next;
  }
}

//stampa da tail a head
void ListStrings::print_reversed() const{
  Cell* ptr=tail;
  while(ptr) {
    cout<<ptr->info<<endl;
    ptr=ptr->prev;
  }
}


// TO DO
ListStrings::~ListStrings() {
    Cell* supp = head;
    while(head){
        head = head->next;
        delete supp;
        supp = head;
    }
}

//TO DO
void ListStrings::add(const string& s) {

    Cell* supp = new Cell;
    supp->info = s;
    if(tail == nullptr){
        supp->next = nullptr;
        supp->prev = nullptr;
        head = supp;
        tail = supp;
    }
    else{
        Cell* aux = head;
        Cell* temp = new Cell;
        bool found = false;
        while(aux && !found){
            if(supp->info.compare(aux->info) <= 0){
                supp->next = aux;
                supp->prev = aux->prev;
                if(aux->prev != nullptr) aux->prev->next = supp;
                aux->prev = supp;
                if(supp->prev == nullptr) head = supp;
                found = true;
            }
            temp = aux;
            aux = aux->next;
        }
        if(!found){

            temp->next = supp;
            tail = supp;
            supp->prev = temp;
            supp->next = nullptr;
        }
    }
}
