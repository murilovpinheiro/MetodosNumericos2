#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <functional>

using namespace std;

double derivadaPrimeira(function<double(double)> f,double x, double delta){
    return (f(x + delta) - f(x - delta))/(2 * delta);
} 

double derivadaSegunda(function<double(double)> f, double x, double delta){
    return (1/(12 * delta * delta)) * 
    (-f(x - 2 * delta) -f(x + 2 * delta) + 16 * f(x - delta) + 16 * f(x + delta) - 30 * f(x));
    //Ordem de erro 4
}

double derivadaTerceira(function<double(double)> f, double x, double delta){
    return (1/(2 * delta * delta * delta)) * 
    (-f(x - 2 * delta) + 2 * f(x - 1 * delta) - 2 * f(x + 1 * delta) + f(x + 2 * delta));
}

double derivadaQuarta(function<double(double)> f, double x, double delta){
    return (1/(pow(delta, 4))) * 
    (f(x - 2 * delta) - 4 * f(x - 1 * delta) + 6 * f(x) - 4 * f(x + 1 * delta) + f(x + 2 * delta));
}

double calculaDerivada(function<double(double)> f,
                       double erro_desejado, double x,
                       double delta, int grauDerivada){
    // Selecionando a fórmula de acordo com o grau
    function<double(function<double(double)>, double, double)> derivada;
    switch (grauDerivada) {
        case 1:
            derivada = derivadaPrimeira;
            break;
        case 2:
            derivada = derivadaSegunda;
            break;
        case 3:
            derivada = derivadaTerceira;
            break;
        case 4:
            derivada = derivadaQuarta;
            break;
        default:
        cerr << "Erro: grau de derivada inválido." << endl;
        return 0;
    }

    // Calcular a derivada com o erro desejado
    double erro = 10000000;
    double valor; double ultimo_valor = 0;
    while(erro > erro_desejado){
        valor = derivada(f, x, delta);
        erro = abs(valor - ultimo_valor)/valor;
        //cout << "| Delta: " << delta << " | Valor da Derivada: " << valor << " | Erro calculado: " << erro << endl;
        delta /= 2;
        ultimo_valor = valor;
    }
    return valor;
}

int main(){
    auto op = [](double x){return sin(pow(x, 2))+ 10 * x + 9;};
    double derivada1 = calculaDerivada(op ,0.001, 2, 0.5, 1);
    double derivada2 = calculaDerivada(op,0.001, 2, 0.5, 2);
    double derivada3 = calculaDerivada(op, 0.001, 2, 0.5, 3);
    double derivada4 = calculaDerivada(op, 0.001, 2, 0.5, 4);

    cout << derivada1 << endl;
    cout << derivada2 << endl;
    cout << derivada3 << endl;
    cout << derivada4 << endl;

    /*fplot([](double x){return limitarY((3 * x * x + 10 * x + 9), 10);}, std::array<double, 2>{-10, 10},
          "-")
        ->line_width(2);
    hold(on);
    fplot([](double x){return limitarY(calculaDerivada([](double x){return 3 * x * x + 10 * x + 9;},0.001, x, 0.5, 1),10);}, std::array<double, 2>{-10, 10},
          "-r")
        ->line_width(2);
    show();*/
    //Aparentemente tudo funcionando OK!!
    return 0;
}