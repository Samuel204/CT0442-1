#include "List_int.h"

int main(){
    List_int l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.prepend(0);
    l.stampa();
    return 0;
}