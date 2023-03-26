#include "vector_int.h"

Vector_int::Vector_int() {}

Vector_int::Vector_int(const Vector_int& l) {
    v = l.v;
}

Vector_int::~Vector_int() {}

void Vector_int::prepend(int e) {
    v.resize(v.size() + 1);
    for(int i = v.size() - 1; i >0; i--)
        v.at(i) = v.at(i - 1);
    v.at(0) = e;
}

void Vector_int::append(int e) { // funzione cappello

}

bool Vector_int::isempty() const {
    return v.size() == 0;
}

int& Vector_int::head() {
    return v.at(0);
}

const int& Vector_int::head() const {
    return v.at(0);
}

int Vector_int::size() const{
    return v.size();
}