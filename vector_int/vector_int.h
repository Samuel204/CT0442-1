#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;

class Vector_int {
    public:
        Vector_int();
        Vector_int(const Vector_int& l);
        ~Vector_int();
        void append(int e);
        void prepend(int e);
        bool isempty() const;
        int size() const;
        int& head(); // Pre: List not empty
        const int& head() const;
        void print() const;
    private:
        vector<int> v;
};
