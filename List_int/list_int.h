#include <iostream>
#include <cstdlib>

class List_int {
    public:
        List_int();
        List_int(const List_int& s);
        ~List_int();
        void append(int e);
        void prepend(int e);
        bool isempty() const;
        int size() const;
        int& head(); // Pre: List not empty
        const int& head() const;
        void print() const;
    private:

        struct Cell{
            int info;
            Cell* next;
        };
        typedef Cell* Pcell;
        Pcell h;
        void append_ric(Pcell& testa, int e);
        void print_ric(Pcell testa) const;
};