#include "./derivadas.hpp"
#include <iostream>
#include <math.h>

using namespace std;

    double DerivadaSegunda::metodoForward(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 1:
           return (f(x) - 2 * f(x +  delta) + f(x + 2 * delta))/(delta*delta);
        break;
        case 2:
            return (2 * f(x)  - 5 * f(x + delta) +
                    4 * f(x + 2 * delta) - f(x + 3 * delta))/(pow(delta, 2));
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
        }
    }
    
    double DerivadaSegunda::metodoBackward(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 1:
            return (f(x) - 2 * f(x -  delta) + f(x - 2 * delta))/(delta*delta);
        break;
        case 2:
            return (2 * f(x)  - 5 * f(x - delta) + 4 * f(x - 2 * delta) - f(x - 3 * delta))/(pow(delta, 2));
        break;
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
    }
    }
    double DerivadaSegunda::metodoCentral(double x, double delta, int ordemErro){
        switch (ordemErro){
        case 2:
            return (1/(delta * delta)) * 
                   (f(x - delta) - 2 * f(x) +  f(x + delta));
        break;
        case 4:
            return (1/(12 * delta * delta)) * 
                   (-f(x - 2 * delta) -f(x + 2 * delta) + 16 * f(x - delta) + 16 * f(x + delta) - 30 * f(x));
        default:
            cout << "Ordem de erro inválido !!" << endl;
            return 0;
        break;
        }
    }