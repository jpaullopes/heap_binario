#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit

// Estrutura para representar um paciente
// (Idealmente, esta struct viria de um arquivo comum, ex: paciente.h)
typedef struct {
    int id;         // Identificador do paciente
    int prioridade; // Nível de prioridade (menor valor = maior prioridade para MinHeap)
} Paciente;

// Estrutura para a Min-Heap
typedef struct {
    Paciente *array; // Ponteiro para o array de pacientes
    int tamanho;     // Número atual de pacientes na heap
    int capacidade;  // Capacidade máxima da heap
} MinHeap;

/**
 * @brief Cria uma nova Min-Heap.
 * @param capacidade A capacidade máxima da heap.
 * @return Ponteiro para a MinHeap criada, ou NULL em caso de falha.
 */
MinHeap* criarMinHeap(int capacidade);

/**
 * @brief Insere um paciente na Min-Heap.
 * A propriedade da heap é mantida.
 * @param heap Ponteiro para a MinHeap.
 * @param p O Paciente a ser inserido.
 */
void inserirPacienteMin(MinHeap *heap, Paciente p);

/**
 * @brief Extrai e retorna o paciente com a menor prioridade da Min-Heap.
 * A propriedade da heap é mantida.
 * @param heap Ponteiro para a MinHeap.
 * @return O Paciente com a menor prioridade. Se a heap estiver vazia,
 * retorna um Paciente com id e prioridade -1.
 */
Paciente extrairMinPacienteHeap(MinHeap *heap);

/**
 * @brief Verifica se a Min-Heap está vazia.
 * @param heap Ponteiro para a MinHeap.
 * @return 1 se a heap estiver vazia, 0 caso contrário.
 */
int minHeapVazia(MinHeap *heap);

/**
 * @brief Libera a memória alocada para a Min-Heap.
 * @param heap Ponteiro para a MinHeap a ser liberada.
 */
void liberarMinHeap(MinHeap *heap);

#endif // MIN_HEAP_H