#include <iostream>

using namespace std;

int** cria_matriz(int linhas, int colunas) {
    int** matriz = new int*[linhas];

    for (int i = 0; i < linhas; i++) {
        matriz[i] = new int[colunas];
    }

    return matriz;
}

void libera_matriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

int main(int argc, char* argv[]) {
    int linhas_caju, colunas_caju, 
        linhas_colheita, colunas_colheita,
        melhor_colheita, soma,  
        i, j;
    int** matriz, **soma_prefixo;

    cin >> linhas_caju >> colunas_caju >> linhas_colheita >> colunas_colheita;

    matriz = cria_matriz(linhas_caju, colunas_caju);
    soma_prefixo = cria_matriz(linhas_caju + 1, colunas_caju + 1);

    for (i = 0; i < linhas_caju; i++) {
        for(j = 0; j < colunas_caju; j++) {
            cin >> matriz[i][j];
        }
    }

    for (i = 0; i <= linhas_caju; i++) {
        for (j = 0; j <= colunas_caju; j++) {
            soma_prefixo[i][j] = 0;
        }
    }

    for (i = 1; i <= linhas_caju; i++) {
        for(j = 1; j <= colunas_caju; j++) {
            soma_prefixo[i][j] = matriz[i-1][j-1]
                           + soma_prefixo[i-1][j]
                           + soma_prefixo[i][j-1]
                           - soma_prefixo[i-1][j-1];
        }
    }

    melhor_colheita = -1;

    for (i = 1; i <= (linhas_caju - linhas_colheita + 1); i++) {
        for (j = 1; j <= (colunas_caju - colunas_colheita + 1); j++) {
            soma = soma_prefixo[i + linhas_colheita - 1][j + colunas_colheita - 1] 
                 - soma_prefixo[i - 1][j + colunas_colheita - 1]
                 - soma_prefixo[i + linhas_colheita - 1][j - 1]
                 + soma_prefixo[i - 1][j - 1];
            
            if (soma > melhor_colheita) {
                melhor_colheita = soma;
            } 
        }
    }

    cout << melhor_colheita;

    libera_matriz(matriz, linhas_caju, colunas_caju);
    libera_matriz(soma_prefixo, linhas_caju + 1, colunas_caju + 1);
    return 0;
}