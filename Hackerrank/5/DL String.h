#include<iostream>
#include<string>

using namespace std;

/*Classe lista di stringhe ordinate alfabeticamente in modo
 * crescente. La lista e' doppiamente concatenata*/

class ListStrings{
    public:
          ListStrings();
          ListStrings(ListStrings&& ls);
          ~ListStrings();
          void print_forward() const;
          void print_reversed() const;
          void add(const string& s);
          ListStrings& operator=(const ListStrings& ls);
          ListStrings operator+(const ListStrings& ls) const;
    private:
          struct Cell{
            string info;
            Cell* next;
            Cell* prev;
          };
          Cell* head; //puntatore alla prima cella
          Cell* tail; //puntatore all'ultima cella
};

