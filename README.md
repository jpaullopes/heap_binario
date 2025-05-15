# Projeto de Implementação de Heap: Fila de Prioridade Hospitalar 🏥

## Descrição 📝

Este projeto consiste na implementação das estruturas de dados Max-Heap e Min-Heap em linguagem C. O objetivo é demonstrar o funcionamento e as aplicações de heaps, utilizando como contexto principal a gestão de uma fila de prioridade de pacientes em um ambiente hospitalar. A Max-Heap é utilizada para gerenciar pacientes onde a maior prioridade numérica indica maior urgência, enquanto a Min-Heap pode ser adaptada para cenários onde a menor prioridade numérica é processada primeiro (ex: menor tempo de espera, ordem de chegada com prioridade mínima).

## Estrutura de Dados: Heap Binária 🌳

Uma **Heap Binária** é uma estrutura de dados baseada em árvore binária completa que satisfaz a propriedade da heap:

* **Max-Heap:** O valor de cada nó pai é maior ou igual aos valores de seus filhos. O maior elemento está sempre na raiz.
* **Min-Heap:** O valor de cada nó pai é menor ou igual aos valores de seus filhos. O menor elemento está sempre na raiz.

Nesta implementação, a heap é representada utilizando um array para maior eficiência de acesso e manipulação dos elementos, seguindo a abordagem padrão.

## Funcionalidades Implementadas ✅

O projeto inclui módulos separados para Max-Heap e Min-Heap, além de uma estrutura comum para os pacientes e um algoritmo de ordenação Heapsort.

### Paciente (`paciente.h`) 👨‍⚕️

Uma estrutura `Paciente` é definida no arquivo `paciente.h` para armazenar os dados relevantes. Este arquivo é incluído pelos módulos de heap e heapsort.

```c
// Definição em paciente.h
typedef struct {
    int id;
    int prioridade;
} Paciente;
```

### Max-Heap (`max_heap.h`, `max_heap.c`) ⬆️

Ideal para cenários onde o maior valor de prioridade deve ser atendido primeiro.

* `criarMaxHeap(capacidade)`: Aloca e inicializa uma nova Max-Heap.
* `inserirPacienteMax(heap, paciente)`: Insere um novo paciente na heap, mantendo a propriedade de Max-Heap.
* `extrairMaxPacienteHeap(heap)`: Remove e retorna o paciente com a maior prioridade.
* `maxHeapVazia(heap)`: Verifica se a heap está vazia.
* `liberarMaxHeap(heap)`: Libera toda a memória alocada para a heap.
* `trocarPacientes(pacienteA, pacienteB)`: Função utilitária (pública) para trocar dois pacientes.
* `heapifyDownMaxArray(array, tamanho, indice)`: Função utilitária (pública) para aplicar o heapify down em um array.

### Min-Heap (`min_heap.h`, `min_heap.c`) 🔻

Ideal para cenários onde o menor valor de prioridade deve ser atendido primeiro.

* `criarMinHeap(capacidade)`: Aloca e inicializa uma nova Min-Heap.
* `inserirPacienteMin(heap, paciente)`: Insere um novo paciente na heap, mantendo a propriedade de Min-Heap.
* `extrairMinPacienteHeap(heap)`: Remove e retorna o paciente com a menor prioridade.
* `minHeapVazia(heap)`: Verifica se a heap está vazia.
* `liberarMinHeap(heap)`: Libera toda a memória alocada para a heap.

### Heapsort (`heapsort.h`, `heapsort.c`) 🔢

Ordenação em ordem crescente de prioridade.

* `heapsortPacientes(array, tamanho)`: Ordena um array de pacientes utilizando o algoritmo Heapsort (baseado em Max-Heap para ordenação ascendente).

## Estrutura dos Arquivos 🗂️

O projeto está organizado da seguinte forma:

```
heap_binario/
│
├── src/
│   ├── includes/
│   │   └── paciente.h
│   ├── max_heap/
│   │   ├── max_heap.h
│   │   └── max_heap.c
│   ├── min_heap/
│   │   ├── min_heap.h
│   │   └── min_heap.c
│   ├── heapsort/
│   │   ├── heapsort.h
│   │   └── heapsort.c
│   └── main.c
│
├── CMakeLists.txt
└── README.md
```

- `src/includes/paciente.h`: Definição da estrutura `Paciente`.
- `src/max_heap/`: Implementação da Max-Heap.
- `src/min_heap/`: Implementação da Min-Heap.
- `src/heapsort/`: Implementação do algoritmo Heapsort.
- `src/main.c`: Arquivo principal com funções de teste e demonstração.
- `CMakeLists.txt`: Script de build para o CMake.

## Contexto de Aplicação: Fila de Prioridade Hospitalar 🏥

A principal aplicação demonstrada é a simulação de uma fila de atendimento em um hospital.

* **Usando Max-Heap:** Pacientes com maior prioridade (ex: 1 a 100, onde 100 é mais urgente) são atendidos primeiro.
* **Usando Min-Heap:** Para casos onde a menor prioridade representa menor tempo de espera ou chegada antecipada.
* **Usando Heapsort:** Gera relatórios ordenados por prioridade a partir de dados de pacientes.

## Análise de Complexidade (Big O) ⏱️

* Inserção em Heap: `O(log n)`
* Extração do máximo/mínimo: `O(log n)`
* Obter máximo/mínimo: `O(1)`
* Construção de Heap: `O(n)`
* Heapsort: `O(n log n)` em todos os casos

## Como Compilar e Executar ⚙️

### Usando CMake (Recomendado)

1. Crie um diretório para build (fora da pasta `src`):

   ```bash
   mkdir build
   cd build
   ```

2. Gere os arquivos de build com o CMake:

   ```bash
   cmake ..
   ```

3. Compile o projeto:

   ```bash
   cmake --build .
   ```

4. Execute o programa:

   - No Linux/macOS:
     ```bash
     ./programa_hospital
     ```
   - No Windows:
     ```cmd
     programa_hospital.exe
     ```

### Compilação Manual (Alternativa)

Se preferir compilar manualmente (sem CMake), use:

```bash
gcc src/main.c src/max_heap/max_heap.c src/min_heap/min_heap.c src/heapsort/heapsort.c -Isrc -o programa_hospital
```
