#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit
#include "includes\paciente.h" // Inclui a definição da struct Paciente

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

/**
 * @brief Troca dois Pacientes de lugar.
 * Função utilitária que pode ser usada externamente.
 * @param a Ponteiro para o primeiro Paciente.
 * @param b Ponteiro para o segundo Paciente.
 */
void trocarPacientes(Paciente *a, Paciente *b);

/**
 * @brief Restaura a propriedade de Max-Heap para uma subárvore representada
 * em um array, com raiz em 'i'.
 * Usada pelo Heapsort e pode ser útil para outras manipulações de array como heap.
 *
 * @param array O array de Pacientes.
 * @param n O tamanho da porção do array considerada como heap.
 * @param i O índice da raiz da subárvore a ser "heapificada".
 */
void heapifyDownMaxArray(Paciente array[], int n, int i);

#endif // MAX_HEAP_H