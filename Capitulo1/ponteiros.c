#include <stdio.h>

int main(){
    int var = 15;
    int *ptr;

    ptr = &var;

    printf("conteudo de var = %d\n", var);
    printf("endereco de var = %p\n", &var);
    printf("conteudo apontado por ptr = %d\n", *ptr);
    printf("endereco apontado por ptr = %p\n", ptr);
    printf("endereco de ptr = %p\n", &ptr);
    printf("\n\n");

    *ptr = 99;

    printf("conteudo de var = %d\n", var);
    printf("endereco de var = %p\n", &var);
    printf("conteudo apontado por ptr = %d\n", *ptr);
    printf("endereco apontado por ptr = %p\n", ptr);
    printf("endereco de ptr = %p\n", &ptr);

    return 0;
}

/* 
Ponteiros:
*ptr : o apontado por, conteudo do endereço da variável que ptr aponta
 ptr : o endereço da variável que ptr aponta
 &ptr o endereço do ponteiro
*/