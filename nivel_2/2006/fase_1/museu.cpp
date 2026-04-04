#include <iostream>
#include <vector>
#include <queue>

#define INFINITO 1000000000

using namespace std;

struct Corredor {
    int destino;
    int tempo_corredor;
};

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num_salas, num_corredores;
    cin >> num_salas >> num_corredores;

    vector<int> tempo_sala(num_salas);
    vector<vector<Corredor>> grafo(num_salas);

    for (int i = 0; i < num_salas; i++) 
        cin >> tempo_sala[i];
    
    for (int i = 0; i < num_corredores; i++) {
        int saida, destino, tempo_deslocamento;
        cin >> saida >> destino >> tempo_deslocamento;

        saida--;
        destino--;

        grafo[saida].push_back({destino, tempo_deslocamento + tempo_sala[destino]});
    }

    int tempo_visita = INFINITO;

    vector<vector<int>> dist(num_salas, vector<int>(num_salas, INFINITO));

    for (int i = 0; i < num_salas; i++) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> fila;

        dist[i][i] = 0;
        fila.push({0, i});

        while (!fila.empty()) {
            int tempo_acumulado = fila.top().first;
            int sala_atual = fila.top().second;
            fila.pop();

            if (tempo_acumulado > dist[i][sala_atual]) continue;

            for (int j = 0; j < grafo[sala_atual].size(); j++) {
                int destino = grafo[sala_atual][j].destino;
                int tempo_corredor = grafo[sala_atual][j].tempo_corredor;

                if (dist[i][destino] > tempo_acumulado + tempo_corredor) {
                    dist[i][destino] = tempo_acumulado + tempo_corredor;
                    fila.push({dist[i][destino], destino});
                }
            }
        }
    }

    for (int i = 0; i < num_salas; i++) {
        for (int j = 0; j < num_salas; j++) {
            if (i != j && dist[i][j] < INFINITO && dist[j][i] < INFINITO) {
                tempo_visita = min(tempo_visita, dist[i][j] + dist[j][i]);
            }
        }
    }

    cout << tempo_visita << endl;

    return 0;
}