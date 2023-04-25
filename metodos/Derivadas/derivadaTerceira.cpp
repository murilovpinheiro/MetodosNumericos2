#include "./derivadas.hpp"
#include <iostream>
#include <math.h>

using namespace std;

    double DerivadaTerceira::metodoForward(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 1:
            return (-1 * f(x) + 3 * f(x + delta) - 3 * f(x + 2 * delta) + f(x + 3 * delta))/(pow(delta, 3));
        break;
        case 2:
            return (-5 * f(x)  + 18 * f(x + delta)
                    -24 * f(x + 2 * delta) + 14 * f(x + 3 * delta) - 3 * f(x + 4 * delta))/(2 * pow(delta, 3));
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
        }
    }
    
    double DerivadaTerceira::metodoBackward(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 1:
            return (f(x) - 3 * f(x - 1 * delta) + 3 * f(x - 2 * delta) - 1 * f(x -3 * delta))/(pow(delta, 3));
        break;
        case 2:
            return ((5) * f(x)  - 18 * f(x - delta) +
                    24 * f(x - 2 * delta) - 14 * f(x - 3 * delta) + (3) * f(x - 4 * delta))/(2 * pow(delta, 3));
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
    }
    double DerivadaTerceira::metodoCentral(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 2:
            return (1/(2 * delta * delta * delta)) * 
                   (-f(x - 2 * delta) + 2 * f(x - 1 * delta) - 2 * f(x + 1 * delta) + f(x + 2 * delta));
        break;
        case 4:
            return (f(x - 3 * delta) - f(x + 3 * delta)
                 -8*f(x - 2 * delta) +8*f(x + 2 * delta)
                +13*f(x - 1 * delta) - 13*f(x + 1 * delta))/(8 * pow(delta, 3));
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
    }