#include <iostream>
#include <cmath>
#include <functional>
#include <derivadas.hpp>

int main() {
  // Define a função que será derivada
  auto f = [](double x) { return std::sin(x); };

  // Cria um objeto da classe DerivadaPrimeira
  DerivadaPrimeira dp(f);
  DerivadaSegunda ds(f);
  DerivadaTerceira dt(f);

  // Calcula a derivada de pi/2 usando o método central com delta = 0.1 e ordem de erro 2
  double x = M_PI / 2.0;
  double delta = 0.1;
  int ordemErro = 2;
  double dfdx = dp.metodoCentral(x, delta, ordemErro);
  double dfds = ds.metodoCentral(x, delta, ordemErro);
  double dfdt = dt.metodoCentral(x, delta, ordemErro);

  // Imprime o resultado
  std::cout << "f'(pi/2) = " << dfdx << std::endl;
  std::cout << "f'(pi/2) = " << dfds << std::endl;
  std::cout << "f'(pi/2) = " << dfdt << std::endl;

  return 0;
}