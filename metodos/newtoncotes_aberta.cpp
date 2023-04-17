#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

//TODO: implementar aberta de grau 4


double funcao(double x){
    return x * x * sin(x/2);
}

//aberta 1 utilizando a filosofia central
double aberta1(function<double(double)> f, double A, double B, double erro_desejado) {
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

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K;
            double h = delta_x / 3;
            
            double x0 = xi + h;
            double x1 = xi + h + h;

            //Newton-Cotes, Abordagem Aberta, Grau 1
            //Fórmula do Trapézio Aberta
            double area = (3*h/2) * (f(x0) + f(x1));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}


//aberta 2 utilizando a filosofia central
double aberta2(function<double(double)> f, double A, double B, double erro_desejado) {
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

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K;
            double h = delta_x / 4;
            
            double x0 = xi + h;
            double x1 = xi + h + h;
            double x2 = xi + h + 2*h;

            //Newton-Cotes, Abordagem Aberta, Grau 2
            //Regra de Milne
            double area = (4*h/3) * (2*f(x0) -f(x1) + 2*f(x2));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}



//aberta 3 utilizando a filosofia central
double aberta3(function<double(double)> f, double A, double B, double erro_desejado) {
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

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K;
            double h = delta_x / 5;
            
            double x0 = xi + h;
            double x1 = xi + h + h;
            double x2 = xi + h + 2*h;
            double x3 = xi + h + 3*h;

            //Newton-Cotes, Abordagem Aberta, Grau 2
            //Sem Nome
            double area = (5*h/24) * (11*f(x0) + f(x1) + f(x2) + 11*f(x3));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}   




//aberta 3 utilizando a filosofia central
double aberta4(function<double(double)> f, double A, double B, double erro_desejado) {
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

    while(erro_atual > erro_desejado) {
        N = N*2; //refinar as subdivisões
        delta_x = (B - A) / N;
        soma = 0;

        //trabalhar nos subproblemas
        for (int K = 0; K < N; K++){
            double xi = A + delta_x * K;
            double h = delta_x / 6;
            
            double x0 = xi + h;
            double x1 = xi + h + h;
            double x2 = xi + h + 2*h;
            double x3 = xi + h + 3*h;
            double x4 = xi + h + 4*h;

            //Newton-Cotes, Abordagem Aberta, Grau 2
            //Sem Nome
            double area = (3*h/10) * (11*f(x0) -14*f(x1) +26*f(x2) -14*f(x3) +11*f(x4));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}   