#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Pilha {

    No *topo;
    int n;

    Pilha() {
        topo = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (topo == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            topo = novo;
        } else {
            novo->prox = topo;
            topo = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = topo;
                topo = NULL;
                delete(aux);
            } else {
                No *aux = topo;
                topo = topo->prox;
                delete(aux);
            }
            n--;
        }
    }
};


struct Fila {
    No *cabeca, *cauda;
    int n;

    Fila() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserir(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    int tamanho() { // O(1)
        return n;
    }

    void remover() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }
};

void inverterFila(Fila& fila) {
    Pilha pilha;

    // Movendo os elementos da fila para a pilha
    while (!fila.vazia()) {
        pilha.inserir(fila.cabeca->valor);
        fila.remover();
    }

    // Movendo os elementos da pilha de volta para a fila
    while (!pilha.vazia()) {
        fila.inserir(pilha.topo->valor);
        pilha.remover();
    }
}


int main() {
    Fila f;
    Pilha p;

    p.inserir(10);
    p.inserir(20);
    p.inserir(30);
    p.remover();
    p.remover();
    p.remover();

    f.inserir(10);
    f.inserir(20);
    f.inserir(30);

    inverterFila(f);

    // Imprimindo os elementos da fila invertida
    while (!f.vazia()) {
        printf("%d ", f.cabeca->valor);
        f.remover();
    }

    return 0;
}
