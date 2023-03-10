/*
 * Scrivere una funzione che, date due stringhe, decida se una è l'anagramma dell'altra.
 * Notate che lo stesso carattere può comparire più volte nelle stringhe. I caratteri di spaziatura vanno ignorati.
 * Le stringhe contengono caratteri alfabetici minuscoli e spazi (nient'altro).
 * La firma della funzione sarà:  bool anagramma(string s1, string s2);
 * dove s1 e s2 sono le stringhe da considerare. Ad esempio "sogno civetta" è l'anagramma di "cattivo segno".      PS: condizione perché s1 sia anagramma di s2 è che tutti i caratteri di s1 siano presenti in s2 e viceversa nello stesso numero di volte.
 */
#include <iostream>
#include <string>

using std::string;

//FUNZIONE DA SCRIVERE
bool anagramma(string s1, string s2)
{
    if(s1.size() == 0 && s2.size() == 0) return true;
    bool trovato;
    int nontrovato = 0;
    for(int i = 0; i < s1.size(); ++i){
        trovato = false;
        for(int j = 0; j < s2.size() && !trovato; ++j){
            if(s1[i] == s2[j]){
                trovato = true;
                s2.erase(j,1);
            }
        }
        if(!trovato) nontrovato++;
    }
    if(s2[0] == ' ') s2.erase(0);
    if(nontrovato > 0 || s2.size() > 0) return false;
    else return true;
}

int main() {
    string a, b;
    getline(std::cin, a);
    getline(std::cin, b);

    if (anagramma(a,b))
        std::cout << "Si" <<std::endl;
    else
        std::cout << "No" <<std::endl;
    return 0;
}