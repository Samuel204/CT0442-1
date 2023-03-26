/*
 * Desideriamo creare una funziona che trasformi un numero in una stringa che descrive una carta.
 * Usiamo un mazzo di 40 carte del tipo trevigiano, con la seguente codifica:
 * • I numeri da 0 a 9 fanno riferimento ai denari
 * • I numeri da 10 a 19 alle coppe
 * • I numeri da 20 a 29 ai bastoni
 * • i numeri da 30 a 39 alle spade
 * All'interno del range le carte sono ordinate in modo crescente.
 * Per esempio lo O sarà l'asso di denari, l'1 il due di denari e così via fino al 9 che sarà il re di denari, mentre il 10 sarà l'asso di coppe, ecc..
 * Si desidera scrivere una funziona che dato un numero restituisca una stringa che specifichi il valore e il seme della carta.
 * Il valore sarà il numero stampato sulla carta, tranne che per i seguenti casi:
 * 1 -> Asso
 * 8 -> Donna
 * 9 -> Fante
 * 10 -> Re
 * Vediamo alcuni esempi. La conversione del numero 18 dovrà dare la stringa "Fante di coppe", mentre il numero 23
 * restituisce "4 di bastoni"
 * Se l'input esce dal range [0,39] si restituisce la stringa "Errore di conversione"
 * Nota: non trasformate i le cifre in char caso per caso, ma sfruttate la codifica dei char.
 */

#include<iostream>
#include<vector>

using std::vector;
using std::string;

// DA IMPLEMENTARE
string carta(int n) {
    if(n < 0 || n > 39) return "Errore di conversione";
    string res, s;
    if(n <= 9) s = " di denari";
    else if(n <= 19) s = " di coppe";
    else if(n <= 29) s = " di bastoni";
    else s = " di spade";
    n = (n + 1) % 10;
    switch(n){
        case 0:
            res = "Re" + s;
            break;
        case 1:
            res = "Asso" + s;
            break;
        case 8:
            res = "Donna" + s;
            break;
        case 9:
            res = "Fante" + s;
            break;
        default:
            res = std::to_string(n) + s;
            break;
    }
    return res;
}

int main() {
  int c;
  string cstr;
  std::cin>>c;
  std::cout<<"**";
  cstr = carta(c);
  std::cout<<"**";
  std::cout<<std::endl<<cstr<<std::endl;
  return 0;
}
