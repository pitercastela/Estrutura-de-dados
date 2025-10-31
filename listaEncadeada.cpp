#include <iostream>
#include <vector>     // <-- Para receber a lista de posições
#include <algorithm>  // <-- Para ordenar a lista de posições
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
    }No* encontrarNesimoDoFim(int n) {
        // N deve ser um número positivo
        if (n < 1) {
            cout << "Erro: 'n' deve ser 1 ou maior." << endl;
            return nullptr;
        }

        No* fast = head;
        No* slow = head;

        // 1. Avança o ponteiro 'fast' N posições à frente.
        for (int i = 0; i < n; i++) {
            // Se 'fast->proximo' é nulo, a lista é mais curta que 'n' elementos.
            if (fast->proximo == nullptr) {
                cout << "Erro: A lista tem menos que " << n << " elementos." << endl;
                return nullptr;
            }
            fast = fast->proximo;
        }

        // 2. Agora, avança 'fast' e 'slow' juntos até 'fast'
        //    chegar ao *último nó* da lista (fast->proximo == nullptr).
        while (fast->proximo != nullptr) {
            fast = fast->proximo;
            slow = slow->proximo;
        }

        // 'slow' agora aponta para o nó *anterior* ao N-ésimo do fim.
        // O N-ésimo nó do fim é, portanto, 'slow->proximo'.
        return slow->proximo;
    }void removerNesimo(int n) {
        // Posição 0 ou negativa é inválida.
        if (n < 1) {
            cout << "Erro: Posicao 'n' deve ser 1 ou maior." << endl;
            return;
        }

        No* p = head;

        // 1. Anda 'n-1' passos para chegar ao *predecessor* do nó a remover.
        //    'p' começará no 'head' (posição 0, o predecessor do 1º).
        //    Após 1 passo (i=0), 'p' estará no 1º (predecessor do 2º).
        //    Após k passos, 'p' estará no k-ésimo (predecessor do k+1-ésimo).
        for (int i = 0; i < n - 1; i++) {
            // Se p->proximo for nulo *antes* de terminarmos o loop,
            // significa que 'n' é maior que o tamanho da lista.
            if (p->proximo == nullptr) {
                cout << "Erro: A lista tem menos que " << n << " elementos." << endl;
                return;
            }
            p = p->proximo;
        }

        // 2. 'p' agora é o predecessor.
        // O nó a remover é 'p->proximo'.
        // Precisamos verificar se o nó a remover realmente existe.
        No* noRemover = p->proximo;

        if (noRemover == nullptr) {
            // Isso acontece se n é maior que o tamanho da lista.
            // (Ex: lista com 3 itens, n=4. O loop anda 3x, p para no 3º item.
            // p->proximo é nulo).
            cout << "Erro: A lista tem menos que " << n << " elementos." << endl;
            return;
        }

        // 3. Remove o nó
        p->proximo = noRemover->proximo; // Desvia o ponteiro
        delete noRemover;                // Libera a memória do nó removido
    }void duplicarElementos() {
        No* p = head->proximo; // Começa no primeiro nó real

        while (p != nullptr) {
            // 1. Guarda o nó seguinte
            No* originalProximo = p->proximo;

            // 2. Cria o novo nó duplicado
            No* novoDuplicado = new No(p->dado);

            // 3. Insere o duplicado após 'p'
            p->proximo = novoDuplicado;

            // 4. Reconecta o duplicado ao resto da lista
            novoDuplicado->proximo = originalProximo;

            // 5. Avança 'p' para o *próximo nó original*.
            //    (Pulamos o nó que acabamos de adicionar)
            p = originalProximo;
        }
    }void InverterRecursivo() {

        head->proximo = inverterRec(head->proximo, nullptr);

    }No* inverterRec(No* atual, No* anterior){

        if (atual == nullptr){
            return anterior;
        }
        No* proximo = atual->proximo;

        atual->proximo = anterior;

        return inverterRec(proximo, atual);

    }bool ehPalindromoSemBib() {
        // Se a lista está vazia ou tem 1 elemento, é palíndromo.
        if (head->proximo == nullptr || head->proximo->proximo == nullptr) {
            return true;
        }

        // 1. Criar uma "pilha" usando outra ListaEncadiada
        ListaEncadiada listaInvertida;

        // 2. Percorrer a lista original e "empilhar" (addInicio)
        //    na lista invertida.
        No* p = head->proximo;
        while (p != nullptr) {
            listaInvertida.addInicio(p->dado); // Usando addInicio como 'push'
            p = p->proximo;
        }

        // 3. Agora, comparar a lista original com a invertida
        No* pOriginal = head->proximo;
        No* pInvertido = listaInvertida.head->proximo;

        while (pOriginal != nullptr) {
            // Se qualquer valor for diferente, não é palíndromo.
            if (pOriginal->dado != pInvertido->dado) {
                return false;
            }

            // Avança ambas as listas
            pOriginal = pOriginal->proximo;
            pInvertido = pInvertido->proximo;
        }

        // 4. Se o loop terminou, elas são iguais.
        // Nota: Não precisamos nos preocupar com a 'listaInvertida'
        // sendo destruída, o C++ cuidará disso quando a função terminar.
        return true;
    }void removerPosicoes(vector<int>& posicoes) {

        // 1. Ordena as posições em ordem CRESCENTE (ex: {5, 1, 3} -> {1, 3, 5})
        //    Isso é necessário para remover duplicatas corretamente.
        sort(posicoes.begin(), posicoes.end());

        // 2. Remove posições duplicadas (ex: {1, 3, 3, 5} -> {1, 3, 5})
        auto last = unique(posicoes.begin(), posicoes.end());
        posicoes.erase(last, posicoes.end());

        // 3. Re-ordena em ordem DECRESCENTE (ex: {1, 3, 5} -> {5, 3, 1})
        //    Esta é a sua observação inteligente!
        sort(posicoes.begin(), posicoes.end(), std::greater<int>());

        // 4. Agora, remove os elementos um por um.
        //    Como estão em ordem decrescente, os índices
        //    anteriores não são afetados.
        for (int pos : posicoes) {
            removerNesimo(pos);
        }
    }ListaEncadiada dividirEmMetades() {
        No* slow = head;
        No* fast = head;

        // 1. Encontra o meio da lista
        //    (Move 'fast' 2x e 'slow' 1x)
        while (fast != nullptr && fast->proximo != nullptr) {
            fast = fast->proximo->proximo;
            slow = slow->proximo;
        }

        // 2. Cria a nova lista para a segunda metade
        ListaEncadiada segundaMetade;

        // 3. 'slow' está no último nó da primeira metade.
        //    'slow->proximo' é o primeiro nó da segunda metade.
        segundaMetade.head->proximo = slow->proximo;

        // 4. "Corta" a lista original, quebrando a ligação
        slow->proximo = nullptr;

        // 5. Retorna a nova lista
        return segundaMetade;
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