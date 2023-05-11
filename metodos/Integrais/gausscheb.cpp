#include <math.h>
#include <bits/stdc++.h>
#include "./integraisGC.hpp"

using namespace std;


double GaussCheb::alfaParaX(double alfa, double xi, double xf){
    cout << alfa<<endl;
    return  cos(((alfa - 0.5) * pi)/4);
}

double GaussCheb::resolve(double erro_desejado, int nop /*number of points*/) {
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
        int K = 0;
            double xi = A + delta_x * K; 
            double xf = B; 
            double somatorio = 0;
            
            //Tá errado não sei oq fazer
            for (int i = 0; i < nop; i++) {
                somatorio += 0.5*(xf - xi)*f(alfaParaX(alfas.at(nop - 2).at(i), xi, xf)) * pesos.at(nop - 2).at(i);
                //cout << "0.5 * (" << xf<< " - " << xi << ") * f(" <<  alfaParaX(alfas.at(nop - 2).at(i), xi, xf) << ") * " << pesos.at(nop - 2).at(i) << "\n";
            }
            soma += somatorio;
        itersGrau2 += 1;
        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    }
    cout << "Numero de Iterações: "<<itersGrau2 << endl;
    return soma;
}
