/*
 * Creare una class "Carrello" che consenta di memorizzare una lista di oggetti dotati di descrizione,
 * quantità e costo unitario. La classe avrà un metodo per l'inserimento di un oggetto,
 * un metodo per creare una stringa con l'elenco degli oggetti (separati da una virgola e un carattere spaziatore),
 * e un metodo per calcolare il totale dovuto.
 * Nel caso in cui si invochino questi due metodi sul carrello vuoto il risultato sarà la stringa "Carrello vuoto" e 0 rispettivamente.
 * La stringa descrittiva deve contenere gli elementi in ordine di inserimento.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Carrello{
public:
    // DA IMPLEMENTARE
    Carrello() {
        head = nullptr;
    }
    // DA IMPLEMENTARE
    ~Carrello() {
        List* copy = head;
        while(copy != nullptr){
            head = head->next;
            delete copy;
            copy = head;
        }
    }
    // DA IMPLEMENTARE
    void add(string  desc, int qnt, double cost) {
        List* cell = new List{desc, qnt, cost, nullptr};
        /*cell->des = desc;
        cell->q = qnt;
        cell->pu = cost;
        cell->next = nullptr;*/
        if(head == nullptr){
            head = cell;
        }
        else{
            //std::cout << "Des " << desc << std::endl;
            List* copy = head;
            while(copy->next != nullptr){
                copy = copy->next;
            }
            copy->next = cell;
            /*copy->des = desc;
            //std::cout << "Des " << copy->des << std::endl;
            copy->q = qnt;
            copy->pu = cost;
            copy->next = nullptr;*/
        }

    }

    string print_carrello() {
        if(head == nullptr) return "Carrello vuoto";
        List* copy = head;
        string res = copy->des;
        while(copy->next != nullptr){
            copy = copy->next;
            res += ", " + copy->des;
        }
        return res;
    }

    double total() {
        if(head == nullptr) return 0;
        List* copy = head;
        double res = 0;
        while(copy != nullptr){
            res += copy->q * copy->pu;
            copy = copy->next;
        }
        return res;
    }

private:
    // DA IMPLEMENTARE
    struct List{
        string des;
        int q;
        double pu;
        List* next;
    };

    List* head;
};
int main() {

	Carrello car;

	int items;

	cin>>items;

	for (int i=0; i<items; i++) {
		string s;
		int q;
		double c;
		cin>>s;
		cin>>q;
		cin>>c;

		car.add(s, q, c);



	}

	cout << car.print_carrello();
	cout<<endl;
	cout<< car.total();
	return 0;
}
