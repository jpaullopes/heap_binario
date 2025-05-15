#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS e malloc/free nos módulos, se necessário

// Nossos cabeçalhos de Heap e Heapsort
#include "max_heap.h" // Já define Paciente
#include "min_heap.h" // Também define Paciente (deve ser idêntica)
#include "heapsort.h" // Usa Paciente de max_heap.h (ou sua própria se max_heap.h não estivesse)

/**
 * @brief Imprime os elementos de um array de Pacientes.
 * @param titulo Uma string para descrever o que está sendo impresso.
 * @param array O array de Pacientes.
 * @param n O número de elementos no array.
 */
void imprimirPacientesArray(const char* titulo, Paciente array[], int n) {
    printf("%s\n", titulo);
    if (n == 0) {
        printf("  (Array vazio)\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        printf("  ID: %2d, Prioridade: %3d\n", array[i].id, array[i].prioridade);
    }
    printf("\n");
}

/**
 * @brief Testa as funcionalidades da Max-Heap.
 */
void testarMaxHeap() {
    printf("--- Testando Max-Heap ---\n");
    MaxHeap *heap = criarMaxHeap(10); // Capacidade para 10 pacientes

    if (!heap) {
        printf("Falha ao criar Max-Heap. Teste abortado.\n");
        return;
    }

    printf("Inserindo pacientes na Max-Heap...\n");
    // Pacientes com diferentes IDs e prioridades
    inserirPacienteMax(heap, (Paciente){1, 70});
    inserirPacienteMax(heap, (Paciente){2, 50});
    inserirPacienteMax(heap, (Paciente){3, 90}); // Maior prioridade
    inserirPacienteMax(heap, (Paciente){4, 60});
    inserirPacienteMax(heap, (Paciente){5, 85});
    inserirPacienteMax(heap, (Paciente){6, 70}); // Prioridade repetida

    printf("\nExtraindo pacientes da Max-Heap (devem sair em ordem de maior prioridade):\n");
    while (!maxHeapVazia(heap)) {
        Paciente p = extrairMaxPacienteHeap(heap);
        if (p.id != -1) { // Checa se não é o paciente inválido de retorno
             printf("  Extraído -> ID: %2d, Prioridade: %3d\n", p.id, p.prioridade);
        }
    }
    printf("\n");

    // Testar inserção após esvaziar
    printf("Inserindo mais pacientes na Max-Heap (após esvaziar)...\n");
    inserirPacienteMax(heap, (Paciente){7, 40});
    inserirPacienteMax(heap, (Paciente){8, 100}); // Nova maior prioridade
    Paciente p_extra = extrairMaxPacienteHeap(heap);
    printf("Extraído após nova inserção -> ID: %2d, Prioridade: %3d\n\n", p_extra.id, p_extra.prioridade);


    liberarMaxHeap(heap);
    printf("Max-Heap liberada.\n");
    printf("-------------------------\n\n");
}

/**
 * @brief Testa as funcionalidades da Min-Heap.
 */
void testarMinHeap() {
    printf("--- Testando Min-Heap ---\n");
    MinHeap *heap = criarMinHeap(10);

    if (!heap) {
        printf("Falha ao criar Min-Heap. Teste abortado.\n");
        return;
    }

    printf("Inserindo pacientes na Min-Heap...\n");
    inserirPacienteMin(heap, (Paciente){11, 70});
    inserirPacienteMin(heap, (Paciente){12, 50});
    inserirPacienteMin(heap, (Paciente){13, 20}); // Menor prioridade
    inserirPacienteMin(heap, (Paciente){14, 60});
    inserirPacienteMin(heap, (Paciente){15, 25});
    inserirPacienteMin(heap, (Paciente){16, 50}); // Prioridade repetida

    printf("\nExtraindo pacientes da Min-Heap (devem sair em ordem de menor prioridade):\n");
    while (!minHeapVazia(heap)) {
        Paciente p = extrairMinPacienteHeap(heap);
         if (p.id != -1) {
            printf("  Extraído -> ID: %2d, Prioridade: %3d\n", p.id, p.prioridade);
        }
    }
    printf("\n");

    // Testar inserção após esvaziar
    printf("Inserindo mais pacientes na Min-Heap (após esvaziar)...\n");
    inserirPacienteMin(heap, (Paciente){17, 40});
    inserirPacienteMin(heap, (Paciente){18, 10}); // Nova menor prioridade
    Paciente p_extra = extrairMinPacienteHeap(heap);
    printf("Extraído após nova inserção -> ID: %2d, Prioridade: %3d\n\n", p_extra.id, p_extra.prioridade);

    liberarMinHeap(heap);
    printf("Min-Heap liberada.\n");
    printf("-------------------------\n\n");
}

/**
 * @brief Testa o algoritmo Heapsort.
 */
void testarHeapsort() {
    printf("--- Testando Heapsort ---\n");
    Paciente pacientes[] = {
        {21, 55}, {22, 22}, {23, 99}, {24, 11}, {25, 77},
        {26, 33}, {27, 88}, {28, 44}, {29, 66}, {30, 5} // Elemento com menor prioridade
    };
    int n = sizeof(pacientes) / sizeof(pacientes[0]);

    imprimirPacientesArray("Array de Pacientes ANTES do Heapsort:", pacientes, n);

    heapsortPacientes(pacientes, n); // Ordena em ordem ascendente de prioridade

    imprimirPacientesArray("Array de Pacientes DEPOIS do Heapsort (prioridade ascendente):", pacientes, n);

    // Teste com array pequeno
    Paciente pacientes_pequeno[] = {{31, 80}, {32, 20}, {33, 50}};
    int n_pequeno = sizeof(pacientes_pequeno) / sizeof(pacientes_pequeno[0]);
    imprimirPacientesArray("Array pequeno ANTES do Heapsort:", pacientes_pequeno, n_pequeno);
    heapsortPacientes(pacientes_pequeno, n_pequeno);
    imprimirPacientesArray("Array pequeno DEPOIS do Heapsort:", pacientes_pequeno, n_pequeno);


    printf("-------------------------\n\n");
}

int main() {
    printf("=====================================================\n");
    printf("Iniciando Testes das Estruturas de Heap e Heapsort para a professora Elanne\n");
    printf("=====================================================\n\n");

    testarMaxHeap();
    testarMinHeap();
    testarHeapsort();

    printf("=====================================================\n");
    printf("Todos os testes foram concluídos.\n");
    printf("=====================================================\n");

    return EXIT_SUCCESS;
}