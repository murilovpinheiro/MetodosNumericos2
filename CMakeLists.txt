cmake_minimum_required(VERSION 3.5)

project(MeuProjeto)

# Adiciona os subdiretórios
add_subdirectory(metodos/Derivadas)
add_subdirectory(metodos/Integrais)


include_directories(${CMAKE_SOURCE_DIR}/metodos/Derivadas)

include_directories(${CMAKE_SOURCE_DIR}/metodos/Integrais)
# Adiciona o executável principal
add_executable(main main.cpp)

# Vincula os subdiretórios ao executável principal
target_link_libraries(main Derivadas Integrais)
