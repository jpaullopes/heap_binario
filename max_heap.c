#include "max_heap.h"

// Funções auxiliares estáticas (paiMax, filhoEsquerdaMax, filhoDireitaMax) permanecem as mesmas
static int paiMax(int i) {
    return (i - 1) / 2;
}

static int filhoEsquerdaMax(int i) {
    return (2 * i) + 1;
}

static int filhoDireitaMax(int i) {
    return (2 * i) + 2;
}

// A função trocarMax agora é pública como trocarPacientes
void trocarPacientes(Paciente *a, Paciente *b) {
    Paciente temp = *a;
    *a = *b;
    *b = temp;
}

// heapifyUpMax permanece static pois é específica da inserção na struct MaxHeap
static void heapifyUpMax(MaxHeap *heap, int index) {
    while (index > 0 && heap->array[paiMax(index)].prioridade < heap->array[index].prioridade) {
        trocarPacientes(&heap->array[paiMax(index)], &heap->array[index]); // Usa a nova função pública/compartilhada
        index = paiMax(index);
    }
}

// heapifyDownMax (original, para a struct) agora pode usar a versão de array ou ser mantida
// Para clareza, vamos manter a original que opera na struct MaxHeap e usa heap->tamanho
static void heapifyDownMaxStruct(MaxHeap *heap, int index) {
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
        trocarPacientes(&heap->array[index], &heap->array[maxIndex]); // Usa a nova função pública/compartilhada
        heapifyDownMaxStruct(heap, maxIndex);
    }
}


// --- IMPLEMENTAÇÃO DA NOVA FUNÇÃO PÚBLICA ---
void heapifyDownMaxArray(Paciente array[], int n, int i) {
    int maior = i;
    int esquerda = filhoEsquerdaMax(i); // Reutiliza as funções de índice
    int direita = filhoDireitaMax(i);

    if (esquerda < n && array[esquerda].prioridade > array[maior].prioridade) {
        maior = esquerda;
    }
    if (direita < n && array[direita].prioridade > array[maior].prioridade) {
        maior = direita;
    }
    if (maior != i) {
        trocarPacientes(&array[i], &array[maior]); // Usa a função de troca pública
        heapifyDownMaxArray(array, n, maior);
    }
}

// Implementações das funções públicas existentes (criarMaxHeap, etc.)
// (Importante: Elas agora usariam heapifyDownMaxStruct internamente se necessário)

MaxHeap* criarMaxHeap(int capacidade) {
    MaxHeap *heap = (MaxHeap*) malloc(sizeof(MaxHeap));
    if (heap == NULL) {
        perror("Falha ao alocar memória para heap (MaxHeap)");
        return NULL;
    }
    heap->array = (Paciente*) malloc(capacidade * sizeof(Paciente));
    if (heap->array == NULL) {
        perror("Falha ao alocar memória para o array da heap (MaxHeap)");
        free(heap);
        return NULL;
    }
    heap->tamanho = 0;
    heap->capacidade = capacidade;
    return heap;
}

void inserirPacienteMax(MaxHeap *heap, Paciente p) {
    if (heap == NULL) return;
    if (heap->tamanho == heap->capacidade) {
        printf("Heap (MaxHeap) está cheia. Não é possível inserir paciente ID %d.\n", p.id);
        return;
    }
    heap->array[heap->tamanho] = p;
    heap->tamanho++;
    heapifyUpMax(heap, heap->tamanho - 1); // heapifyUpMax continua usando a struct
}

Paciente extrairMaxPacienteHeap(MaxHeap *heap) {
    Paciente pVazio = {-1, -1};
    if (heap == NULL || heap->tamanho <= 0) {
        return pVazio;
    }
    if (heap->tamanho == 1) {
        heap->tamanho--;
        return heap->array[0];
    }
    Paciente raiz = heap->array[0];
    heap->array[0] = heap->array[heap->tamanho - 1];
    heap->tamanho--;
    heapifyDownMaxStruct(heap, 0); // Usa a versão que opera na struct MaxHeap
    return raiz;
}

int maxHeapVazia(MaxHeap *heap) {
    if (heap == NULL) return 1;
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