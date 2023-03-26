/*
 * Un grattacielo viene verniciato in modo tale che ogni piano sia bianco oppure nero. I piani vengono numerati da 0.
 * L'architetto è molto attento alla moda e sa che non può verniciare due piani neri consecutivi mentre può verniciare quanti piani bianchi consecutivi vuole.
 * Si scopre che i condomini vorrebbero tutti vivere in un piano verniciato di nero e offrono all'architetto dei soldi perché il piano in cui vivono sia scelto per essere verniciato di nero.
 * Vista l'opportunità ghiotta, l'architetto vuole scoprire il massimo guadagno che può totalizzare scegliendo opportunamente le verniciature di bianco e nero che rispettano il vincolo di non mettere due piani neri consecutivi.
 * Input:
 * n: il numero di piani del palazzo
 * offerte: vettore di n elementi che contiene l'offerta del piano i, con 0<=i<n. Gli elementi del vettore sono non negativi.
 * Output:
 * il guadagno massimo dell'architetto
 * Esempio: supponiamo di avere un piccolo palazzo di 3 piani.
 * Il piano 0 e il piano 2 offrono 100 euro per essere neri, mentre il piano 1 offre 80 Euro. Il guadagno totale sarà 200,
 * corrispondente alla verniciatura Nero, Bianco, Nero.
 * Suggerimento: La funzione ricorsiva grattacielo ha la seguente firma:
 * int grattacielo(const vector<int>& v, int piano, colore c);
 * Dove i parametri hanno il seguente significato:
 * v: è il vettore di offerte degli inquilini u
 * piano: è il prossimo piano di cui si deve decidere il colore
 * c: è il colore del piano precedente a quello di cui si deve
 * decidere il colore
 */

#include <iostream>
#include <vector>

enum colore{Bianco, Nero};

typedef enum colore tcolore;

void leggi_vettore(std::vector<int>& v)
{
    for (auto& el:v)
        std::cin >> el;
}

// DA IMPLEMENTARE
int grattacielo(const std::vector<int>& v, int piano, colore c) {
    if(piano >= v.size()){
        return 0;
    }
    else{
        int black = 0, white = 0;
        white += grattacielo(v, piano + 1, Bianco);
        if(c == Bianco) black += v.at(piano) + grattacielo(v, piano + 1, Nero);
        return std::max(black, white);
    }
}
int main() {
    std::vector<int> reward;
    int n;
    std::cin>>n;
    reward.resize(n);
    leggi_vettore(reward);
    std::cout<<grattacielo(reward, 0, Bianco);
    return 0;
}