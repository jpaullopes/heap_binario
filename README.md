# 🏥 Projeto de Implementação de Heap: Fila de Prioridade Hospitalar 🏥

## Descrição 📝

Este projeto consiste na implementação das estruturas de dados Max-Heap e Min-Heap em linguagem C. O objetivo é demonstrar o funcionamento e as aplicações de heaps, utilizando como contexto principal a gestão de uma fila de prioridade de pacientes em um ambiente hospitalar. A Max-Heap é utilizada para gerenciar pacientes onde a maior prioridade numérica indica maior urgência, enquanto a Min-Heap pode ser adaptada para cenários onde a menor prioridade numérica é processada primeiro (ex: menor tempo de espera, ordem de chegada com prioridade mínima).

## Estrutura de Dados: Heap Binária 🌳

Uma **Heap Binária** é uma estrutura de dados baseada em árvore binária completa que satisfaz a propriedade da heap:
*   **Max-Heap:** O valor de cada nó pai é maior ou igual aos valores de seus filhos. O maior elemento está sempre na raiz.
*   **Min-Heap:** O valor de cada nó pai é menor ou igual aos valores de seus filhos. O menor elemento está sempre na raiz.

Nesta implementação, a heap é representada utilizando um array para maior eficiência de acesso e manipulação dos elementos, seguindo a abordagem padrão.

## Funcionalidades Implementadas ✅

O projeto inclui módulos separados para Max-Heap e Min-Heap, cada um com as seguintes funcionalidades:

### Paciente 👨‍⚕️
Uma estrutura `Paciente` é definida para armazenar os dados relevantes:

*   `id`: Identificador único do paciente.
*   `prioridade`: Valor numérico que define a urgência ou ordem de atendimento.

```c
typedef struct {
    int id;
    int prioridade;
} Paciente;
```

### Max-Heap (max\_heap.h, max\_heap.c) ⬆️

Ideal para cenários onde o maior valor de prioridade deve ser atendido primeiro.

*   `criarMaxHeap(capacidade)`: Aloca e inicializa uma nova Max-Heap.
*   `inserirPacienteMax(heap, paciente)`: Insere um novo paciente na heap, mantendo a propriedade de Max-Heap.
*   `extrairMaxPacienteHeap(heap)`: Remove e retorna o paciente com a maior prioridade.
*   `maxHeapVazia(heap)`: Verifica se a heap está vazia.
*   `liberarMaxHeap(heap)`: Libera toda a memória alocada para a heap.

### Min-Heap (min\_heap.h, min\_heap.c) ⬇️

Ideal para cenários onde o menor valor de prioridade deve ser atendido primeiro.

*   `criarMinHeap(capacidade)`: Aloca e inicializa uma nova Min-Heap.
*   `inserirPacienteMin(heap, paciente)`: Insere um novo paciente na heap, mantendo a propriedade de Min-Heap.
*   `extrairMinPacienteHeap(heap)`: Remove e retorna o paciente com a menor prioridade.
*   `minHeapVazia(heap)`: Verifica se a heap está vazia.
*   `liberarMinHeap(heap)`: Libera toda a memória alocada para a heap.

### Estrutura dos Arquivos 🗂️

O projeto está organizado nos seguintes arquivos:

*   `max_heap.h`: Arquivo de cabeçalho para a implementação da Max-Heap. Contém as definições das estruturas e os protótipos das funções.
*   `max_heap.c`: Arquivo de código fonte com a implementação das funções da Max-Heap.
*   `min_heap.h`: Arquivo de cabeçalho para a implementação da Min-Heap.
*   `min_heap.c`: Arquivo de código fonte com a implementação das funções da Min-Heap.
*   `main.c` (Exemplo de uso): Um arquivo principal (não fornecido aqui, a ser criado pelo usuário) para demonstrar o uso das heaps no contexto da fila de hospital.

## Contexto de Aplicação: Fila de Prioridade Hospitalar 🏥

A principal aplicação demonstrada é a simulação de uma fila de atendimento em um hospital.

*   **Usando Max-Heap:** Pacientes são inseridos com um nível de prioridade (ex: 1 a 10, onde 10 é mais urgente). A Max-Heap garante que o paciente com a maior prioridade seja sempre o próximo a ser chamado para atendimento.
*   **Usando Min-Heap:** Poderia ser usado para um sistema onde a menor prioridade significa, por exemplo, "chegou mais cedo" em um grupo de pacientes com a mesma urgência médica, ou para gerenciar recursos com base no menor custo/tempo.

## Análise de Complexidade (Big O) ⏱️

A eficiência das operações da Heap Binária (tanto Max quanto Min) é uma de suas principais vantagens:

*   **Inserção** (`inserirPacienteMax`, `inserirPacienteMin`): O(log n)

    O novo elemento é adicionado ao final do array (folha mais à direita) e, no pior caso, "sobe" até a raiz através da operação `heapifyUp`. A altura de uma heap binária completa com n elementos é O(log n).
*   **Extração do Máximo/Mínimo** (`extrairMaxPacienteHeap`, `extrairMinPacienteHeap`): O(log n)

    O elemento da raiz é removido. O último elemento da heap é movido para a raiz e, no pior caso, "desce" até uma posição de folha através da operação `heapifyDown`. Novamente, o número de operações é limitado pela altura da árvore.
*   **Obter Máximo/Mínimo** (sem extrair): O(1)

    O elemento de maior (Max-Heap) ou menor (Min-Heap) prioridade está sempre na raiz, permitindo acesso em tempo constante.
*   **Criação da Heap** (a partir de um array desordenado - não implementado diretamente como uma função única aqui, mas pode ser feito em O(n)):

    Embora inserir n elementos um a um resulte em O(n log n), existe um algoritmo (como o de Floyd, que aplica `heapifyDown` da metade dos elementos para baixo até a raiz) que constrói uma heap em tempo linear O(n).

## Como Compilar e Executar ⚙️

Para compilar o projeto, você precisará de um compilador C (como o GCC). Crie um arquivo `main.c` que inclua `max_heap.h` e/ou `min_heap.h` e utilize as funções implementadas.

Exemplo de compilação (com GCC):

Se você tiver um `main.c` que usa a Max-Heap:

```bash
gcc main.c max_heap.c -o programa_hospital_max
./programa_hospital_max
```

Se você tiver um `main.c` que usa a Min-Heap:

```bash
gcc main.c min_heap.c -o programa_hospital_min
./programa_hospital_min
```

Se o `main.c` utilizar ambas:

```bash
gcc main.c max_heap.c min_heap.c -o programa_hospital_completo
./programa_hospital_completo
```

## Possíveis Melhorias e Próximos Passos 🚀

*   **Redimensionamento Dinâmico:** Implementar a capacidade da heap de crescer dinamicamente caso o número de elementos exceda a capacidade inicial (usando `realloc`).
*   **Função construirHeap (Build Heap):** Adicionar uma função que receba um array de pacientes desordenado e o transforme em uma heap eficiente (em tempo O(n)).
*   **Interface de Usuário Mais Robusta:** Desenvolver um `main.c` com um menu interativo para simular a chegada de pacientes, visualização da fila e atendimento.
*   **Critérios de Prioridade Múltiplos:** Expandir a `struct Paciente` e a lógica de prioridade para considerar múltiplos fatores (ex: idade, condição crônica, tempo de espera) na definição da prioridade final.
*   **Testes Unitários:** Criar um conjunto de testes para garantir a corretude de todas as funções da heap.
*   **Documentação Doxygen:** Gerar documentação HTML a partir dos comentários do código usando Doxygen.

## Autor 👨‍💻

João Paulo

(Este projeto foi desenvolvido como parte dos estudos em Estruturas de Dados.)