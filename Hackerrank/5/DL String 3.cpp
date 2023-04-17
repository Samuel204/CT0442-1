#include "DL String 2.cpp"

ListStrings ListStrings::operator+(const ListStrings& ls) const {
    ListStrings s3;
    Cell* pc = head;
    Cell* aux = ls.head;
    while(aux != nullptr && pc != nullptr){
        if(aux->info.compare(pc->info) <= 0){
            s3.add(aux->info);
            aux = aux->next;
        }
        else{
            s3.add(pc->info);
            pc = pc->next;
        }

    }
    if(aux == nullptr){
        while(pc){
            s3.add(pc->info);
            pc = pc->next;
        }
    }
    else{
        while(aux){
            s3.add(aux->info);
            aux = aux->next;
        }
    }
    return s3;
}