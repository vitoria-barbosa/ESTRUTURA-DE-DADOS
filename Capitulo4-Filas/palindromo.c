// verifica se uma cadeia é palíndroma (ordem original da frase = ordem inversa)

#include <stdio.h>
#include <ctype.h>
#include "fila.h"
#include "../Capitulo3-Expressoes/pilhaChar.h"
#define MAX 256

int ehPalindromo(char frase[MAX]){
    Fila F = fila(MAX);
    Pilha P = pilha(MAX);

    for (int i = 0;  frase[i]; i++){
        if (isalpha(frase[i])){
            enfileira(toupper(frase[i]), F);
            empilha(toupper(frase[i]), P);
        }   
    }

    while(!vaziaf(F)){
        if(desenfileira(F) != desempilha(P)) return 0;
    }

    destroif(&F);
    destroip(&P);
    return 1;
}

int main(){
    char frase[MAX];
    
    printf("\nDigite a frase: ");
    gets(frase);
    
    puts(ehPalindromo(frase)? "\nPalindromo!" : "\nNao palindromo!");

    return 0;
}