#include <iostream>
#include <functional>
#include <math.h>
#include <derivadas.hpp>
#include <integraisGL.hpp>
#include <integraisNC.hpp>

using namespace std;

void derivada(){
  double x, delta, ordemErro;
  int option = 0;
  cout << "Qual a ordem da derivada que você deseja de 1 a 4: " << endl;
  cin >> option;

  cout << "Agora digite ordenadamente o X e Delta:" << endl;
  cin >> x >> delta;
  auto f = [](double x) { return (x) * (x) * (x) + 3 * x - cos(x); };
  if (option == 1)
  {
    DerivadaPrimeira dv(f);
    double resultado = dv.metodoCentral(x, delta, 2);
    cout << "Resultado da derivada Primeira método Central erro de ordem 2: " << resultado << endl;
    resultado = dv.metodoCentral(x, delta, 4);
    cout << "Resultado da derivada Primeira método Central erro de ordem 4: " << resultado << endl;

    cout << endl;

    resultado = dv.metodoForward(x, delta, 1);
    cout << "Resultado da derivada Primeira método Forward erro de ordem 1: " << resultado << endl;
    resultado = dv.metodoForward(x, delta, 2);
    cout << "Resultado da derivada Primeira método Forward erro de ordem 2: " << resultado << endl;

    cout << endl;

    resultado = dv.metodoBackward(x, delta, 1);
    cout << "Resultado da derivada Primeira método Backward erro de ordem 1: " << resultado << endl;
    resultado = dv.metodoBackward(x, delta, 2);
    cout << "Resultado da derivada Primeira método Backward erro de ordem 2: " << resultado << endl;
  }
}

int main() {
  int option = 0;
  cout << "Prototipo do Programa de Metodos Numericos 2:\n\nAutores:\nMurilo Pinheiro\nNatan Maia" << endl << endl;
  while (option != 1 && option !=2){
    cout << "Para começar diga o que deseja fazer:\n1 - Derivada\n2 - Integral" << endl;
    cin >> option;
    switch (option)
    {
    case 1:
      cout << "Voce escolheu Derivada, agora escolha o que deseja:" << endl;
      derivada();
      break;
    case 2:
      cout << "Voce escolheu Integral, agora escolha o que deseja:" << endl;
      break;
    default:
      cout << "Valor inválido." << endl << endl;
      break;
    }
  }
  return 0;
}