#include "./derivadas.hpp"
#include <iostream>

using namespace std;

    double DerivadaPrimeira::metodoForward(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 1:
            return (f(x +  delta) - f(x))/delta;
        break;
        case 2:
            return (- 3 * f(x)  + 4 * f(x + delta) - f(x + 2 * delta))/(2 * delta);
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
        }
    }
    double DerivadaPrimeira::metodoBackward(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 1:
            return (f(x) - f(x -  delta))/delta;
        break;
        case 2:
            return (3 * f(x)  - 4 * f(x - delta) + f(x - 2 * delta))/(2 * delta);
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
    }
    double DerivadaPrimeira::metodoCentral(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 2:
            return (f(x + delta) - f(x - delta))/(2 * delta);
        break;
        case 4:

            // Depois ajeitar essa derivada primeira
            return (1/(12*delta)) * (f(x - 2*delta) - 8 * f(x - delta) + 8
                                  * f(x + delta) + -1 * f(x + 2 * delta));
            //return (1/(12 * delta)) * ( -f());
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
    }