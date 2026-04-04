#include <stdio.h>
#define N_RODADAS 3 

using namespace std;

int main(int argc, char* argv[]) {
    int forca_carta[14], jogadas_adalberto[3], jogadas_bernadete[3]; 
    int i, numero_partidas, partida, rodada, adalberto, bernadete, pontos_rodada_adalberto, pontos_rodada_bernadete, carta_adalberto, carta_bernadete;

    adalberto = 0;
    bernadete = 0;

    forca_carta[0] = 0;
    forca_carta[1] = 8;
    forca_carta[2] = 9;
    forca_carta[3] = 10;
    forca_carta[4] = 1;
    forca_carta[5] = 2;
    forca_carta[6] = 3;
    forca_carta[7] = 4;
    forca_carta[8] = 0;
    forca_carta[9] = 0;
    forca_carta[10] = 0;
    forca_carta[11] = 6;
    forca_carta[12] = 5;
    forca_carta[13] = 7;

    scanf("%d", &numero_partidas);

    for (partida = 0; partida < numero_partidas; partida++) {
        scanf("%d %d %d %d %d %d",
              &jogadas_adalberto[0],
              &jogadas_adalberto[1],
              &jogadas_adalberto[2],
              &jogadas_bernadete[0], 
              &jogadas_bernadete[1],
              &jogadas_bernadete[2]);

        pontos_rodada_adalberto = 0;
        pontos_rodada_bernadete = 0;

        for(rodada = 0; rodada < N_RODADAS; rodada++) {
            carta_adalberto = jogadas_adalberto[rodada];
            carta_bernadete = jogadas_bernadete[rodada];

            if (forca_carta[carta_adalberto] >= forca_carta[carta_bernadete]) 
                pontos_rodada_adalberto++;
            else
                pontos_rodada_bernadete++; 

            if (pontos_rodada_adalberto >= 2 || pontos_rodada_bernadete >= 2)
                break;  
        }

        if (pontos_rodada_adalberto > pontos_rodada_bernadete) 
            adalberto++;
        else
            bernadete++;

    }

    printf("%d %d\n", adalberto, bernadete);

    return 0;
}