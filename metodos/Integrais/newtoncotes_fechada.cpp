#include <math.h>
#include <bits/stdc++.h>
#include "./integraisNC.hpp"

using namespace std;

double NewtonCotesFechada::Grau0(double erro_desejado) {
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
            double xi = A + delta_x * K; //x0

            //Newton-Cotes, Abordagem Fechada, Grau 0, função constante
            double area = f(xi) * delta_x;
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}

//fechada 1 utilizando a filosofia central
double NewtonCotesFechada::Grau1(double erro_desejado) {
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
            double xi = A + delta_x * K; //x0
            //x1, x2, x3
            double xf = A + delta_x * (K+1); //x1

            //Newton-Cotes, Abordagem Fechada, Grau 1
            //Fórmula do Trapézio
            double area = (delta_x/2) * (f(xi) + f(xf));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}



//fechada 2 utilizando a filosofia central
double NewtonCotesFechada::Grau2(double erro_desejado) {
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
            double xi = A + delta_x * K; //x0
            double h = delta_x / 2;

            double x0 = xi;
            double x1 = xi + h;
            double x2 = xi + 2*h;

            //Newton-Cotes, Abordagem Fechada, Grau 2
            //Fórmula 1/3 de Simpson
            double area = (h/3) * (f(x0) + 4*f(x1) + f(x2));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}


//fechada 3 utilizando a filosofia central
double NewtonCotesFechada::Grau3(double erro_desejado) {
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
            double xi = A + delta_x * K; //x0
            double h = delta_x / 3;

            double x0 = xi;
            double x1 = xi + h;
            double x2 = xi + 2*h;
            double x3 = xi + 3*h;

            //Newton-Cotes, Abordagem Fechada, Grau 3
            //Fórmula 3/8 de Simpson
            double area = (3*h/8) * (f(x0) + 3*f(x1) + 3*f(x2) + f(x3));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}


//fechada 4 utilizando a filosofia central
double NewtonCotesFechada::Grau4(double erro_desejado) {
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
            double xi = A + delta_x * K; //x0
            double h = delta_x / 4;

            double x0 = xi;
            double x1 = xi + h;
            double x2 = xi + 2*h;
            double x3 = xi + 3*h;
            double x4 = xi + 4*h;

            //Newton-Cotes, Abordagem Fechada, Grau 4
            //Sem nome
            double area = (2*h/45) * (7*f(x0) + 32*f(x1) + 12*f(x2) + 32*f(x3) + 7*f(x4));
            soma += area;
        }

        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }

    return soma;
}