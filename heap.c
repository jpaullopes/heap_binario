#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Para INT_MIN em extractMax em caso de erro

// Estrutura para o Max-Heap
typedef struct {
    int *arr;     // Ponteiro para o array de elementos do heap
    int capacity; // Capacidade máxima do heap
    int size;     // Número atual de elementos no heap
} MaxHeap;

// Função para criar um Max-Heap com uma dada capacidade
MaxHeap* createHeap(int capacity) {
    MaxHeap* heap = (MaxHeap*)malloc(sizeof(MaxHeap));
    if (!heap) {
        perror("Erro ao alocar memória para o heap");
        return NULL;
    }
    heap->arr = (int*)malloc(capacity * sizeof(int));
    if (!heap->arr) {
        perror("Erro ao alocar memória para o array do heap");
        free(heap);
        return NULL;
    }
    heap->capacity = capacity;
    heap->size = 0;
    return heap;
}

// Funções auxiliares para obter índices
int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

// Função auxiliar para trocar dois inteiros
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Função para manter a propriedade do Max-Heap subindo (para inserção)
void heapifyUp(MaxHeap* heap, int index) {
    // Enquanto o nó atual não for a raiz e for maior que seu pai
    while (index > 0 && heap->arr[index] > heap->arr[parent(index)]) {
        swap(&heap->arr[index], &heap->arr[parent(index)]);
        index = parent(index); // Move para o índice do pai
    }
}

// Função para inserir um novo elemento no Max-Heap
void insert(MaxHeap* heap, int key) {
    if (heap->size == heap->capacity) {
        printf("Erro: Heap cheio. Não é possível inserir %d.\n", key);
        return;
    }

    // Insere o novo elemento no final do array
    heap->size++;
    int index = heap->size - 1;
    heap->arr[index] = key;

    // Corrige a propriedade do Max-Heap subindo a partir do novo elemento
    heapifyUp(heap, index);
    printf("%d inserido no heap.\n", key);
}

// Função para manter a propriedade do Max-Heap descendo (para extração e construção)
void heapifyDown(MaxHeap* heap, int index) {
    int maxIndex = index;
    int l = leftChild(index);
    int r = rightChild(index);

    // Verifica se o filho esquerdo existe e é maior que o nó atual
    if (l < heap->size && heap->arr[l] > heap->arr[maxIndex]) {
        maxIndex = l;
    }

    // Verifica se o filho direito existe e é maior que o maior encontrado até agora
    if (r < heap->size && heap->arr[r] > heap->arr[maxIndex]) {
        maxIndex = r;
    }

    // Se o maior não for o nó atual, troca e continua o heapifyDown recursivamente
    if (index != maxIndex) {
        swap(&heap->arr[index], &heap->arr[maxIndex]);
        heapifyDown(heap, maxIndex);
    }
}

// Função para remover e retornar o maior elemento do Max-Heap (a raiz)
int extractMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Erro: Heap vazio.\n");
        return INT_MIN; // Retorna um valor mínimo para indicar erro
    }
    if (heap->size == 1) {
        heap->size--;
        return heap->arr[0];
    }

    // Armazena o valor da raiz (o máximo)
    int root = heap->arr[0];

    // Substitui a raiz pelo último elemento do heap
    heap->arr[0] = heap->arr[heap->size - 1];
    heap->size--;

    // Corrige a propriedade do Max-Heap descendo a partir da raiz
    heapifyDown(heap, 0);

    return root;
}

// Função para obter o maior elemento do Max-Heap (a raiz) sem removê-lo
int getMax(MaxHeap* heap) {
    if (heap->size <= 0) {
        printf("Erro: Heap vazio.\n");
        return INT_MIN; // Retorna um valor mínimo para indicar erro
    }
    return heap->arr[0];
}

// Função para construir um Max-Heap a partir de um array
// Esta função é mais eficiente (O(n)) do que inserir elementos um por um (O(n log n))
void buildHeap(MaxHeap* heap, int* array, int n) {
    if (n > heap->capacity) {
        printf("Erro: Capacidade do heap insuficiente para construir a partir do array.\n");
        return;
    }
    heap->size = n;
    for (int i = 0; i < n; i++) {
        heap->arr[i] = array[i];
    }

    // Começa o heapifyDown a partir do último nó não-folha
    // O último nó não-folha está no índice (n/2) - 1
    for (int i = (heap->size / 2) - 1; i >= 0; i--) {
        heapifyDown(heap, i);
    }
    printf("Heap construído a partir do array.\n");
}


// Função para imprimir os elementos do heap (representação em array)
void printHeap(MaxHeap* heap) {
    if (heap->size == 0) {
        printf("Heap está vazio.\n");
        return;
    }
    printf("Elementos do Heap (Max-Heap): ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

// Função para liberar a memória alocada para o heap
void destroyHeap(MaxHeap* heap) {
    if (heap) {
        if (heap->arr) {
            free(heap->arr);
        }
        free(heap);
    }
    printf("Heap destruído.\n");
}

// Função principal para demonstrar as operações do Max-Heap
int main() {
    // Cria um Max-Heap com capacidade 10
    MaxHeap* heap = createHeap(10);
    if (!heap) {
        return 1; // Termina se a criação do heap falhar
    }

    printf("--- Testando Inserções ---\n");
    insert(heap, 10);
    printHeap(heap);
    insert(heap, 20);
    printHeap(heap);
    insert(heap, 5);
    printHeap(heap);
    insert(heap, 30);
    printHeap(heap);
    insert(heap, 15);
    printHeap(heap);

    printf("\nMaior elemento atual (getMax): %d\n", getMax(heap));

    printf("\n--- Testando Extrações ---\n");
    printf("Extraído: %d\n", extractMax(heap));
    printHeap(heap);
    printf("Extraído: %d\n", extractMax(heap));
    printHeap(heap);

    printf("\nMaior elemento atual (getMax): %d\n", getMax(heap));

    printf("\n--- Testando Inserções Adicionais ---\n");
    insert(heap, 50);
    printHeap(heap);
    insert(heap, 3);
    printHeap(heap);

    printf("\n--- Testando Extração até esvaziar ---\n");
    while (heap->size > 0) {
        printf("Extraído: %d\n", extractMax(heap));
        printHeap(heap);
    }

    // Tenta extrair de um heap vazio
    printf("Tentando extrair de um heap vazio: %d\n", extractMax(heap));

    // Libera a memória do primeiro heap
    destroyHeap(heap);

    printf("\n--- Testando buildHeap ---\n");
    MaxHeap* heap2 = createHeap(10);
    if(!heap2) return 1;

    int arr_example[] = {4, 10, 3, 5, 1, 12, 9};
    int n_example = sizeof(arr_example) / sizeof(arr_example[0]);

    buildHeap(heap2, arr_example, n_example);
    printHeap(heap2);

    printf("Extraído de heap2: %d\n", extractMax(heap2));
    printHeap(heap2);

    destroyHeap(heap2);


    return 0;
}