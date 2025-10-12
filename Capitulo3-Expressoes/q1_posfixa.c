#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilhaChar.h"

int prioridade(char operador) {
    switch (operador) {
        case '(' : return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return-1;
}

char *converterPosfixa(char *exp) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for (int i = 0; exp[i]; i++)
        if (exp[i] == '(' ) empilha(exp[i], P);
        else if (isdigit(exp[i])) s[j++] = exp[i];
        else if (strchr("+-*/", exp[i])){
            while (!vaziap(P) && prioridade(topo(P)) >= prioridade(exp[i])){
                s[j++] = desempilha(P);
            }
            empilha(exp[i], P);
        }
        else if (exp[i] == ')' ){
            while (topo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P);
        }

    while (!vaziap(P))
        s[j++] = desempilha(P);

    s[j] = '\0';
    destroip(&P);
    return s;    
}

float calcularPosfixa(char *pos){
    Pilha P = pilha(256);
    for(int i = 0; pos[i]; i++){
        if(isdigit(pos[i])){
            empilha(pos[i] - '0', P);
        } 
        else{
            float b = desempilha(P);
            float a = desempilha(P);
            switch(pos[i]){
                case '+': empilha(a + b, P); break;
                case '-': empilha(a - b, P); break;
                case '*': empilha(a * b, P); break;
                case '/': empilha(a / b, P); break;
            }
        }
    }
    float resultado = desempilha(P);
    destroip(&P);
    return resultado;
}

int main(void) {
    char expressao[256];
    printf("Infixa: ");
    gets(expressao);
    char *posfixa = converterPosfixa(expressao);
    printf("Posfixa: %s\n\n", posfixa);
    printf("Resultado: %.1f\n", calcularPosfixa(posfixa));

    return 0;
}