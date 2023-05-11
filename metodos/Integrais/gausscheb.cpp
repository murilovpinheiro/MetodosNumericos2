#include <math.h>
#include <bits/stdc++.h>
#include "./integraisGC.hpp"

using namespace std;
// tá muito errado não tenho ctz de como funciona
double GaussCheb::alfaParaX(double alfa, double xi, double xf){
    return alfa;
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
        soma = 0;
        //trabalhar nos subproblemas
            double xi = A ; 
            double xf = B; 
            double somatorio = 0;
            
            //Gauss Legendre, dois pontos
            for (int i = 0; i < nop; i++) {
                cout << f(alfas.at(nop - 2).at(i)) << " " << pesos.at(nop-2).at(i)<<endl;
                somatorio += f(alfaParaX(alfas.at(nop - 2).at(i), xi, xf)) * pesos.at(nop - 2).at(i);
            }
            soma += somatorio;
        itersGrau2 += 1;
        //calcular o erro relativo, para sair do <while>.
        erro_atual = abs((soma - soma_antiga)/soma);
        soma_antiga = soma;
    cout << "Numero de Iterações: "<<itersGrau2 << endl;
    return soma;
}
