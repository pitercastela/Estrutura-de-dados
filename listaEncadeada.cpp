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
        }
    };
        bool Busca(int info){
            No *p = head->proximo;
            while(p->proximo != nullptr && p->dado != info){
                p = p->proximo;
            }
            if (p->dado == info)
            {
                return true;
            } return false;

        }
        int Conta(){
            int num = 0;
            No *p = head->proximo;
            while (p != nullptr)
            {
                num += 1;
                p = p->proximo;
            }
            return num;
        }
        void inverter() {
        No *anterior = nullptr;
        No *atual = head->proximo;
        No *proximo = nullptr;

        while (atual != nullptr) {
            proximo = atual->proximo;

            atual->proximo = anterior;

            anterior = atual;
            atual = proximo;
        }

        head->proximo = anterior;
    }

    void imprimir() {
        No *p = head->proximo;
        cout << "Lista: [ ";
        while (p != nullptr) {
            cout << p->dado << " ";
            p = p->proximo;
        }
        cout << "]" << endl;
    }
    void removerDuplicatas() {
        No *p = head->proximo;

        while (p != nullptr) {
            No *aux = p;

            while (aux->proximo != nullptr) {

                if (aux->proximo->dado == p->dado) {
                    No *noRemover = aux->proximo;

                    aux->proximo = noRemover->proximo;

                    delete noRemover;
                } else {
                    aux = aux->proximo;
                }
            }

            p = p->proximo;
        }
    }
    ListaEncadiada mesclar(ListaEncadiada& outraLista) {
        ListaEncadiada listaMesclada;
        No* tail = listaMesclada.head; // Ponteiro para o fim da nova lista

        // 1. Copia todos os elementos da lista ATUAL (this)
        No* p = this->head->proximo;
        while (p != nullptr) {
            tail->proximo = new No(p->dado); // Cria novo nó e anexa
            tail = tail->proximo;            // Avança o ponteiro tail
            p = p->proximo;                   // Avança o ponteiro da lista atual
        }

        // 2. Copia todos os elementos da OUTRA lista (outraLista)
        p = outraLista.head->proximo;
        while (p != nullptr) {
            tail->proximo = new No(p->dado); // Cria novo nó e anexa
            tail = tail->proximo;            // Avança o ponteiro tail
            p = p->proximo;                   // Avança o ponteiro da outra lista
        }

        return listaMesclada; // Retorna a nova lista completa
    }
    void selectionSort() {
        No* atual = head->proximo;
        while (atual != nullptr) {
            No* minNo = atual;
            No* busca = atual->proximo;

            while (busca != nullptr) {
                if (busca->dado < minNo->dado) {
                    minNo = busca;
                }
                busca = busca->proximo;
            }
            if (minNo != atual) {
                int temp = atual->dado;
                atual->dado = minNo->dado;
                minNo->dado = temp;
            }
            atual = atual->proximo;
        }
    }

};


int main() {
    ListaEncadiada lista;
    lista.addInicio(10); // Lista: [ 10 ]
    lista.addFim(20);    // Lista: [ 10 20 ]
    lista.addFim(30);    // Lista: [ 10 20 30 ]
    lista.addFim(40);    // Lista: [ 10 20 30 40 ]
    lista.addFim(40);    // Lista: [ 10 20 30 40 ]
    lista.addFim(40);    // Lista: [ 10 20 30 40 ]
    lista.imprimir();
    lista.removerDuplicatas();
    lista.imprimir();
    return 0;
}