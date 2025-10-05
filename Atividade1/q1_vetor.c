// Crie um vetor de inteiros ( int ) de 10 posições. Preencha-o
// com os valores 10 , 20 , 30 , 40 , 50 , 60 , 70 , 80 , 90 e
// 100 . Use um for para exibir os valores deste vetor
#include<stdio.h>

void exibirValores(int vetor[]){
    for(int i = 0; i < 10; i++){
        printf("%d ", vetor[i]);
    }
}

int main(void){
    int vetor[10];

    for(int i = 0, j = 10; i < 10; i++, j+=10){
        vetor[i] = j;
    }

    exibirValores(vetor);

    return 0;
}