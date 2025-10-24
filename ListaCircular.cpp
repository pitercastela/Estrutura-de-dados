#include <iostream>
using namespace std;

class No{
    public:
        int dado;
        No *proximo;
        No *anterior;
        No(int dado = 0, No *p = nullptr, No *a  = nullptr){
            this->dado = dado;
            this->proximo = p;
            this->anterior = a;
        }
};

class ListaCircular{
public:
    No *head;

    ListaCircular(){
        this->head = new No(0);
        head->anterior = head;
        head->proximo = head;
    }

    void addFinal(int info){
        No *novo = new No(info);
        No *ultimo = head->anterior;

        ultimo->proximo = novo;
        novo->anterior = ultimo; 
        novo->proximo = head;
        head->anterior = novo;
    }

    void addInicio(int info){
        No *novo = new No(info);
        No *p = head->proximo;

        novo->proximo = p;
        head->proximo = novo;
        novo->anterior = head;
        p->anterior = novo;
        
        delete p;
    }
    void remove(int info){
        No *p = head->proximo; 
        while (p != head && p->dado != info) {
            p = p->proximo;
        }
        if (p != head) {
            p->anterior->proximo = p->proximo;
            p->proximo->anterior = p->anterior;
            delete p;
            cout << "Elemento " << info << " removido." << endl;
        } else {
            cout << "Elemento " << info << " nao encontrado para remocao." << endl;
        }
    }

    void Busca(int info){
        No *p = head->proximo;
        while(p != head){
            if(p->dado == info){
                cout << "Elemento " << info << " encontrado na lista." << endl;
                return;
            }
            p = p->proximo;
        }
        cout << "Elemento " << info << " nao encontrado na lista." << endl;
        delete p;
    }

    void imprime(){
        No *p = head->proximo;
        if (p == head) {
            cout << "Lista vazia." << endl;
            return;
        }
        cout << "Lista: head <-> ";
        while (p != head) {
            cout << p->dado << " <-> ";
            p = p->proximo;
        }
        cout << "head" << endl;
    }
};

int main() {
    ListaCircular lista;
    lista.imprime();

    lista.addInicio(20);
    lista.addInicio(10);
    lista.imprime();

    lista.addFinal(30);
    lista.addFinal(40);
    lista.imprime();


    lista.Busca(30);
    lista.Busca(99);

    lista.remove(99);
    lista.imprime();

    lista.remove(20);
    lista.imprime();
    lista.remove(10);
    lista.imprime();

    lista.remove(40);
    lista.imprime();

    lista.remove(30);
    lista.imprime();

    return 0;
}