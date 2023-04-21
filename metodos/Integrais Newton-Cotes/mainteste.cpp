#include <iostream>
#include <functional>
#include <math.h>
#include <integraisNC.hpp>

using namespace std;

int main() {
    // Definir a função a ser integrada e os limites de integração
    auto f = [](double x) { return sin(x * x) + 3/2 * x + 10 * pow(x, 3); };
    double A = 0.0;
    double B = 3.14159;

    // Criar um objeto NewtonCotesAberta
    NewtonCotesAberta NC(f, A, B);
    NewtonCotesFechada NCF(f, A, B);

    // Calcular a integral numérica usando diferentes graus de fórmulas de Newton-Cotes abertas
    double resultado0 = NC.Grau0(0.0001);
    double resultado1 = NC.Grau1(0.0001);
    double resultado2 = NC.Grau2(0.0001);
    double resultado3 = NC.Grau3(0.0001);
    double resultado4 = NC.Grau4(0.0001);

    // Imprimir os resultados
    cout << "Integral numérica usando a fórmula de Newton-Cotes aberta de grau 0: " << resultado0 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes aberta de grau 1: " << resultado1 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes aberta de grau 2: " << resultado2 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes aberta de grau 3: " << resultado3 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes aberta de grau 4: " << resultado4 << endl;

    resultado0 = NCF.Grau0(0.0001);
    resultado1 = NCF.Grau1(0.0001);
    resultado2 = NCF.Grau2(0.0001);
    resultado3 = NCF.Grau3(0.0001);
    resultado4 = NCF.Grau4(0.0001);

    // Imprimir os resultados
    cout << "Integral numérica usando a fórmula de Newton-Cotes fechada de grau 0: " << resultado0 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes fechada de grau 1: " << resultado1 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes fechada de grau 2: " << resultado2 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes fechada de grau 3: " << resultado3 << endl;
    cout << "Integral numérica usando a fórmula de Newton-Cotes fechada de grau 4: " << resultado4 << endl;
    return 0;
}
