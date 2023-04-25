#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

double alfaGrau2[2] = {-sqrt(1/3), sqrt(1/3)};
double alfaGrau3[3] = {-sqrt(3/5), 0, sqrt(3/5)};
double alfaGrau4[4] = {-0.861136, -0.339981, 0.339981, 0.861136};

double pesosGrau2[2] = {1.0, 1.0};
double pesosGrau3[3] = {0.555556, 0.888889, 0.555556};
double pesosGrau4[4] = {0.347855, 0.652145, 0.652145, 0.347855};

int itersGrau2 = 0;
int itersGrau3 = 0;
int itersGrau4 = 0;

double funcao(double x){
    return x * x * sin(x/2);
}

double alfaParaX(double alfa, double xi, double xf) {
    return 0.5*(xi+xf) - 0.5*alfa*(xf-xi);
}

double doisPontos(function<double(double)> f, double A, double B, double erro_desejado) {
    //integrar a função <function> entre A e B
    double erro_atual = 10000;
    //quantidade <N> de subproblemas
    int N = 1;
    //tamanho do subproblema
    double delta_x;
    //seção do subproblema, pedaço de delta_x
    double h;
    //resultado da integral
    double soma = 0;
    double soma_antiga = 0;

    itersGrau2 = 0;

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K; 
            double xf = A + delta_x * (K+1); 
            double somatorio = 0;
            
            //Gauss Legendre, dois pontos
            for (int i = 0; i < 2; i++) {
                somatorio += 0.5*(xf - xi)*f(alfaParaX(alfaGrau2[i], xi, xf)) * pesosGrau2[i];
            }
            soma += somatorio;
            
        }
        itersGrau2 += 1;
        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }
    return soma;
}

double tresPontos(function<double(double)> f, double A, double B, double erro_desejado) {
    //integrar a função <function> entre A e B
    double erro_atual = 10000;
    //quantidade <N> de subproblemas
    int N = 1;
    //tamanho do subproblema
    double delta_x;
    //seção do subproblema, pedaço de delta_x
    double h;
    //resultado da integral
    double soma = 0;
    double soma_antiga = 0;

    itersGrau3 = 0;

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K; 
            double xf = A + delta_x * (K+1); 
            double somatorio = 0;
            
            //Gauss Legendre, tres pontos
            for (int i = 0; i < 3; i++) {
                somatorio +=  0.5*(xf - xi)*f(alfaParaX(alfaGrau3[i], xi, xf)) * pesosGrau3[i];
            }
            soma += somatorio;
            
        }
        itersGrau3 += 1;

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }
    return soma;
}

double quatroPontos(function<double(double)> f, double A, double B, double erro_desejado) {
    //integrar a função <function> entre A e B
    double erro_atual = 10000;
    //quantidade <N> de subproblemas
    int N = 1;
    //tamanho do subproblema
    double delta_x;
    //seção do subproblema, pedaço de delta_x
    double h;
    //resultado da integral
    double soma = 0;
    double soma_antiga = 0;

    itersGrau4 = 0;

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K; 
            double xf = A + delta_x * (K+1); 
            double somatorio = 0;
            
            //Gauss Legendre, quatro pontos
            for (int i = 0; i < 4; i++) {
                somatorio +=  0.5*(xf - xi)*f(alfaParaX(alfaGrau4[i], xi, xf)) * pesosGrau4[i];
            }
            soma += somatorio;
        }
        itersGrau4 += 1;
        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }
    return soma;
}

int main(){
    auto op = [](double x){ return x * x * sin(x/2); };

    double res2 = doisPontos(op, 0, 1, 0.000001);
    double res3 = tresPontos(op, 0, 1, 0.000001);
    double res4 = quatroPontos(op, 0, 1, 0.000001);

    cout << "dois pontos " << res2 << " iteracoes: " << itersGrau2 << endl;
    cout << "tres pontos " << res3 << " iteracoes: " << itersGrau3 << endl;
    cout << "quatro pontos " << res4 << " iteracoes: " << itersGrau4 << endl;
    return 0;
}