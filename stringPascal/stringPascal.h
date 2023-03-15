#ifndef CT0442_1_STRINGPASCAL_H
#define CT0442_1_STRINGPASCAL_H




#endif //CT0442_1_STRINGPASCAL_H
#include <iostream>
#include <cstring>
using namespace std;

class stringPascal{
    public:
        stringPascal(); // default constructor
        stringPascal(const string& s);
        stringPascal(char* s);
        char& at(int pos);
        stringPascal(const stringPascal& copy); //copy constructor
        ~stringPascal(); // distruttore
        void print() const; // il metodo print non modifica lo stato della classe
        void set(const string& s);
        void setchar(int pos, char c);
        string getchar(int pos);
        void setsize(int dim);
    private:
        unsigned char buff[256];
};

/*
 * un costruttore è un metodo che viene chiamato ogni volta
 * che si istanzia un oggetto di quella classe
 */


