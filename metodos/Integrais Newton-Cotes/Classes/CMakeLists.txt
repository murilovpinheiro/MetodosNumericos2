# Define o nome da biblioteca que será criada
project(Integrais)
set(CLASSESNC_LIB Classes)

# Cria uma biblioteca estática com todos os arquivos .cpp no diretório atual
file(GLOB CLASSES_SRC *.cpp)
add_library(${CLASSESNC_LIB} STATIC ${CLASSES_SRC})

# Adiciona o diretório atual como um diretório de inclusão de cabeçalho
target_include_directories(${CLASSESNC_LIB} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


