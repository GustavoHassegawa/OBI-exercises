#include <iostream>
#define OVELHA 'k'
#define LOBO 'v'
#define CERCA '#'

using namespace std;

int linhas, colunas;
char pasto[250][250];
bool visitado[250][250];

void procura_no_pasto(int x, int y, int &ovelhas, int &lobos, bool &borda) {
    visitado[x][y] = true;

    if (pasto[x][y] == OVELHA)
        ovelhas++;
    
    if (pasto[x][y] == LOBO)
        lobos++;
    
    if (x == 0 || x == linhas-1 || y == 0 || y == colunas-1)
        borda = true;

    if (x-1 >= 0 && !visitado[x-1][y] && pasto[x-1][y] != CERCA) {
        procura_no_pasto(x-1, y, ovelhas, lobos, borda);
    }

    if (x+1 < linhas && !visitado[x+1][y] && pasto[x+1][y] != CERCA) {
        procura_no_pasto(x+1, y, ovelhas, lobos, borda);
    }

    if (y-1 >= 0 && !visitado[x][y-1] && pasto[x][y-1] != CERCA) {
        procura_no_pasto(x, y-1, ovelhas, lobos, borda);
    }

    if (y+1 < colunas && !visitado[x][y+1] && pasto[x][y+1] != CERCA) {
        procura_no_pasto(x, y+1, ovelhas, lobos, borda);
    }
}

void read_matrix(int linhas, int colunas, char matrix[250][250]) {
    for (int i = 0; i < linhas; i++) 
        for (int j = 0; j < colunas; j++) 
            cin >> matrix[i][j];
}

int main(int argc, char* argv[]) {
    cin >> linhas >> colunas;
    
    read_matrix(linhas, colunas, pasto);

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            visitado[i][j] = false;

    int total_ovelhas = 0, total_lobos = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (!visitado[i][j] && pasto[i][j] != CERCA) {
                int ovelhas = 0;
                int lobos = 0;
                bool borda = false;

                procura_no_pasto(i, j, ovelhas, lobos, borda);
                
                if (borda) {
                    total_ovelhas += ovelhas;
                    total_lobos += lobos;
                } else {
                    if (ovelhas > lobos){
                        total_ovelhas += ovelhas;
                    } else {
                        total_lobos += lobos;
                    }
                }
            }
        }
    }

    cout << total_ovelhas << " " << total_lobos;
    
    return 0;
}