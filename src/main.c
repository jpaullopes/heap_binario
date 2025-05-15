#include <stdio.h>
#include <stdlib.h> // Para EXIT_SUCCESS

#include "max_heap/max_heap.h" 
#include "min_heap/min_heap.h" 
#include "heapsort/heapsort.h" 

/**
 * @brief Imprime os elementos de um array de Pacientes.
 * @param titulo Uma string para descrever o que está sendo impresso.
 * @param array O array de Pacientes.
 * @param n O número de elementos no array.
 */
void imprimirPacientesArray(const char* titulo, Paciente array[], int n) {
    printf("%s\n", titulo);
    if (n <= 0) { // Alterado para n <= 0 para cobrir array vazio de forma mais robusta
        printf("  (Array vazio ou inválido)\n");
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
    MaxHeap *heap = criarMaxHeap(5); // Capacidade menor para testar limite

    if (!heap) {
        printf("Falha ao criar Max-Heap. Teste abortado.\n");
        return;
    }

    printf("Inserindo pacientes na Max-Heap...\n");
    inserirPacienteMax(heap, (Paciente){1, 70});
    inserirPacienteMax(heap, (Paciente){2, 50});
    inserirPacienteMax(heap, (Paciente){3, 90});
    inserirPacienteMax(heap, (Paciente){4, 60});
    inserirPacienteMax(heap, (Paciente){5, 85});

    // Teste de inserção em heap cheia
    printf("\nTentando inserir em Max-Heap cheia:\n");
    inserirPacienteMax(heap, (Paciente){99, 100}); // Deve falhar ou avisar


    printf("\nExtraindo pacientes da Max-Heap (devem sair em ordem de maior prioridade):\n");
    while (!maxHeapVazia(heap)) {
        Paciente p = extrairMaxPacienteHeap(heap);
        if (p.id != -1) {
             printf("  Extraído -> ID: %2d, Prioridade: %3d\n", p.id, p.prioridade);
        }
    }
    printf("\n");

    // Teste de extração de heap vazia
    printf("Tentando extrair de Max-Heap vazia:\n");
    Paciente pVazia = extrairMaxPacienteHeap(heap);
    if (pVazia.id == -1) {
        printf("  Corretamente retornou paciente inválido de heap vazia.\n\n");
    } else {
        printf("  ERRO: Deveria ter retornado paciente inválido de heap vazia.\n\n");
    }

    printf("Inserindo mais pacientes na Max-Heap (após esvaziar)...\n");
    inserirPacienteMax(heap, (Paciente){7, 40});
    inserirPacienteMax(heap, (Paciente){8, 100});
    Paciente p_extra = extrairMaxPacienteHeap(heap);
    if (p_extra.id != -1) {
        printf("Extraído após nova inserção -> ID: %2d, Prioridade: %3d\n\n", p_extra.id, p_extra.prioridade);
    }

    liberarMaxHeap(heap);
    printf("Max-Heap liberada.\n");
    printf("-------------------------\n\n");
}

/**
 * @brief Testa as funcionalidades da Min-Heap.
 */
void testarMinHeap() {
    printf("--- Testando Min-Heap ---\n");
    MinHeap *heap = criarMinHeap(5); // Capacidade menor para testar limite

    if (!heap) {
        printf("Falha ao criar Min-Heap. Teste abortado.\n");
        return;
    }

    printf("Inserindo pacientes na Min-Heap...\n");
    inserirPacienteMin(heap, (Paciente){11, 70});
    inserirPacienteMin(heap, (Paciente){12, 50});
    inserirPacienteMin(heap, (Paciente){13, 20});
    inserirPacienteMin(heap, (Paciente){14, 60});
    inserirPacienteMin(heap, (Paciente){15, 25});

    // Teste de inserção em heap cheia
    printf("\nTentando inserir em Min-Heap cheia:\n");
    inserirPacienteMin(heap, (Paciente){98, 5}); // Deve falhar ou avisar

    printf("\nExtraindo pacientes da Min-Heap (devem sair em ordem de menor prioridade):\n");
    while (!minHeapVazia(heap)) {
        Paciente p = extrairMinPacienteHeap(heap);
         if (p.id != -1) {
            printf("  Extraído -> ID: %2d, Prioridade: %3d\n", p.id, p.prioridade);
        }
    }
    printf("\n");

    // Teste de extração de heap vazia
    printf("Tentando extrair de Min-Heap vazia:\n");
    Paciente pVazia = extrairMinPacienteHeap(heap);
    if (pVazia.id == -1) {
        printf("  Corretamente retornou paciente inválido de heap vazia.\n\n");
    } else {
        printf("  ERRO: Deveria ter retornado paciente inválido de heap vazia.\n\n");
    }

    printf("Inserindo mais pacientes na Min-Heap (após esvaziar)...\n");
    inserirPacienteMin(heap, (Paciente){17, 40});
    inserirPacienteMin(heap, (Paciente){18, 10});
    Paciente p_extra = extrairMinPacienteHeap(heap);
    if (p_extra.id != -1) {
        printf("Extraído após nova inserção -> ID: %2d, Prioridade: %3d\n\n", p_extra.id, p_extra.prioridade);
    }
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
        {26, 33}, {27, 88}, {28, 44}, {29, 66}, {30, 5}
    };
    int n = sizeof(pacientes) / sizeof(pacientes[0]);

    imprimirPacientesArray("Array de Pacientes ANTES do Heapsort:", pacientes, n);
    heapsortPacientes(pacientes, n);
    imprimirPacientesArray("Array de Pacientes DEPOIS do Heapsort (prioridade ascendente):", pacientes, n);

    // Teste com array pequeno
    printf("Teste Heapsort com array pequeno:\n");
    Paciente pacientes_pequeno[] = {{31, 80}, {32, 20}, {33, 50}};
    int n_pequeno = sizeof(pacientes_pequeno) / sizeof(pacientes_pequeno[0]);
    imprimirPacientesArray("  Array pequeno ANTES:", pacientes_pequeno, n_pequeno);
    heapsortPacientes(pacientes_pequeno, n_pequeno);
    imprimirPacientesArray("  Array pequeno DEPOIS:", pacientes_pequeno, n_pequeno);

    // Teste com array de um elemento
    printf("Teste Heapsort com array de um elemento:\n");
    Paciente pacientes_um[] = {{41, 100}};
    int n_um = sizeof(pacientes_um) / sizeof(pacientes_um[0]);
    imprimirPacientesArray("  Array de um elemento ANTES:", pacientes_um, n_um);
    heapsortPacientes(pacientes_um, n_um);
    imprimirPacientesArray("  Array de um elemento DEPOIS:", pacientes_um, n_um);

    // Teste com array vazio
    printf("Teste Heapsort com array vazio:\n");
    Paciente pacientes_vazio[] = {}; // Array vazio
    int n_vazio = 0; // sizeof retorna 0 para array vazio em alguns compiladores, melhor ser explícito
    imprimirPacientesArray("  Array vazio ANTES:", pacientes_vazio, n_vazio);
    heapsortPacientes(pacientes_vazio, n_vazio);
    imprimirPacientesArray("  Array vazio DEPOIS:", pacientes_vazio, n_vazio);

    printf("-------------------------\n\n");
}

int main() {
    printf("=====================================================\n");
    // A mensagem original mencionava a professora Elanne, você pode ajustar conforme necessário.
    printf("Iniciando Testes das Estruturas de Heap e Heapsort\n");
    printf("=====================================================\n\n");

    testarMaxHeap();
    testarMinHeap();
    testarHeapsort();

    printf("=====================================================\n");
    printf("Todos os testes foram concluídos.\n");
    printf("=====================================================\n");

    return EXIT_SUCCESS;
}