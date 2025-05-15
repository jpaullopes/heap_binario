#include "min_heap.h"

// Funções auxiliares (estáticas)

/**
 * @brief Retorna o índice do pai do nó i.
 * @param i Índice do nó.
 * @return Índice do pai.
 */
static int paiMin(int i) {
    return (i - 1) / 2;
}

/**
 * @brief Retorna o índice do filho esquerdo do nó i.
 * @param i Índice do nó.
 * @return Índice do filho esquerdo.
 */
static int filhoEsquerdaMin(int i) {
    return (2 * i) + 1;
}

/**
 * @brief Retorna o índice do filho direito do nó i.
 * @param i Índice do nó.
 * @return Índice do filho direito.
 */
static int filhoDireitaMin(int i) {
    return (2 * i) + 2;
}

/**
 * @brief Troca dois Pacientes de lugar.
 * @param a Ponteiro para o primeiro Paciente.
 * @param b Ponteiro para o segundo Paciente.
 */
static void trocarMin(Paciente *a, Paciente *b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Mantém a propriedade da Min-Heap "subindo" a partir de um índice.
 * Usado após inserção.
 * @param heap Ponteiro para a MinHeap.
 * @param index Índice a partir do qual verificar e corrigir a heap.
 */
static void heapifyUpMin(MinHeap *heap, int index) {
    // Sobe se o pai for MAIOR que o filho (MinHeap)
    while (index > 0 && heap->array[paiMin(index)].prioridade > heap->array[index].prioridade) {
        trocarMin(&heap->array[paiMin(index)], &heap->array[index]);
        index = paiMin(index);
    }
}

/**
 * @brief Mantém a propriedade da Min-Heap "descendo" a partir de um índice.
 * Usado após extração do mínimo.
 * @param heap Ponteiro para a MinHeap.
 * @param index Índice a partir do qual verificar e corrigir a heap.
 */
static void heapifyDownMin(MinHeap *heap, int index) {
    int minIndex = index;
    int esq = filhoEsquerdaMin(index);
    int dir = filhoDireitaMin(index);

    // Procura o MENOR entre o nó atual e seus filhos
    if (esq < heap->tamanho && heap->array[esq].prioridade < heap->array[minIndex].prioridade) {
        minIndex = esq;
    }
    if (dir < heap->tamanho && heap->array[dir].prioridade < heap->array[minIndex].prioridade) {
        minIndex = dir;
    }

    if (index != minIndex) {
        trocarMin(&heap->array[index], &heap->array[minIndex]);
        heapifyDownMin(heap, minIndex);
    }
}

// Implementações das funções públicas

MinHeap* criarMinHeap(int capacidade) {
    MinHeap *heap = (MinHeap*) malloc(sizeof(MinHeap));
    if (heap == NULL) {
        perror("Falha ao alocar memória para heap (MinHeap)");
        return NULL;
    }
    heap->array = (Paciente*) malloc(capacidade * sizeof(Paciente));
    if (heap->array == NULL) {
        perror("Falha ao alocar memória para o array da heap (MinHeap)");
        free(heap);
        return NULL;
    }
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void inserirPacienteMin(MinHeap *heap, Paciente p) {
    if (heap == NULL) return;
    if (heap->tamanho == heap->capacidade) {
        printf("Heap (MinHeap) está cheia. Não é possível inserir paciente ID %d.\n", p.id);
        return;
    }
    heap->array[heap->tamanho] = p;
    heap->tamanho++;
    heapifyUpMin(heap, heap->tamanho - 1);
}

Paciente extrairMinPacienteHeap(MinHeap *heap) {
    Paciente pVazio = {-1, -1};
    if (heap == NULL || heap->tamanho <= 0) {
        // printf("Heap (MinHeap) está vazia. Não é possível extrair.\n");
        return pVazio;
    }
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->array[0];
    }

    Paciente raiz = heap->array[0]; // Salva o mínimo
    heap->array[0] = heap->array[heap->tamanho - 1]; // Move o último para a raiz
    heap->tamanho--;
    heapifyDownMin(heap, 0); // Restaura a propriedade da heap

    return raiz;
}

int minHeapVazia(MinHeap *heap) {
    if (heap == NULL) return 1;
    return heap->tamanho == 0;
}

void liberarMinHeap(MinHeap *heap) {
    if (heap != NULL) {
        if (heap->array != NULL) {
            free(heap->array);
        }
        free(heap);
    }
}