# Define o nome do subdiretório
set(SUBDIR_NAME Integrais)

# Adiciona todos os arquivos .cpp na pasta
file(GLOB ${SUBDIR_NAME}_SOURCES "*.cpp")

# Adiciona a biblioteca estática com os arquivos .cpp encontrados
add_library(${SUBDIR_NAME} STATIC ${${SUBDIR_NAME}_SOURCES})