//
// Created by Simone Dinato on 23/02/23.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void init(std::vector<int>& v, int carte){
    v.resize(carte);
    for(int i = 0; i < carte; i++){
        v.at(i) = i;
    }
}
void print(const std::vector<int>& v){
    for(auto e : v){
        std::cout<<e<<std::endl;
    }
}

int estrai(std::vector<int>& v){
    int pos = rand()%v.size();
    int result = v.at(pos);
    v.at(pos) = v.at(v.size() - 1);
    v.pop_back();
    return result;
}

int main(){
    std::vector<int> mazzo;
    int ncarte;
    srand(time(NULL));
    std::cin>>ncarte;
    init(mazzo, ncarte);
    print(mazzo);
    std::cout<<"Estrazione "<<std::endl;
    for(int i = 0; i < mazzo.size() / 2; i++){
        std::cout<<estrai(mazzo)<<std::endl;
    }
    std::cout<<"Mazzo Rimanente: "<<std::endl;
    print(mazzo);
}