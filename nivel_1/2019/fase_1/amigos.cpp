#include <iostream>
#include <vector>

using namespace std;

int main(int argv, char* argc[]) {
    int num_predios, altura_predio, maior_distancia_1 = 0, maior_distancia_2 = 0, i;
    vector<int> altura_predios;

    cin >> num_predios;

    for (i = 0; i < num_predios; i++){
        cin >> altura_predio;

        altura_predios.push_back(altura_predio);
    }

    for (i = 0; i < num_predios; i++) {
        if (maior_distancia_1 < altura_predios[i] - i)
            maior_distancia_1 = altura_predios[i] - i;
    }

    for (i = 0; i < num_predios; i++) {
        if (maior_distancia_2 < altura_predios[i] + i)
            maior_distancia_2 =  altura_predios[i] + i;
    }

    cout << maior_distancia_1 + maior_distancia_2 << endl;

    return 0;
}