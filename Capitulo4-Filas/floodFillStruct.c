#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct{
    int x, y;
} Ponto;


typedef struct {
    Ponto dados[TAM * TAM];
    int inicio, final;
} Fila;


void inicializarFila(Fila *f) {
    f->inicio = f->final = 0;
}


int filaVazia(Fila *f) {
    return f->inicio == f->final;
}


void enfileirar (Fila *f, int x, int y) {
    f->dados[f->final].x = x;
    f->dados[f->final].y = y;
    f->final++;
}


Ponto desenfileirar(Fila *f) {
    return f->dados[f->inicio++];
}

void exibirImagem(int imagem[TAM][TAM]){
    for(int v = 0; v < TAM; v++){
        for(int t = 0; t < TAM; t++){
            printf("%d ", imagem[v][t]); 
        } 
    printf("\n");
    }
}


void floodFill(int imagem[TAM][TAM], int linhas, int colunas, int x, int y, int novaCor) {
    int corOriginal = imagem[x][y];
    if (corOriginal == novaCor) return;

    Fila fila;
    inicializarFila(&fila);
    enfileirar(&fila, x,y);

    while(!filaVazia(&fila)) {
        Ponto p = desenfileirar(&fila);
        int i = p.x; // índice na linha
        int j = p.y; // índice na coluna

        if (i<0 || i>=linhas || j<0 || j>=colunas) continue;
        if (imagem[i][j] != corOriginal) continue;

        imagem[i][j] = novaCor;
        enfileirar(&fila, i+1, j);
        enfileirar(&fila, i-1, j);
        enfileirar(&fila, i, j+1);
        enfileirar(&fila, i, j-1);
    }
}

int main(){
    int imagem[TAM][TAM] = {
        {1, 1, 1, 2, 2},
        {1, 1, 0, 2, 2},
        {1, 0, 0, 2, 2},
        {1, 1, 0, 2, 2},
        {1, 1, 1, 2, 2}
    };

    printf("Imagem inicial:\n");
    exibirImagem(imagem);

    floodFill(imagem, TAM, TAM, 2, 2, 9);

    printf("\n\n");
    printf("Imagem apos trocar o 0 por 9:\n");
    exibirImagem(imagem);

    return 0;
}