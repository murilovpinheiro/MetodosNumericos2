#ifndef INTEGRAISGB_HPP
#define INTEGRAISGB_HPP
#include <vector>
#include <functional>
#include <math.h>

const double pi = 3.14159265358979323846;

using namespace std;

class GaussCheb{

protected:
    std::function<double(double)> f;
    double A;
    double B;
    vector<vector<double>> alfas = {{-1/sqrt(2), 1/sqrt(2)},
                                {-sqrt(3)/2, 0 , sqrt(3)/2},
                                {-sqrt(2 + sqrt(2))/2,-sqrt(2 - sqrt(2))/2, sqrt(2 - sqrt(2))/2, sqrt(2 + sqrt(2))/2}};
    vector<vector<double>> pesos = {{pi/2, pi/2},
                                {pi/3, pi/3, pi/3},
                                {pi/4, pi/4,pi/4, pi/4}};

public:
GaussCheb(std::function<double(double)> op, double Xi, double Xf) : f(op), A(Xi), B(Xf){}
virtual ~GaussCheb() {}

double alfaParaX(double alfa, double xi, double xf);
double resolve(double erro_desejado, int nop);

};

#endif