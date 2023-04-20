cmake_minimum_required(VERSION 3.0)
project(Derivadas)

# Adiciona o subdiretório "classes" ao projeto
add_subdirectory(Classes)

# Adiciona o arquivo "main.cpp" ao projeto
add_executable(main mainteste.cpp)

# Linka o arquivo "main.cpp" com a biblioteca "classes"
target_link_libraries(main Classes)
