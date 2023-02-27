# PEL - THEORY

---

## Sommario
- <a href="#tipo">Tipo di dati e oggetti</a>
- <a href="#variabile">Variabili</a>
- <a href="#puntatori">Puntatori</a>
- <a href="#cicli">Cicli</a>
- <a href="#referenza">Referenze</a>
- <a href="#funzioni">Funzioni</a>
- <a href="#struct">Struct</a>
- <a href="#vectors">Vectors</a>
- <a href="#matrici">Matrici</a>
- <a href="#esercizio">Esercizio</a>
- <a href="#stringhe">Stringhe</a>
---

### <p id="tipo">Tipo di dato: </p>
Insieme di valori sui quali vengono definite delle operazioni.

### Oggetto:
Area di memoria dotata di tipo.

---
### <p id="variabile">Variabili</p>
Oggetto a cui è stato assegnato un identificatore.
````c++
int a;
double b = 3.14;
a = b;
````
Esegue, narrowing (viene messo solo 3 con conseguente perdita di informazioni),
casting implicito, da evitare.


````c++
int a = 2;
double b = 3.14;
b = a;
````
Esegue, cast implicito


#### Inizializzazione
````c++
int z = 12; 
//questa è anche una definizione (alloco spazio in z) e una dichiarazione (introduco un nuovo nome)
int k{12]; 
//con le graffe controlla il narrowing e se c'è da errore
````

#### Costanti
````c++
constexpr int a = 7;
````
Creiamo una variabile right value;

---

#### Assegnamento
````c++
int z;
z = z + 2;
````
---
## <p id="puntatori">Puntatori</p>
Si possono usare entrambe le sintassi.
````c++
//c:
int *p;
//c++: 
int* p;

````

Assegna a p l'indirizzo di memoria di x

````c++
int* p;
int x;
p = &x;
````

### Operatore * e &
L'operatore * prende in input un right value e produce un left value
````c++
x = *p + 3;
````


L'operatore & estrae l'indirizzo di memoria di una variabile.
Lavora su un left value e produce un right value.
Quindi:
````c++
&x = p;
````
non è corretto

---

## <p id="cicli">Cicli</p>
Le variabili dentro la condizione del for vanno modificate solo nella parte di iterazione, non dentro al blocco.
Né break né continue né goto.

Do while: ciclo almeno una volta.
While: posso anche non ciclare.

Esempio:
````c++
int v[20];
/* codice che legge v*/
/* domanda: v contiene il valore 5? */
bool resp = false;
int i = 0;
while( i < 20 && !resp){
	if(v[i] == 5) rest = true;
	i++;
}
if(resp) cout<<"presente";
else cout<<"non presente";
````
### Invariante
Invariante di un ciclo: proprietà vera prima e durante il ciclo.<br>
Invariante di questo ciclo: se sono dentro al ciclo resp è falso e i appartiene al dominio.

### Massimo Comune Divisore
````c++
while(a!=b){
    if(a > b) a = a - b;
    else b = b - a;
}
cout<<a;
````
Invariante: il massimo comune divisore non cambia, anche se operiamo su a e b dentro al ciclo

---

## <p id="referenza">Referenze</p>
````c++
double a;
double& b = a;
double c = 3.14;
b = c;
````
Modifica sia a che b perché sono la stessa cosa

### Swap
````c++
void swap (int& a, int& b){
    int c;
    c = a;
    a = b;
    b = c;
}
int main(){
    int x = 3, y = 4;
    swap(x,y);
    cout<<x<<" "<<y<<endl;
}
````
Passaggio di parametri per referenza o per indirizzo: passo dei left value.

---

## <p id="funzioni">Funzioni</p>
Parametri di una funzione: parametri formali<br>
Passaggio dei parametri per: valore / copia - referenza / indirizzo

#### Copia - Valore
````c++
void esempio(int a, double b){
    ...
}
````
Non modifica i valori dei parametri, viene passato un right value



#### Referenza - Indirizzo
````c++
void esempioref(int& a, int& b){
    ...
}
````
Modifica i valori dei parametri passati, viene passato un left value

---

## <p id="struct">Struct</p>
````c++
struct s{
    int a;
    double b;
}

typedef struct s ts;

void foo(ts x){
    x.a = 12;
    x.b = 12.3;
}

int main(){
    ts y;
    foo(y);
    ...
}
````

Foo non modifica y.



````c++
void foo(ts& x);
````
Foo modifica y, semantica di c++. Non è possibile farlo in c.


````c++
struct s{
    int a;
    double b;
}

typedef struct s ts;

ts foo(ts x){
    x.a = x.a + 12;
    x.b = x.b * 2;
    return x;
}

int main(){
    ts y,w;
    y.a = 4;
    y.b = 3.0;
    w = foo(y);
    ...
}
````
Il main istanzia y, la funzione foo ritorna in i valori modificati di y in w.

#### Differenze dal codice C
````c++
struct s{
    int a;
    double b[40];
}
typedef struct s ts;
ts foo(ts x){
    x.a = x.a + 12;
    x.b[0] = x.b[0] * 2;
}
int main(){
    ts y,w;
    y.a = 4;
    y.b[0] = 3.0;
    w = foo(y);
    ...
}
````
x viene passato per copia, viene fatta una deep copy.
Un array dichiarato dentro la struct viene passato per copia, se viene dichiarato fuori viene passato per indirizzo:

````c++
void foo2(int a[]){
    for(int i = 0; i < 20; i++)
        a[i] = 0;
}
int main(){
    int v[20];
    foo2(v);
    //é come fare foo2(&v[0]);
}
````
Passo v per riferimento, v viene modificato. Non useremo mai questa sintassi.

---

## <p id="vectors">Vectors</p>
````c++
#include <vector>

void foo (std::vector<int>& temp){ // passaggio del vettore per indirizzo
    ...
}

int main(){
    std::vector<double> v; //la dichiarazione del tipo in quel modo è definita come template
    std::vector<int> v(30); //possiamo definire la size in dichiarazione
    v.push_back(13.4); //inserisce un elemento in coda
    v.at(0) = 13.2; //controlla se l'indice è nella size dell'array
    v[0] = 13.2; // non controlla l'indice
    v.size(); // ritorna la lunghezza dell'array
    v.pop_back() // rimuove l'ultimo elemento
    foo(v);
}
````
I template vengono risolti in fase di compilazione

Capacity: memoria occupata dall'array.<br>
Size: Memoria utilizzata dall'array.<br>
Se la size è uguale alla capacity e viene fatta una pushback, la capacity viene raddoppiata

---

### Somma degli elementi di un array

Il tipo delle varibili è determinato staticamente.<br>
La valutazione delle espressioni è determinata in esecuzione.<br>
Valore: cifra / carattere / espressione.<br>
Proprietà: relazione tra valori.<br>

````c++
int main(){
    vector<int>v;
    leggi(v);
    int sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum = sum + v.at(i);
    }
    cout<<sum;
}
````
Invariante: sum è la somma degli elementi tra 0 e i-1.<br>
Scorro per indice.<br>

---

### Foreach
Rappresenta un'altro modo per scorrere gli elementi di un array
````c++
for(int e : v){
    sum = sum + e;
}
````
Viene copiato il valore nella posizione considerata dell'array.
Scorro per elemento.
La e rappresenta una copia degli elementi dell'array. Cioé se modifico e non modifico gli elementi dell'array.

Al posto di int e si può inserire auto in modo da lasciar decidere il tipo della 
variabile al compliatore in base al tipo degli elementi dell'array.

---

### Leggi
````c++
void leggi(vector<int>& tr){
    int num;
    cin>>num;
    tr.resize(num);
    for(int i = 0; i < num; i++){
        cin>>tr.at(i);
    }
    //oppure
    //for(auto& e : tr) cin>>e;
    //in questo caso se modifico e modifico tr
}

void leggi(vector<int>* tr){
    int num;
    cin>>num;
    tr->resize(num);
    for(int i = 0; i < num; i++){
        cin>>*(tr).at(i);
        //oppure
        cin>> tr->at(i);
    }
}
````
Differenze tra le due firme:
- Prima: non si usano i puntatori (nascosti).
- Seconda: il parametro deve essere un left value. Mi arriva un passaggio per copia e un indirizzo di memoria.

---

### Contatore
````c++
int main(){
    vector<int> v;
    leggi(v);
    int pari = 0;
    for(auto e : v){
        if(e % 2 == 0) pari++;
    }
    cout<<pari;
}
````
Invariante: pari contiene il numero di elementi pari all'interno dell'array.

## <p id="matrici">Array multidimensionali - Matrici</p>
````c++
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix;
    int r,c;
    cin>>r;
    cin>>c;
    matrix.resize(r);
    for(auto e : matrix) e.resize(c);
    //metto a 0 tutti gli elementi della matrice
    for(auto r : matrix)
        for(auto& e : r)
            e = 0;
}
````

## <p id="esercizio">Esercizio - Problema mazzo di carte</p>

Array di 40 carte con estrazione casuale senza ripetizioni.
Soluzione:
````c++
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
````
## <p id="stringhe">Stringhe</p>

Unico modo per definire delle stringhe in c
````c++
char s[200] = "hello";
char t[50] = "hello";

if(s == t) // --> ritorna false poiché compara gli indirizzi di memoria
if(s > t) // compara i due indirizzi di memoria.
//s viene visto come l'indirizzo di memoria del primo carattere ( &s[0])
s = t // da errore --> s viene visto come right value e quindi non può stare a sinistra di un assegnamento
// invece
char *u;
u = s;
if(u == s) //ritorna true
````
Da array di caratteri a stringhe in c++
````c++
#include <string>

string s1,s2;
cin>>s1;
cin>>s2;

if(s1 == s2) // compara le due stringhe
s1 = s2 // mette dentro s1 il contenuto di s2
s1>s2 // ordinamento alfabetico
// se s1 contiene abaco e s2 contiene abate restituisce false

s3 = s1 + s2 
s1 = s1 + s2
// due modi per concatenare le stringhe

s1.lenght() // restituisce il numero di caratteri di s1
````
Alcune chiamate a funzione con le stringhe:
````c++
void f(string s)
// copio s, non modifico la stringa originale
void f1(string& s) 
// posso modificare la stringa originale
void f2(const string& s) 
// s è passata per referenza come su f1 ma il const ci garantisce che non verrà modificata
````
---

## Memoria Dinamica

Differenze tra c e c++:
````c++
// c
int* p = (int*)malloc(sizeof(int));
free();
//c++
int a = new int;
int size = 20;
int b = new int[size];
delete[] b;
````

