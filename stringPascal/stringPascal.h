#ifndef CT0442_1_STRINGPASCAL_H
#define CT0442_1_STRINGPASCAL_H

#endif //CT0442_1_STRINGPASCAL_H
#include <iostream>
#include <string>

/*
 * un costruttore è un metodo che viene chiamato ogni volta
 * che si istanzia un oggetto di quella classe
 */

using namespace std;

class stringPascal{
    public:
        stringPascal(); // default constructor
        stringPascal(const string& s);
        stringPascal(const stringPascal& s); //copy constructor
        void print();
        void set(const string& s);
        void setchar(int pos, char c);
        string getchar(int pos);
        void setsize(int dim);
    private:
        unsigned char buff[256];
};

