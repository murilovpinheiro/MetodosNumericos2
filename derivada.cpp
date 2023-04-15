#include <iostream>
#include <math.h>

using namespace std;

double funcao(double x){
    return sqrt(exp(3 * x) + 4 * pow(x, 2));
}

double derivada(double x, double delta){
    double mult = 1/(12 * delta * delta);
    double f = -funcao(x - 2 * delta) + 16 * funcao(x - delta) - 30 * funcao(x) + 16 * funcao(x + delta) -funcao(x + 2 * delta);
    return mult * f;
}

double error(double delta){
    return (abs((derivada(2, delta) - derivada(2, 2 * delta))/derivada(2, delta)));
}

int main(){
    double delta = 0.5;
    double erro = 1;
    double valor;
    while(erro > 0.00001){
        valor = derivada(2, delta);
        erro = error(delta);
        cout << "| Delta: " << delta << " | Valor da Derivada: " << valor << " | Erro calculado: " << erro << endl;
        delta = delta/2;
    }
    return 0;
}