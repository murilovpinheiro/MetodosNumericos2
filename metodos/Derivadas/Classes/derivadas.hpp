#ifndef DERIVADAS_HPP
#define DERIVADAS_HPP
#include <functional>

class Derivada{
protected:
    std::function<double(double)> f;
public:
Derivada(std::function<double(double)> op) : f(op) {}
virtual ~Derivada() {}
virtual double metodoForward(double x, double delta, int ordemErro) = 0;
virtual double metodoBackward(double x, double delta, int ordemErro) = 0;
virtual double metodoCentral(double x, double delta, int ordemErro) = 0;
}; 

class DerivadaPrimeira: public Derivada{
protected:
        std::function<double(double)> f;
public:
DerivadaPrimeira(std::function<double(double)> op) : Derivada(op), f(op) {}
~DerivadaPrimeira() {}
double metodoForward(double x, double delta, int ordemErro) override;
double metodoBackward(double x, double delta, int ordemErro) override;
double metodoCentral(double x, double delta, int ordemErro) override;

};

class DerivadaSegunda: public Derivada{
protected:
     std::function<double(double)> f;
public:
DerivadaSegunda(std::function<double(double)> op) : Derivada(op), f(op) {}
~DerivadaSegunda() {}
double metodoForward(double x, double delta, int ordemErro) override;
double metodoBackward(double x, double delta, int ordemErro) override;
double metodoCentral(double x, double delta, int ordemErro) override;
};

class DerivadaTerceira: public Derivada{
protected:
     std::function<double(double)> f;
public:
DerivadaTerceira(std::function<double(double)> op) : Derivada(op), f(op) {}
~DerivadaTerceira(){}
double metodoForward(double x, double delta, int ordemErro) override;
double metodoBackward(double x, double delta, int ordemErro) override;
double metodoCentral(double x, double delta, int ordemErro) override;

};

#endif // DERIVADAS_HPP