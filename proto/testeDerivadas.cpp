#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <functional>


// Esse aqui é um código de teste, que utilizei primeiro para desenvolver e testar as derivadas
// Mais a frente vou utilizar as derivadas de forma mais complexa
using namespace std;

double derivadaPrimeira(function<double(double)> f,double x, double delta, int ordemErro){
    switch (ordemErro){
        case 2:
            return (f(x + delta) - f(x - delta))/(2 * delta);
        break;
        case 4:

            // Depois ajeitar essa derivada primeira
            return (1/(12*delta)) * (f(x - 2*delta) - 8 * f(x - delta) + 8 * f(x + delta) + -1 * f(x + 2 * delta));
            //return (1/(12 * delta)) * ( -f());
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
} 

double derivadaSegunda(function<double(double)> f, double x, double delta, int ordemErro){
    switch (ordemErro){
        case 2:
            return (1/(delta * delta)) * 
                   (f(x - delta) - 2 * f(x) +  f(x + delta));
        break;
        case 4:
            return (1/(12 * delta * delta)) * 
                   (-f(x - 2 * delta) -f(x + 2 * delta) + 16 * f(x - delta) + 16 * f(x + delta) - 30 * f(x));
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
}

double derivadaTerceira(function<double(double)> f, double x, double delta, int ordemErro){
switch (ordemErro){
        case 1:
            return (-1 * f(x) + 3 * f(x + delta) - 3 * f(x + 2 * delta) + f(x + 3 * delta))/(pow(delta, 3));
        break;
        case 2:
            return (-5 * f(x)  + 18 * f(x + delta)
                    -24 * f(x + 2 * delta) + 14 * f(x + 3 * delta) - 3 * f(x + 4 * delta))/(2 * pow(delta, 3));
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
}
    
}

double derivadaQuarta(function<double(double)> f, double x, double delta, int ordemErro){
    return (1/(pow(delta, 4))) * 
    (f(x - 2 * delta) - 4 * f(x - 1 * delta) + 6 * f(x) - 4 * f(x + 1 * delta) + f(x + 2 * delta));
}

double calculaDerivada(function<double(double)> f,
                       double erro_desejado, double x,
                       double delta, int grauDerivada, int ordemErro){
    // Selecionando a fórmula de acordo com o grau
    function<double(function<double(double)>, double, double, int)> derivada;
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
        cout << erro << " " << erro_desejado<< endl;
        valor = derivada(f, x, delta, ordemErro);
        cout << "valor: " << valor << "  " << ultimo_valor << endl;

        erro = abs((valor - ultimo_valor)/valor);
        //cout << "| Delta: " << delta << " | Valor da Derivada: " << valor << " | Erro calculado: " << erro << endl;
        delta /= 2;
        ultimo_valor = valor;
    }
    return valor;
}

int main(){
    auto op = [](double x){return x*x*x;};
    // sin(x²) + 10x + 9
    /*double derivada1 = calculaDerivada(op ,0.001, 2, 0.5, 1, 4);
    double derivada2 = calculaDerivada(op,0.001, 2, 0.5, 2, 4);
    */
    double derivada3 = calculaDerivada(op, 0.1, 2, 0.5, 3, 1);
    //double derivada4 = calculaDerivada(op, 0.001, 2, 0.5, 4, 2);

    /*cout << derivada1 << endl;
    cout << derivada2 << endl;*/
    cout << derivada3 << endl;
    //cout << derivada4 << endl;
    //Aparentemente tudo funcionando OK!!
    return 0;
}