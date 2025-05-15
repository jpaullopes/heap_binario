#ifndef HEAPSORT_H
#define HEAPSORT_H

// Inclui max_heap.h para ter acesso à struct Paciente e às novas funções públicas
#include "max_heap/max_heap.h"

/**
 * @brief Ordena um array de Pacientes usando o algoritmo Heapsort.
 * A ordenação é feita in-place e em ordem ascendente de prioridade.
 * Utiliza funções do módulo max_heap para operações de heapify e troca.
 *
 * @param array O array de Pacientes a ser ordenado.
 * @param n O número de elementos no array.
 */
void heapsortPacientes(Paciente array[], int n);

#endif // HEAPSORT_H