// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class No{
    public:
        int dado;
        No *proximo;
        No(int dado, No *p = nullptr){
            this->dado = dado;
            this->proximo = p;
        }
};

class ListaEncadiada{public:
    No *head = new No(0);
    void ListaEncadeada(){
        this->head = nullptr;
    }
    void addFim(int info){
        No *novo = new No(info);
        if(head->proximo == nullptr){
            head->proximo = novo;
        } else {
            No *p = head;
            while(p->proximo != nullptr){
                p = p->proximo;
            }
            p->proximo = novo;
        }
    }
    void addInicio(int info){
        No *novo = new No(info);
        if (head->proximo != nullptr)
            {
            novo->proximo = head->proximo;
            }
            head->proximo = novo;
        }
    void remove(int info){
        No *p = head;
        while (p->proximo != nullptr && p->proximo->dado != info) {
           p = p->proximo;
        }
        if (p->proximo != nullptr) {
            No *remover = p->proximo;
            p->proximo = remover->proximo; 
            delete remover;
            delete p;
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
    ListaEncadiada lista;
    lista.addInicio(10);
    lista.addFim(20);
    lista.Busca(1);


    
    return 0;
}