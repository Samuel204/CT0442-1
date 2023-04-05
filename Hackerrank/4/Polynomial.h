#include<iostream>
#include<vector>
#include<list>


class Polynomial{
      public:
            Polynomial();
            Polynomial(const Polynomial& p);
            void set(int exponent, int coeff);
            int at(int exponent) const;
            void read();
            int evaluate(int x) const;
            Polynomial differentiate(int order) const;
            int degree() const;
            void print() const;

        private:
            struct power{
                int exp;
                int coeff;
            };
            std::vector<power> v;
            int intpow(int base, int exponent) const;
};

