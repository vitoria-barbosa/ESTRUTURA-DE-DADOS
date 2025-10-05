// Crie uma matriz de caracteres ( char ) de 16 posições (4x4).
// Preencha-a com os valores a , b , c , d , e , f , g , h , i , j ,
// k , l , m , n , o e p . Use dois for para exibir os valores desta
// matriz.
#include <stdio.h>

void exibirValores(char matriz[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%c ", matriz[i][j]); 
        }
        printf("\n");
    }
}

int main(void){
    char matriz[4][4];
    char letra = 97;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = letra;
            letra++;
        }
    }

    exibirValores(matriz);

    return 0;
}