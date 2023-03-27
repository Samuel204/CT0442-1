#include <iostream>
#include <vector>
#include <cstdlib>
class List_int {
    public:
        List_int();
        List_int(const List_int& l);
        ~List_int();
        void append(int el);
        void prepend(int el);
        void stampa() const;
    private:
        struct Impl;
        Impl* pimpl;
};


