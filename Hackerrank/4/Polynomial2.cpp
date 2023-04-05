#include "Polynomial1.cpp"

//Methods for exercise 2
//Returns the degree of a polynomial. The polynomial 0 has degree 0
int Polynomial::degree() const{
    int max = 0;
    for(auto e: v){
        if(e.exp > max) max = e.exp;
    }
    return max;
}