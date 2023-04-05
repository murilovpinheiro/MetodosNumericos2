#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // Cria as filas com os valores
    queue<vector<double>> fila1, fila2;
    fila1.push({1, 2, 3.5});
    fila1.push({2, 4, 7.8});
    fila1.push({3, 6, 9.2});


    fila2.push({1, 2, 4.1});
    fila2.push({1, 3, 1});
    fila2.push({1, 66, 9.1});
    fila2.push({2, 2, 5.6});
    fila2.push({2, 3, 5.6});
    fila2.push({2, 4, 3.6});
    fila2.push({2, 5, 5});
    fila2.push({2, 6, 5.6});
    fila2.push({3, 6, 51.2});
    fila2.push({3, 9, 25.2});
    fila2.push({4, 5, 5});
    fila2.push({5, 7, 2});

    // Percorre os elementos das filas e compara as chaves
    while (!fila1.empty()) {
        vector<double> elemento1 = fila1.front();
        fila1.pop();
        int chave1 = elemento1[0];
        int chave12 = elemento1[1];
        double valor1 = elemento1[2];
        cout << "Chave - " << chave1 <<" "<< chave12 << " tem valor igual a " << valor1 << endl;

        while (!fila2.empty()) {
            vector<double> elemento2 = fila2.front();
            int chave2 = elemento2[0];
            int chave22 = elemento2[1];
            double valor2 = elemento2[2];
            if (chave1 != chave2) break;
            fila2.pop();
            cout << "                   Chave - " << chave2 <<" "<< chave22 << " tem valor igual a " << valor2 << endl;

        }
    }

    return 0;
}
