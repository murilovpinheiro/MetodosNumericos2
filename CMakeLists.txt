cmake_minimum_required(VERSION 3.5)

project(MeuProjeto)

# Adiciona os subdiretórios
add_subdirectory(metodos/Derivadas)
add_subdirectory(metodos/Integrais)

# Adiciona o executável principal
add_executable(Main main.cpp)

# Vincula os subdiretórios ao executável principal
target_link_libraries(Main Derivadas Integrais)
