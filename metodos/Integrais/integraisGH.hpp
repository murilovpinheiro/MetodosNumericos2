#ifndef INTEGRAISGH_HPP
#define INTEGRAISGH_HPP
#include <vector>
#include <functional>
#include <math.h>
#include "constante.hpp"

using namespace std;

class GaussHerm{

protected:
    std::function<double(double)> f;
    //double A; -> -infinite 
    //double B; ->  infinite
    vector<vector<double>> alfas = {{-1/sqrt(2), 1/sqrt(2)},
                                {-sqrt(6)/2, 0 , sqrt(6)/2},
                                {-1.65068, -0.524648, 0.524648,1.65068 }};
    vector<vector<double>> pesos = {{sqrt(pi)/2, sqrt(pi)/2},
                                {sqrt(pi)/6, 2* sqrt(pi) /3, sqrt(pi)/6},
                                {0.0813128, 0.804914, 0.804914, 0.0813128}};

public:
GaussHerm(std::function<double(double)> op) : f(op) {}
virtual ~GaussHerm() {}

double resolve(double erro_desejado, int nop);

};

#endif