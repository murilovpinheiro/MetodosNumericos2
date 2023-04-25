#include <iostream>
#include <functional>
#include <math.h>
#include <integraisGL.hpp>

using namespace std;

int main() {
    // Definir a função a ser integrada e os limites de integração
    auto f = [](double x) {return x * x * sin(x/2); };
    double A = 0.0;
    double B = 3.14159;

    // Criar um objeto NewtonCotesAberta
    GaussLegendre gl(f, 0, 1);
    double resultado0 = gl.doisPontos(0.000001, 2);
    
    // Calcular a integral numérica usando diferentes graus de fórmulas de Newton-Cotes abertas
    //Aparenemtente ok
    // Imprimir os resultados
    cout << "Integral numérica usando a fórmula de Newton-Cotes aberta de grau 0: " << resultado0 << endl;
}
