#include <math.h>
#include <bits/stdc++.h>
#include "./integraisGC.hpp"

using namespace std;

double GaussCheb::resolve(double erro_desejado, int nop /*number of points*/) {
    double soma = 0;

    for (int i = 0; i < nop; i++) {
        soma += f(alfas.at(nop - 2).at(i)) * pesos.at(nop - 2).at(i);
        cout << f(alfas.at(nop - 2).at(i))  << " " << pesos.at(nop - 2).at(i) << endl;
    }
    // CHEBYSHEV WORKING !!!!
    return soma;
}
