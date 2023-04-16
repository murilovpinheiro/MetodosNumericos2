#include <iostream>
#include <math.h>

using namespace std;

double funcao(double x){
    return x * x + 3 * x;
}

int main(){
    double Aold = 0; double A = 0;
    double erro_desejado = 0.0001;
    double erro = 1;
    int N = 1;
    double delta_x;

    double a = 0; double b = 2;
    char teste;
    double X_K;

    while (erro > erro_desejado){
        cout << "ERRO: "<< erro << " > " << erro_desejado << endl;
        N = N * 2;
        cout << N << " numero de divisões" << endl;
        delta_x = (b - a)/N;
        cout << "tamanho do intervalo: " << delta_x << endl;
        A = 0;
        for (int K = 0; K < N; K++){
            // a + delta_x/2 é porque usamos o ponto central do intervalo;
            X_K = (a + delta_x/2) + (delta_x) * K;
            A = A + funcao(X_K) * delta_x;
        }
        cout << endl;
        erro = abs((A - Aold)/A);
        Aold = A;
    }
    cout << erro << " < " << erro_desejado << endl;
    cout << A << endl;
    return 0;
}