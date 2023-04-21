#ifndef INTEGRAISNC_HPP
#define INTEGRAISNC_HPP
#include <functional>

class NewtonCotes{

protected:
    std::function<double(double)> f;
    double A;
    double B;

public:
NewtonCotes(std::function<double(double)> op, double Xi, double Xf) : f(op), A(Xi), B(Xf){}
virtual ~NewtonCotes() {}

virtual double Grau0(double erro_desejado) = 0;
virtual double Grau1(double erro_desejado) = 0;
virtual double Grau2(double erro_desejado) = 0;
virtual double Grau3(double erro_desejado) = 0;
virtual double Grau4(double erro_desejado) = 0;

};

class NewtonCotesAberta : public NewtonCotes{ 
    
protected:
    std::function<double(double)> f;
    double A;
    double B;

public:
NewtonCotesAberta(std::function<double(double)> op, double Xi, double Xf) : NewtonCotes(op,Xi,Xf), f(op), A(Xi), B(Xf){}
~NewtonCotesAberta() {}

double Grau0(double erro_desejado) override;
double Grau1(double erro_desejado) override;
double Grau2(double erro_desejado) override;
double Grau3(double erro_desejado) override;
double Grau4(double erro_desejado) override;
}; 

class NewtonCotesFechada : public NewtonCotes{ 
    
protected:
    std::function<double(double)> f;
    double A;
    double B;

public:
NewtonCotesFechada(std::function<double(double)> op, double Xi, double Xf) : NewtonCotes(op,Xi,Xf), f(op), A(Xi), B(Xf){}
~NewtonCotesFechada() {}

double Grau0(double erro_desejado) override;
double Grau1(double erro_desejado) override;
double Grau2(double erro_desejado) override;
double Grau3(double erro_desejado) override;
double Grau4(double erro_desejado) override;
}; 

#endif // DERIVADAS_HPP