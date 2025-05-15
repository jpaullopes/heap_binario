cmake_minimum_required(VERSION 3.10)

# Nome do projeto e linguagem principal
project(HeapHospital C)

# Define o padrão da linguagem C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Adiciona o executável e lista todos os arquivos .c com seus caminhos
add_executable(programa_hospital
    src/main.c
    src/max_heap/max_heap.c
    src/min_heap/min_heap.c
    src/heapsort/heapsort.c
)

# o diretório onde este CMakeLists.txt está (a raiz do seu projeto).
target_include_directories(programa_hospital PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
