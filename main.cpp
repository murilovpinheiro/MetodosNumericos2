#include <iostream>
#include <functional>
#include <math.h>
#include <derivadas.hpp>
#include <integraisGL.hpp>
#include <integraisNC.hpp>

using namespace std;

int main() {
  auto f = [](double x) { return std::sin(x); };
  GaussLegendre gl(f, 2, 3);
  NewtonCotesAberta nc(f, 2, 3);
  DerivadaPrimeira dp(f);
  cout << "Teste" << endl;

  return 0;
}