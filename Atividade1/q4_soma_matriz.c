// FAça um programa com uma matriz com 9 elementos (3x3) reais positivos (aleatórios e de sua escolha). Calcule e exiba a soma
// dos elementos de cada linha desta matriz.
#include<stdio.h>

int main(){
    float matriz[3][3] = {
        {1.5, 2.5, 3.5},
        {4.5, 5.5, 6.5},
        {7.5, 8.5, 9.5}
    };
    float somaLinha[3] = {0, 0, 0};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            somaLinha[i] += matriz[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        printf("Soma da linha %d: %.2f\n", i+1, somaLinha[i]);
    }

    return 0;
}
