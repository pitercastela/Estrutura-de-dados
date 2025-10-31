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
int Josephus(int n, int k, int start) {

        if (n <= 0 || k <= 0 || start <= 0 || start > n) {
            return -1; 
        }

        No* p = head->proximo;
        while(p != head) {
            No* temp = p;
            p = p->proximo;
            delete temp;
        }
        head->proximo = head;
        head->anterior = head;

        for (int i = 1; i <= n; i++) {
            addFinal(i);
        }

        No *atual = head->proximo;
        while (atual->dado != start && atual != head) {
            atual = atual->proximo;
        }
        if (atual == head) return -1;

        while (head->proximo != head->anterior) {
            
            for (int i = 0; i < k; i++) {
                atual = atual->proximo;
                if (atual == head) {
                    atual = atual->proximo;
                }
            }

            No * eliminar = atual;

            atual =  eliminar->proximo;
            if (atual == head) {
                atual = atual->proximo;
            }


             eliminar->anterior->proximo =  eliminar->proximo;
             eliminar->proximo->anterior =  eliminar->anterior;
            delete  eliminar; 
        }

        return head->proximo->dado;
    }
    

};

int main() {
    ListaCircular lista;

    int sobrevivente1 = lista.Josephus(5, 2, 2);

    return 0;
}