#include <math.h>
#include <bits/stdc++.h>
#include "./integraisGL.hpp"

using namespace std;


double GaussLegendre::alfaParaX(double alfa, double xi, double xf){
    return 0.5 * (xi+xf) - 0.5 * alfa * (xf-xi);
}

double GaussLegendre::doisPontos(double erro_desejado, int nop /*number of points*/) {
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

    int itersGrau2 = 0;

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
            for (int i = 0; i < nop; i++) {
                somatorio += 0.5*(xf - xi)*f(alfaParaX(alfas.at(nop - 2).at(i), xi, xf)) * pesos.at(nop - 2).at(i);
            }
            soma += somatorio;
            
        }
        itersGrau2 += 1;
        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }
    cout << "Numero de Iterações: "<<itersGrau2 << endl;
    return soma;
}