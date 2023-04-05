#include "Polynomial.h"
//////// Pre-implemented part/////////////
//Do not change this method! It reads a Polynomial
void Polynomial::read() {
  int coeff, exponent;
  do {
    std::cin>>exponent;
    if (exponent>=0)  {
      std::cin>>coeff;
      set(exponent, coeff);
    }
  } while (exponent>=0);
}


//Do not change this method! It prints a Polynomial
void Polynomial::print() const {
  int n = degree();

  for (int i=0; i<=n; i++) {
    if (at(i)!=0)
      std::cout<<"+("<<at(i)<<")x^"<<i;
  }
  std::cout<<std::endl;
}



//Do not change this method! It simply computes the integer power
//It could be useful!
int Polynomial::intpow(int base, int exponent) const {
  int res=1;

  while (exponent>0) {
    res = res*base;
    exponent--;
  }
  return res;
}


//Methods for exercise 1

//Default constructor: builds the polynomial 0
Polynomial::Polynomial() {
    set(0,0);
}

//Copy constructor
Polynomial::Polynomial(const Polynomial& p) {
    v = p.v;
}

//Returns the coefficient of the terms  x^exponent
//If it has not been added it returns 0
//Notice that we have only one version of at
//It does not return a reference, just an int. So we can only read with at!
int Polynomial::at(int exponent) const {
    return v[exponent].coeff;
}

//Set to coeff the coefficient of x^exponent. If this is present,
//it will be overwritten. Setting the coefficient to 0 means
//the removal from the polynomial representation
void Polynomial::set(int exponent, int coeff) {
    if(v.size() <= exponent){
        v.resize(exponent + 1);
    }
    for(int i = 0; i <= v.size(); i++){
        if(i == exponent){
            v[i].coeff = coeff;
            v[i].exp = exponent;
            //v.at(i).coeff = coeff;
            //v.at(i).exp = exponent;
        }
    }
}

//Evaluate a polynomial for a certain x
int Polynomial::evaluate(int x) const{
    if(x == 0) return 0;
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += v[i].coeff * intpow(x, v[i].exp); // intpow(x, v.at(i).exp)
    }/*
    for(auto e: v){
        sum += e.coeff * intpow(x, e.exp);
    }*/
    return sum;
}

void fun(Polynomial p, int a) {
  std::cout<<p.evaluate(a)<<std::endl;
}