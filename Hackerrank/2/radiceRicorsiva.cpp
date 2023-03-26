/*
 * In questo esercizio dovrai implementare un algoritmo ricorsivo che calcola la radice di indice k di un numero n, dove k
 * è un intero maggiore o uguale a 2 e n è un numero double maggiore di 1.
 * La radice va calcolata correttamente con 5 cifre decimali.
 * La funzione ha firma: double radice(double n, unsigned int k, double min, double max);
 * I parametri formali min e max rappresentano l'intervallo entro cui cercare la radice e ad ogni chiamata ricorsiva diventerà sempre più piccolo.
 * Ad esempio, supponiamo di voler calcolare la radice quadrata di 5, quindi n=5.0 e k=2.
 * La chiamata alla funzione dal main sarà: res = radice(5.0, 2, 1.0, 5.0). L'intervallo di ricerca iniziale è (1.0, 5.0).
 * Quindi calcoliamo il punto medio dell'intervallo, cioè (5+1)/2 = 3.0.
 * Siccome 3^2=9 e 9>5.0 vuol dire che la radice sta nell'intervallo (1.0, 3.0).
 * Ricalcoliamo il punto medio che risulta essere 2.0. Siccome 2.0^2=4.0<5.0 significa che la radice sta nell'intervallo (2.0,3.0).
 * Ricalcoliamo il punto medio che risulta essere 2.5. Siccome 2.5^2=6.25>5.0 significa che la radice sta nell'intervallo (2.0,2.5).
 * Ad ogni passo l'intervallo diventa sempre più piccolo.
 * Quando è "sufficientemente piccolo" (quale condizione?) allora il punto medio è la radice cercata con l'approssimazione richiesta.
 * Non usare altre librerie rispetto a quelle date.
 */

#include<iostream>
#include<iomanip>

// DA IMPLEMENTARE
double radice(double n, unsigned int k, double min, double max) {
    double res = (max + min) / 2;
    double interval = res;
    for(int i = 1; i < k; ++i)
        interval *= res;
    double a = (interval - n > 0) ?  interval - n : n - interval;
    if(a < 0.00001) return res;
    else if(interval > n){
        res = radice(n,k, min, res);
    }
    else{
        res = radice (n,k,res,max);
    }
    return res;
}

int main() {
    double input;
    unsigned int indice;

    std::cin>>input;
    std::cin>>indice;

    std::cout<<std::setprecision(5)<<radice(input, indice, 1.0, input);

    return 0;
}