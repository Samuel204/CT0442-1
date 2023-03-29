#include <iostream>
#include <cstdlib>

class List_int {
    public:
        List_int();

        List_int(const List_int& source);
        ~List_int();
        void append(int el);
        void prepend(int el);

        bool isempty() const;
        int size() const;
        int& head(); // Pre: List not empty
        const int& head() const;
        void print() const;

        //METODI AGGIUNTI POSTERIORMENTE
        List_int(int el);
        std::string convert_to_string() const;
        void tail(List_int& res);
        int& first();
        const int& first() const;
        bool equal(const List_int& l) const;
        void concat(List_int& l);
        List_int& operator=(const List_int& source);
        int deleteLast(int n);


    private:
        struct Cell{
            int info;
            Cell* next;
        };
        typedef Cell* Pcell;
        Pcell h;
        void append_ric(Pcell& testa, int el);
        void print_ric(Pcell testa) const;

        //CAMPO AGGIUNTO POSTERIORMENTE
        Pcell last;
        int  eliminaFondoRic(Pcell& l, int n);
        void pre_pend(Pcell l, int el);
        void ribalta_ric(Pcell&p);
};