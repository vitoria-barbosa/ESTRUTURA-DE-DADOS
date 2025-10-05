// Faça um programa com um vetor com 10 elementos inteiros
// positivos (aleatórios e de sua escolha). Permita que seja solicitado
// um determinado valor inteiro e positivo para ser procurado neste
// vetor. Caso exista, o programa deve exibir o índice no qual o valor
// está posicionado. Caso contrário, o programa deve informar que o
// elemento não existe no vetor.
#include<stdio.h>

int main(void){
    int vetor[10] = {3, 6, 7, 9, 44, 62, 77, 24, 98, 100};
    int n;
    puts("Digite um numero inteiro:");
    scanf("%d", &n);

    for(int i = 0; i < 10; i++){
        if(vetor[i] == n){
            printf("Esse numero esta no indice %d", i);
            return 0;
        }
    }
    printf("Esse numero nao existe no vetor.");
    return 0;
}