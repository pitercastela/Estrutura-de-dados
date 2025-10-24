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

class ListaDuplamenteEncadiada{public:
    No *head = new No(0);
    void ListaDuplamenteEncadeada(){
        this->head = new No(0);

        head->anterior = nullptr;
        head->proximo = nullptr;

    }
    void addFim(int info){
        No *novo = new No(info);
        if(head->proximo == nullptr){
            head->proximo = novo;
            novo->anterior = head;
        } else {
            No *p = head;
            while(p->proximo != nullptr){
                p = p->proximo;
            }
            p->proximo = novo;
            novo->anterior = p;
        }
    }
    void addInicio(int info){
        No *novo = new No(info);
        if (head->proximo != nullptr)
            {
            novo->proximo = head->proximo;
            }
            head->proximo = novo;
            novo->anterior = head; 
        }
    void remove(int x) {
    No *p = head;
        while (p != nullptr) {
        if (p->dado == x) { 
            if (p->anterior != nullptr) {
                p->anterior->proximo = p->proximo; 
            } else {
                head = p->proximo; 
            }
            if (p->proximo != nullptr) {
                p->proximo->anterior = p->anterior; 
            } else {
            head->anterior = p->anterior; 
            }
            delete p; 
            return;
        }
        p = p->proximo; 
    }
};
        void Busca(int info){
            No *p = head;
            while(p != nullptr){
                if(p->dado == info){
                    cout << "Elemento " << info << " encontrado na lista." << endl;
                    return;
                }
                p = p->proximo;
            }
            cout << "Elemento " << info << " nao encontrado na lista." << endl;
        }
    };


int main() {
    ListaDuplamenteEncadiada lista;
    lista.addInicio(10);
    lista.addFim(20);
    lista.remove(10);
    lista.Busca(10);
    return 0;
}