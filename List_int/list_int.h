//
// Created by Simone Dinato on 20/03/23.
//

#ifndef CT0442_1_LIST_INT_H
#define CT0442_1_LIST_INT_H
#include <iostream>
#include <cstdlib>

class List_int {
    public:
        List_int();
        List_int(const List_int& s);
        ~List_int();
        void append(int l);
        void prepend(int l);
        bool isempty() const;
        int& head();
        const int& head() const;
        void print() const;
    private:
        struct Cell{
            int info;
            Cell* next;
        };
        Cell* h;
};


#endif //CT0442_1_LIST_INT_H
