#include <cstdlib>
#include <iostream>

class ListDL {
    public:
        ListDL();
        ListDL(const ListDL& s);
        ~ListDL();
        void prepend(int e);
        void append(int e);
        void print() const;
        int& at(int pos);
        int& at(int pos) const;
        bool operator==(const ListDL& l) const;
        const ListDL operator=(const ListDL& l);
        ListDL operator+(const ListDL& l) const;
        ListDL operator*(unsigned int n) const;
    private:
        struct Cell {
            int info;
            Cell* next;
            Cell* prev;
        };
        typedef Cell* Pcell;
        Pcell head;
        Pcell tail;
        void copy(Pcell h, Pcell t);
};