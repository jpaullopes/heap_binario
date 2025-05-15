#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit

// Estrutura para representar um paciente
typedef struct {
    int id;         // Identificador do paciente
    int prioridade; // Nível de prioridade (maior valor = maior prioridade)
} Paciente;

// Estrutura para a Max-Heap
typedef struct {
    Paciente *array; // Ponteiro para o array de pacientes
    int tamanho;     // Número atual de pacientes na heap
    int capacidade;  // Capacidade máxima da heap
} MaxHeap;

/**
 * @brief Cria uma nova Max-Heap.
 * @param capacidade A capacidade máxima da heap.
 * @return Ponteiro para a MaxHeap criada, ou NULL em caso de falha.
 */
MaxHeap* criarMaxHeap(int capacidade);

/**
 * @brief Insere um paciente na Max-Heap.
 * A propriedade da heap é mantida.
 * @param heap Ponteiro para a MaxHeap.
 * @param p O Paciente a ser inserido.
 */
void inserirPacienteMax(MaxHeap *heap, Paciente p);

/**
 * @brief Extrai e retorna o paciente com a maior prioridade da Max-Heap.
 * A propriedade da heap é mantida.
 * @param heap Ponteiro para a MaxHeap.
 * @return O Paciente com a maior prioridade. Se a heap estiver vazia,
 * retorna um Paciente com id e prioridade -1.
 */
Paciente extrairMaxPacienteHeap(MaxHeap *heap);

/**
 * @brief Verifica se a Max-Heap está vazia.
 * @param heap Ponteiro para a MaxHeap.
 * @return 1 se a heap estiver vazia, 0 caso contrário.
 */
int maxHeapVazia(MaxHeap *heap);

/**
 * @brief Libera a memória alocada para a Max-Heap.
 * @param heap Ponteiro para a MaxHeap a ser liberada.
 */
void liberarMaxHeap(MaxHeap *heap);

#endif // MAX_HEAP_H