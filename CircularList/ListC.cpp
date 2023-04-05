#include <iostream>
#include <cstdlib>

struct Cell{
    int info;
    Cell* next;
};
typedef Cell* ListaCirc;

void print(ListaCirc l){
    if(l != nullptr){
        ListaCirc start = l;
        do{
            l = l->next;
            std::cout<<l->info<<std::endl;
        }while(l != start);
    }
}

int main(){
    
    return 0;
}
