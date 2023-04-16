#include <iostream>
#include <math.h>

// Tenho planos para no futuro modificar esses códigos de Integração e Derivação e Transformar numa Grande
// Junção desses métodos.

using namespace std;

double funcao(double x){
    return x * x + 3 * x; // Exemplo de função simples que utilizei:
                          // X² + 3X, pensando em no futuro talvez fazer um parser simples de func. matemáticas
}

double func_teste(double x){
    return x * x * sin(x/2);
}

int main(){
    double integralOld = 0; double integral = 0;
    //double erro_desejado = 0.00001;
    double erro_desejado = 0.01;
    double erro = 1;
    int N = 1;
    double intervalSize;

    //double xI = -18; double xF = 190;
    double xI = 0; double xF = 4;
    double a; double b;
    int contador = 0;

    while (erro > erro_desejado){
        contador++;
        //cout << "ERRO: "<< erro << " > " << erro_desejado << endl;
        N = N * 2;
        //cout << N << " numero de divisões" << endl;
        intervalSize = (xF - xI)/N;
        //cout << "tamanho do intervalo: " << intervalSize << endl;
        integral = 0;
        double delta_x;
        for (int K = 0; K < N; K++){
            a = (xI) + (intervalSize) * K; // encontrando o primeiro ponto do intervalo
            b = (xI) + (intervalSize) * (K + 1);// calculando o valor de b (ultimo ponto do intervalo)            
            delta_x = (b - a)/4;
            integral = integral + (b - a)/90 * (7 * funcao(a) + 32 * funcao(a + delta_x) +
                        12 * funcao(a + 2 * delta_x) + 32 * funcao(a + 3 * delta_x) + 7 * funcao(b));
            cout << "Numero do intervalo: " << K << endl;
            cout << "       inicio do intervalo: " << a << "\n       final do intervalo: " << b << endl;
            cout << "       deltaX: " << delta_x<< endl;
        }
        cout << endl << endl<< endl;
        erro = abs((integral - integralOld)/integral);
        integralOld = integral;
    }
    cout << erro << " < " << erro_desejado << " numero de iterações: " << contador << endl;
    cout << "resultado: " << integral << endl;
    return 0; // Aparentemente funcionando direitinho
}