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
- <a href="#dinamica">Memoria Dinamica</a>
- <a href="#classi">Classi</a>
- <a href="#pascal">StringPascal</a>
- <a href="#listint">List_int</a>
- <a href="#pimpl">Pimpl</a>
- <a href="#dl">Double Linked List</a>
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

#### Esercizio
````c++
struct coppia{
    int x;
    int y;
    int sum(){
        return x + y;
    }
}

int main(){
    coppia c;
    c.x = 4;
    c.y = 6;
    coppia c1;
    c1.x = 23;
    c1.y = 27;
    cout << c.sum();
    cout << c1.sum();
}
````
Il risultato che ci aspettiamo dai due <a href="https://cplusplus.com/reference/iostream/cout/" >cout</a> sono 10 e 50.

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

#### Somma degli elementi di un array

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

#### Foreach
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

#### Leggi
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

#### Contatore
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

### Bubble sort
Il bubble sort è un algoritmo di ordinamento. Vediamo come funziona con un esempio:<br>
Array = [9,7,2,25,19,35,12,10], soglia = 0.<br>
Invariante: la parte prima della soglia è ordinata e tutta minore della seconda parte della soglia.<br>
Durante il ciclo l'array arriverà in questa situazione: <br>
Array = [2,7,9|25,19,35,12,10], soglia = 2.<br>

Metodo di verifica: <br>
Confronta gli ultimi due elementi dell'array. Se sono disordinati li scambia.<br>
Contunua così a ritroso per ogni coppia. In questo modo il 10 che era a fine array riesce ad arrivare alla soglia.<br>
Così facendo la soglia viene incrementata e riinizia il processo del confronto.<br>
Il costo di questo algoritmo è n<sup>2</sup>.
````c++
void bouble_sort(vector<int>& v){
    int soglia = 0; // il vettore è ordinato nella porzione 0 , -1
    for(soglia = 0; soglia < v.size(); ++soglia){
        for(int i = v.size() - 1; i > soglia; i--){
            if(v.at(i) < v.at(i - 1))
                scambia(v.at(i), v.at(i - 1));
        }
    }
}
````


---

## <p id="matrici">Array multidimensionali - Matrici</p>
````c++
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix;
    int numr,numc;
    cin>>numr;
    cin>>numc;
    matrix.resize(r);
    for(int i = 0; i < numr; ++i) 
        matrix.at(i).resize(numc);
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
### Palindromo
````c++
bool palindroma(const string& s){
    
    bool flag = true;
    
    for(int i = 0; i < s.length() / 2; ++i)
        if(s.at(i) != s.at(s.length() - 1 - i)) 
            flag = false;
    
    return flag;
}
````
#### Esercizio
Dato un vettore di stringhe produrre una stringa che è la concatenazione delle stringhe
````c++
string concatena(const vector<string>& vs){
    string res;
    for(const auto& el : vs){
        res += el;
    }
    return res;
}
````
---

## <p id="dinamica">Memoria Dinamica</p>

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

---

## <p id="classi">Classi</p>
Finora abbiamo visto le struct in c++ come questa:
````c++
struct Punto{
    double x;
    double y;
    void trasla(double dx, double dy){
        x += dx;
        y += dy;
    }
};

int main(){
    Punto a,b;
    a.x = 10;
    a.y = 20;
    b.x = 4;
    b.y = 6;
    a.trasla(-2, 10.5);
}
````
Possiamo però anche definire delle classi allo stesso modo:

````c++
class Punto{
    double x;
    double y;
    void trasla(double dx, double dy){
        x += dx;
        y += dy;
    }
};
````
#### Differenza tra classi e struct:<br>
Gli elementi contenuti all'interno delle classi possono essere pubblici o privati.<br>
In questo caso x, y e trasla sono privati. Se voglio renderli pubblici devo scrivere public:.<br>
Una classe pubblica è uguale a una struct.

Una possibile implementazione di punto è:
````c++
class PuntoAdv{
    public:
        void setxy(double mx, double my){
            x = mx;
            y = my;
        }
        double getx(){
            return x;
        }
        double gety(){
            return y;
        }
        void trasla(double dx, double dy){
            x += dx;
            y += dy;
        }
    private:
        double x;
        double y;
};

int main(){
    PuntoAdv a;
    a.setxy(10.0,3.14);
    a.trasla(-2.0,10.5);
    cout<<a.getx()<<a.gety();
    a.x = 15; // errore perché x è privato
}
````

### <p id="pascal">StringPascal</p>

Codice presente nell' [header](stringPascal/stringPascal.h).
````c++
#ifndef CT0442_1_STRINGPASCAL_H
#define CT0442_1_STRINGPASCAL_H

#endif //CT0442_1_STRINGPASCAL_H
#include <iostream>
#include <string>

/*
 * un costruttore è un metodo che viene chiamato ogni volta
 * che si istanzia un oggetto di quella classe
 */

using namespace std;

class stringPascal{
    public:
        stringPascal(); // default constructor
        stringPascal(const string& s);
        stringPascal(char* s);
        char& at(int pos);
        stringPascal(const stringPascal& copy); //copy constructor
        ~stringPascal(); // distruttore
        void print() const; // il metodo print non modifica lo stato della classe
        void set(const string& s);
        void setchar(int pos, char c);
        string getchar(int pos);
        void setsize(int dim);
    private:
        unsigned char buff[256];
};
````

Codice presente nel [corpo](stringPascal/stringPascal.cpp).
````c++
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

````

### <p id="listint">List_int</p>

Codice presente nell' [header](List_int/List_int.h).
````c++
#include <iostream>
#include <cstdlib>

class List_int {
    public:
        List_int();

        List_int(const List_int& source);
        ~List_int();
        void append(int el);
        void prepend(int el);

        bool isempty() const;
        int size() const;
        int& head(); // Pre: List not empty
        const int& head() const;
        void print() const;

        //METODI AGGIUNTI POSTERIORMENTE
        List_int(int el);
        std::string convert_to_string() const;
        void tail(List_int& res);
        int& first();
        const int& first() const;
        bool equal(const List_int& l) const;
        void concat(List_int& l);
        List_int& operator=(const List_int& source);
        int deleteLast(int n);


    private:
        struct Cell{
            int info;
            Cell* next;
        };
        typedef Cell* Pcell;
        Pcell h;
        void append_ric(Pcell& testa, int el);
        void print_ric(Pcell testa) const;

        //CAMPO AGGIUNTO POSTERIORMENTE
        Pcell last;
        int  eliminaFondoRic(Pcell& l, int n);
        void pre_pend(Pcell l, int el);
        void ribalta_ric(Pcell&p);
};
````

Codice presente nel [corpo](List_int/List_int.cpp).
````c++
#include "list_int.h"

// METODI AGGIUNTI PRECEDENTEMENTE
List_int::List_int() {
    h = nullptr;
}

List_int::List_int(const List_int& source) {
    Pcell pc = source.h;
    h = nullptr;
    while(pc != nullptr){
        append(pc->info);
        pc = pc->next;
    }
}

List_int::~List_int(){
    Pcell pc = h;
    while(pc != nullptr){
        h = h->next;
        delete pc;
        pc = h;
    }
}

void List_int::prepend(int eL) {
    Pcell nuova = new Cell;
    nuova->info = eL;
    nuova->next = h;
    h = nuova;
}

void List_int::pre_pend(Pcell l, int el) {
    Pcell nuova = new Cell;
    nuova->info = el;
    nuova->next = h;
    h = nuova;
}

void List_int::append(int el) { // funzione cappello
    append_ric(h, el);
}

void List_int::append_ric(Pcell& testa, int el) {
    if(testa == nullptr){
        pre_pend(testa, el);
    }
    else{
        append_ric(testa->next, el);
    }
}

bool List_int::isempty() const {
    return (h == nullptr);
}

int& List_int::head() {
    return h->info;
}

const int& List_int::head() const {
    return h->info;
}

void List_int::print() const {
    print_ric(h);
}

void List_int::print_ric(Pcell testa) const{
    if(testa != nullptr){
        std::cout<<testa->info;
        print_ric(testa->next);
    }
}

int List_int::size() const{
    int res = 0;
    Pcell p = h;
    while(p != nullptr){
        res++;
        p = p->next;
    }
    return res;
}

// METODI AGGIUNTI POSTERIORMENTE
int List_int::deleteLast(int n) {
    return eliminaFondoRic(h,n);
}

int List_int::eliminaFondoRic(Pcell &l, int n) {
    if(l == nullptr) return 0;
    else{
        int deleted = eliminaFondoRic(l->next, n);
        if(deleted < n){
            delete l;
            l = nullptr;
            return deleted + 1;
        }
        else return n;


    }
}

void List_int::ribalta_ric(Pcell &p) {
    if(p != nullptr && p->next != nullptr){
        Pcell supp = p->next;
        ribalta_ric(supp);
        p->next->next = p;
        p->next = nullptr;
        p = supp;
    }
}
````
### <p id="pimpl">Pimpl</p>

Codice presente nell' [header](Pimpl/List_int.h).
````c++
#include <iostream>
#include <vector>
#include <cstdlib>
class List_int {
    public:
        List_int();
        List_int(const List_int& l);
        ~List_int();
        void append(int el);
        void prepend(int el);
        void stampa() const;
    private:
        struct Impl;
        Impl* pimpl;
};
````

Codice presente nel [corpo](Pimpl/List_int.cpp).
````c++
#include "List_int.h"

struct List_int::Impl {
    std::vector<int> v;
};

List_int::List_int()  {
    pimpl = new Impl;
}

List_int::List_int(const List_int &l) {
    pimpl = new Impl;
    pimpl->v = l.pimpl->v;
}

List_int::~List_int() {
    delete pimpl;
}

void List_int::prepend(int el) {
    pimpl->v.resize(pimpl->v.size()+1);
    for(int i = pimpl->v.size() - 1; i > 0; i--)
        pimpl->v[i] = pimpl->v[i - 1];
    pimpl->v[0] = el;
}

void List_int::append(int el) {
    pimpl->v.push_back(el);
}

void List_int::stampa() const {
    for(auto e: pimpl->v)
        std::cout << e << std::endl;
}
````

Codice presente nel [main](Pimpl/princ.cpp).

````c++
#include "List_int.h"

int main(){
    List_int l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.prepend(0);
    l.stampa();
    return 0;
}
````

### <p id="dl">Double Linked List</p>

Codice presente nell' [header](DoubleLinkedList/ListDL.h).
````c++
#include <cstdlib>
#include <iostream>

class ListDL {
    public:
        ListDL();
        ListDL(const ListDL& s);
        ~ListDL();
        void prepend(int e);
        void append(int e);
    private:
        struct Cell {
            int info;
            Cell* next;
            Cell* prev;
        };
        typedef Cell* Pcell;
        Pcell head;
        Pcell tail;
        void copy(Pcell h, Pcell t);
};
````

Codice presente nel [corpo](DoubleLinkedList/ListDL.cpp).
````c++

````

