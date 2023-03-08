#include "stringPascal.h"

void stringPascal::set(const string& s) {
    if(s.length() <= 255)
        buff[0] = s.length();
    else
        buff[0] = 255;
    for(int i = 1; i <= buff[0]; ++i)
        buff[i] = s.at(i - 1);

}

void stringPascal::print(){
    for(int i = 1; i <= buff[0]; ++i){
        cout << buff[i];
    }
    cout<<endl;
}

stringPascal::stringPascal() {
    buff[0] = 0;
}

stringPascal::stringPascal(const string& s) {
    set(s);
}

stringPascal::stringPascal(const stringPascal& s) {
    this->buff[0] = s.buff[0];
    for(int i = 1; i <= s.buff[0]; ++i)
        this->buff[i] = s.buff[i];
}

int main(){
    stringPascal x;
    stringPascal y;
    x.set("Hi");
    y.set("Hello");
    x.print();
    y.print();
    string cpps = "Hi";
    stringPascal z(cpps);
    stringPascal w(z); //uso del copy constructor
}
