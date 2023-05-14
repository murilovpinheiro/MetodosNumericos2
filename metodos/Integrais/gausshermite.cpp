#include <math.h>
#include <bits/stdc++.h>
#include "./integraisGH.hpp"

using namespace std;

double GaussHerm::resolve(double erro_desejado, int nop /*number of points*/) {
    double soma = 0;

    for (int i = 0; i < nop; i++) {
        soma += f(alfas.at(nop - 2).at(i)) * pesos.at(nop - 2).at(i);
        cout << f(alfas.at(nop - 2).at(i))  << " " << pesos.at(nop - 2).at(i) << endl;
    }
    return soma;
}
