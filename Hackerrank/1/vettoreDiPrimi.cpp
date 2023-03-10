/*
 * Si desidera scrivere una funzione che riempia un
 * vettore con n numeri primi dove n è un numero non negativo.
 */

#include<vector>
#include<iostream>

void print(const std::vector<int>& v) {
  for (auto x: v) {
    std::cout<<x<<std::endl;
  }
}
//FUNZIONE AGGIUNTA DA ME
bool is_prime(int i){
    int count = 0;
    for(int j = 1; j < i; ++j){
        if(i % j == 0) count++;
    }
    if(count > 1) return false;
    return true;
}
//FUNZIONE DA SCRIVERE
std::vector<int> fill_with_primes(int size) {
    std::vector<int> v(size);
    int count = 0, i = 2;
    while(count != size){
        if(is_prime(i)){
            v.at(count) = i;
            count++;
        }
        i++;
    }
    return v;
}
int main() {
  int size;

  std::cin>>size;

  std::vector<int> v;

  v = fill_with_primes(size);

  print(v);

  return 0;
}

