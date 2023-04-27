#ifndef INTEGRAISGL_HPP
#define INTEGRAISGL_HPP
#include <vector>
#include <functional>

using namespace std;

class GaussLegendre{

protected:
    std::function<double(double)> f;
    double A;
    double B;
    vector<vector<double>> alfas = {{-sqrt(1/3), sqrt(1/3)},
                                {-sqrt(3/5), 0, sqrt(3/5)},
                                {-0.861136, -0.339981, 0.339981, 0.861136}};
    vector<vector<double>> pesos = {{1.0, 1.0},
                                {0.555556, 0.888889, 0.555556},
                                {0.347855, 0.652145, 0.652145, 0.347855}};

public:
GaussLegendre(std::function<double(double)> op, double Xi, double Xf) : f(op), A(Xi), B(Xf){}
virtual ~GaussLegendre() {}

double alfaParaX(double alfa, double xi, double xf);
double doisPontos(double erro_desejado, int nop);
double tresPontos(double erro_desejado);
double quatroPontos(double erro_desejado);

};

#endif