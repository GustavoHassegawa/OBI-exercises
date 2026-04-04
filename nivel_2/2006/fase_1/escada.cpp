#include <iostream>

using namespace std;

int tamanho_menor_degrau(int soma_pedras, int numero_degraus) {
    int base = soma_pedras - (numero_degraus*(numero_degraus - 1))/2; 
    
    if (base % numero_degraus != 0) {
        return -1;
    } 
    return base/numero_degraus;
}

int main(int argc, char* argv[]) {
    int i, num_degraus, soma_pedras, menor_degrau, movimentos;
    int *degraus; 

    soma_pedras = 0;
    movimentos = 0;

    cin >> num_degraus;
    degraus = new int[num_degraus];

    for (i = 0; i < num_degraus; i++) {
        cin >> degraus[i];
        soma_pedras += degraus[i];
    }

    menor_degrau = tamanho_menor_degrau(soma_pedras, num_degraus);

    if (menor_degrau == -1) {
        cout << -1 << endl;
        delete[] degraus;
        return 0;
    }

    for (int i = 0; i < num_degraus; i++) {

        if (degraus[i] < (menor_degrau + i)) {
            movimentos += (menor_degrau + i) - degraus[i];
        }
    }

    cout << movimentos << endl;

    delete[] degraus;
    return 0;
}