#include "Polynomial2.cpp"

//Methods for exercise 3
//This recursive function computes the n-th derivative of the polynomial
Polynomial Polynomial::differentiate(int order) const {
    if(order <= 0){
        return *this;
    }
    else{
        Polynomial copy = *this;
        for(int i = 1; i < copy.v.size(); i++){
            copy.v[i - 1].coeff = copy.v[i].coeff * copy.v[i].exp;
            copy.v[i].coeff = 0;
            copy.v[i - 1].exp = copy.v[i].exp - 1;
        }
        return copy.differentiate(order - 1);
    }
}