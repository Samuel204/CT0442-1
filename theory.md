# PEL - Theory 

---

### Tipo di dato: 
Insieme di valori sui quali vengono definite delle operazioni.

---
### Oggetto: 
Area di memoria dotata di tipo.

---
### Variabile: 
Oggetto a cui è stato assegnato un identificatore.
````c++
int a;
double b = 3.14;
a = b;
````
Esegue, narrowing (viene messo solo 3 con conseguente perdita di informazioni),
casting implicito, da evitare.

---

````c++
int a = 2;
double b = 3.14;
b = a;
````
Esegue, cast implicito

---
### Inizializzazione
````c++
int z = 12; 
//questa è anche una definizione (alloco spazio in z) e una dichiarazione (introduco un nuovo nome)
int k{12]; 
//con le graffe controlla il narrowing e se c'è da errore
````
---
### Assegnamento
````c++
int z;
z = z + 2;
````
---
### Puntatori
Si possono usare entrambe le sintassi.
````c++
//c:
int *p;
//c++: 
int* p;

````
---
Assegna a p l'indirizzo di memoria di x

````c++
int* p;
int x;
p = &x;
````
---
### Operatore * e &
L'operatore * prende in input un right value e produce un left value
````c++
x = *p + 3;
````
---

L'operatore & estrae l'indirizzo di memoria di una variabile.
Lavora su un left  value e produce un right value.
quindi:
````c++
&x = p;
````
non è corretto

---

### Costanti
````c++
constexpr int a = 7;
````
Creiamo una variabile right value;

---

### Cicli
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
#### Invariante
Invariante di un ciclo: proprietà vera prima e durante il ciclo.<br>
Invariante di questo ciclo: se sono dentro al ciclo resp è falso e i appartiene al dominio.

#### Massimo Comune Divisore
````c++
while(a!=b){
    if(a > b) a = a - b;
    else b = b - a;
}
cout<<a;
````
Invariante: il massimo comune divisore non cambia, anche se operiamo su a e b dentro al ciclo

---

### Referenze
````c++
double a;
double& b = a;
double c = 3.14;
b = c;
````
Modifica sia a che b perché sono la stessa cosa

#### Swap
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

### Funzioni
Parametri di una funzione: parametri formali<br>
Passaggio dei parametri per: valore / copia - referenza / indirizzo

#### Copia - Valore
````c++
void esempio(int a, double b){
    ...
}
````
Non modifica i valori dei parametri, viene passato un right value

---

#### Referenza - Indirizzo
````c++
void esempioref(int& a, int& b){
    ...
}
````
Modifica i valori dei parametri passati, viene passato un left value

---

### Struct
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

---

````c++
void foo(ts& x);
````
Foo modifica y, semantica di c++. Non è possibile farlo in c.

---

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

---

#### Differene dal codice C
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

### Vectors
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