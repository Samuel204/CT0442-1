# PEL - Theory 

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
