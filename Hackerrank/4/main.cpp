#include "Polynomial3.cpp"

int main() {
    //main 1
    Polynomial x;
    x.read();
    int a;
    std::cin>>a;
    fun(x,a);

    //main 2
    Polynomial y;
    y.read();
    y.print();

    //main 3
    Polynomial z;
    z.read();
    int b;
    std::cin>>b;
    z.differentiate(b).print();
    return 0;
}