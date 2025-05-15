#include "max_heap.h"

// Funções auxiliares (estáticas, não visíveis fora deste arquivo)

/**
 * @brief Retorna o índice do pai do nó i.
 * @param i Índice do nó.
 * @return Índice do pai.
 */
static int paiMax(int i) {
    return (i - 1) / 2;
}

/**
 * @brief Retorna o índice do filho esquerdo do nó i.
 * @param i Índice do nó.
 * @return Índice do filho esquerdo.
 */
static int filhoEsquerdaMax(int i) {
    return (2 * i) + 1;
}

/**
 * @brief Retorna o índice do filho direito do nó i.
 * @param i Índice do nó.
 * @return Índice do filho direito.
 */
static int filhoDireitaMax(int i) {
    return (2 * i) + 2;
}

/**
 * @brief Troca dois Pacientes de lugar.
 * @param a Ponteiro para o primeiro Paciente.
 * @param b Ponteiro para o segundo Paciente.
 */
static void trocarMax(Paciente *a, Paciente *b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Mantém a propriedade da Max-Heap "subindo" a partir de um índice.
 * Usado após inserção.
 * @param heap Ponteiro para a MaxHeap.
 * @param index Índice a partir do qual verificar e corrigir a heap.
 */
static void heapifyUpMax(MaxHeap *heap, int index) {
    while (index > 0 && heap->array[paiMax(index)].prioridade < heap->array[index].prioridade) {
        trocarMax(&heap->array[paiMax(index)], &heap->array[index]);
        index = paiMax(index);
    }
}

/**
 * @brief Mantém a propriedade da Max-Heap "descendo" a partir de um índice.
 * Usado após extração do máximo.
 * @param heap Ponteiro para a MaxHeap.
 * @param index Índice a partir do qual verificar e corrigir a heap.
 */
static void heapifyDownMax(MaxHeap *heap, int index) {
    int maxIndex = index;
    int esq = filhoEsquerdaMax(index);
    int dir = filhoDireitaMax(index);

    if (esq < heap->tamanho && heap->array[esq].prioridade > heap->array[maxIndex].prioridade) {
        maxIndex = esq;
    }
    if (dir < heap->tamanho && heap->array[dir].prioridade > heap->array[maxIndex].prioridade) {
        maxIndex = dir;
    }

    if (index != maxIndex) {
        trocarMax(&heap->array[index], &heap->array[maxIndex]);
        heapifyDownMax(heap, maxIndex);
    }
}

// Implementações das funções públicas

MaxHeap* criarMaxHeap(int capacidade) {
    MaxHeap *heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    if (heap == NULL) {
        perror("Falha ao alocar memória para heap (MaxHeap)");
        return NULL; // Retorna NULL em caso de falha na alocação da struct
    }
    heap->array = (Paciente*) malloc(capacidade * sizeof(Paciente));
    if (heap->array == NULL) {
        perror("Falha ao alocar memória para o array da heap (MaxHeap)");
        free(heap); // Libera a struct da heap se o array falhar
        return NULL; // Retorna NULL em caso de falha na alocação do array
    }
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void inserirPacienteMax(MaxHeap *heap, Paciente p) {
    if (heap == NULL) return;
    if (heap->tamanho == heap->capacidade) {
        // Idealmente, redimensionar o array ou tratar o erro de forma mais robusta
        printf("Heap (MaxHeap) está cheia. Não é possível inserir paciente ID %d.\n", p.id);
        return;
    }
    // Insere no final e depois sobe para a posição correta
    heap->array[heap->tamanho] = p;
    heap->tamanho++;
    heapifyUpMax(heap, heap->tamanho - 1);
}

Paciente extrairMaxPacienteHeap(MaxHeap *heap) {
    Paciente pVazio = {-1, -1}; // Paciente inválido para retorno em caso de erro/vazio
    if (heap == NULL || heap->tamanho <= 0) {
        // printf("Heap (MaxHeap) está vazia. Não é possível extrair.\n"); // Opcional: log silencioso
        return pVazio;
    }
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->array[0];
    }

    Paciente raiz = heap->array[0]; // Salva o máximo
    heap->array[0] = heap->array[heap->tamanho - 1]; // Move o último para a raiz
    heap->tamanho--;
    heapifyDownMax(heap, 0); // Restaura a propriedade da heap

    return raiz;
}

int maxHeapVazia(MaxHeap *heap) {
    if (heap == NULL) return 1; // Considera NULL como vazio
    return heap->tamanho == 0;
}

void liberarMaxHeap(MaxHeap *heap) {
    if (heap != NULL) {
        if (heap->array != NULL) {
            free(heap->array);
        }
        free(heap);
    }
}