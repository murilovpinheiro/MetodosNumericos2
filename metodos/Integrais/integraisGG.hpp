#ifndef INTEGRAISGG_HPP
#define INTEGRAISGG_HPP
#include <vector>
#include <functional>
#include <math.h>
#include "constante.hpp"

using namespace std;

class GaussLaguerre{

protected:
    std::function<double(double)> f;
    //double A; -> -1 sempre
    //double B; ->  1 sempre
    vector<vector<double>> alfas = {{0.585786, 3.41421},
                                {0.415775, 2.29428, 6.28995},
                                {0.322548, 1.74576, 4.53662, 9.39507}};
    vector<vector<double>> pesos = {{0.853553, 0.146447},
                                {0.711093, 0.278518, 0.0103893},
                                {0.603154, 0.357419,0.0388879, 0.000539295}};

public:
GaussLaguerre(std::function<double(double)> op) : f(op){}
virtual ~GaussLaguerre() {}

double resolve(double erro_desejado, int nop);

};

#endif