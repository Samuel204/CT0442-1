#include "stringPascal.h"

void stringPascal::set(const string& s) {
    if(s.length() <= 255)
        buff[0] = s.length();
    else
        buff[0] = 255;
    for(int i = 1; i <= buff[0]; ++i)
        buff[i] = s.at(i - 1);

}

void stringPascal::print() const{
    for(int i = 1; i <= buff[0]; ++i){
        cout << buff[i];
    }
    cout<<endl;
}

char& stringPascal::at(int pos) {
    if(pos < buff[0])
        return reinterpret_cast<char &>(buff[pos]);
    else return reinterpret_cast<char &>(buff[buff[0] - 1]);
}

stringPascal::stringPascal() {
    buff[0] = 0;
}

stringPascal::stringPascal(const string& s) {
    set(s);
    cout << "Costruttore stringa" << endl;
}

stringPascal::stringPascal(char* s){
    int n = strlen(s);
    if(n < 256) buff[0] = n;
    else buff[0] = 255;
    for(int i = 0; i < buff[0]; i++){
        buff[i + 1] = char(i);
    }
    cout << "Costrutture char" << endl;
}

stringPascal::stringPascal(const stringPascal& copy) {
    for(int i = 0; i <= copy.buff[0]; ++i)
        buff[i] = copy.buff[i];
}

stringPascal::~stringPascal() {
    cout << "Chiamato il distruttore di class" << endl;
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
    char c[100] = "Hello";
    stringPascal s(c);
    s.print();
}
