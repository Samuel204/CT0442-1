/*
 * Scriver la funzione:  vector<double> media_mobile(const vector<double>& v, int k)
 * che calcola un vettore della stessa dimensione di v in cui l'i-mo è la media dei k
 * elementi che precedono i, dei k elementi che seguono i e dell'i-mo stesso.
 * Nel caso in cui una posizione non sia presente nel vettore, va ingorata.
 * Per esempio, supponiamo che v sia il vettore [12.0, 13.0, 0.0, -1.0, 5-0] e che k
 * sia uguale a 1, allora il vettore in output sarà [12.5, 8.33, 4.0, 1.33, 2.0].
 */
#include<vector>
#include<iostream>

void print(const std::vector<double>& v) {
  for (auto x: v) {
    std::cout<<x<<std::endl;
  }
}


void read(std::vector<double>& v) {
  int size;
  double el;
  std::cin>>size;

  v.clear(); //cancella tutti gli elementi del vettore
  for (;size>0;size--) {
    std::cin>>el;
    v.push_back(el);
  }
}

//FUNZIONE DA SCRIVERE
std::vector<double> moving_average(const std::vector<double> v, int k) {
    if(k == 0) return v;
    std::vector<double> res(v.size());
    double sum = 0.0;
    int count = 1;
    for(int i = 0; i < v.size(); i++){
        sum = v.at(i);
        int posj = i + 1;
        for(int j = 0; j < k; j++){
            if(posj < v.size()){
                sum += v.at(posj);
                count++;
            }
            posj++;
        }
        int posx = i - 1;
        for(int x = 0; x < k; x++){

            if(posx >= 0){
                sum += v.at(posx);
                count++;
            }
            posx--;
        }
        res.at(i) = sum / count;
        count = 1;
    }
    return res;
}
int main() {
  std::vector<double> v;

  int mov;

  std::cin>>mov;

  read(v);

  std::vector<double> result;

  result = moving_average(v, mov);

  print(result);

  return 0;
}