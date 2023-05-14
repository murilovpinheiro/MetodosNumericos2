#ifndef INTEGRAISGC_HPP
#define INTEGRAISGC_HPP
#include <vector>
#include <functional>
#include <math.h>
#include "constante.hpp"

using namespace std;

class GaussCheb{

protected:
    std::function<double(double)> f;
    //double A; -> -1 sempre
    //double B; ->  1 sempre
    vector<vector<double>> alfas = {{-1/sqrt(2), 1/sqrt(2)},
                                {-sqrt(3)/2, 0 , sqrt(3)/2},
                                {-sqrt(2 + sqrt(2))/2,-sqrt(2 - sqrt(2))/2, sqrt(2 - sqrt(2))/2, sqrt(2 + sqrt(2))/2}};
    vector<vector<double>> pesos = {{pi/2, pi/2},
                                {pi/3, pi/3, pi/3},
                                {pi/4, pi/4,pi/4, pi/4}};

public:
GaussCheb(std::function<double(double)> op) : f(op){}
virtual ~GaussCheb() {}

double resolve(double erro_desejado, int nop);

};

#endif