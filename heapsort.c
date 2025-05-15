#include "heapsort.h" // Já inclui max_heap.h transitivamente

// Não precisamos mais das versões estáticas de trocarHeapsort e heapifyDownHeapsort aqui,
// pois usaremos as versões públicas de max_heap.c

void heapsortPacientes(Paciente array[], int n) {
    if (n <= 1) {
        return;
    }

    // 1. Construir a Max-Heap (reorganizar o array)
    // Chama a função heapifyDownMaxArray exposta por max_heap.c
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyDownMaxArray(array, n, i);
    }

    // 2. Extrair elementos um por um da heap
    for (int i = n - 1; i > 0; i--) {
        // Mover a raiz atual (maior elemento) para o final do array
        // Chama a função trocarPacientes exposta por max_heap.c
        trocarPacientes(&array[0], &array[i]);

        // Chamar heapifyDownMaxArray na heap reduzida
        heapifyDownMaxArray(array, i, 0);
    }
}