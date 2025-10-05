// Faça um programa com uma matriz 5x5 de inteiros
// positivos ou negativos (aleatórios e de sua escolha) e encontre e
// exiba o maior elemento desta matriz.
#include <stdio.h>

void exibirMatriz(int matriz[5][5]){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%3d ", matriz[i][j]); 
        }
        printf("\n");
    }
}

int main(){
    int matriz[5][5] = {
        {1, 3, 5, 7, 9,},
        {100, -5, -8, -1, -2},
        {24, 67, 78, 22, 1},
        {-54, -65, -11, 9, -8},
        {8, 7, 6, 5, 4},
    };

    int maior = matriz[0][0];
    for(int i = 0; i < 5; i++){
        for(int j =0; j < 5; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }
    exibirMatriz(matriz);
    printf("\nMaior elemento da matriz: %d", maior);

    return 0;
}