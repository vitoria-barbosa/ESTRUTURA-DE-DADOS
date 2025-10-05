#include <stdio.h>

int main(void) {
    int a = 3, b = 5;
    int *p = &a, *q = &b;

    *p = *p + *q;   // 3 + 5 = 8   a=8 b=5 
    *q = *p - *q;   // 8 - 5 = 3   a=8 b=3 
    *p = *p - *q;   // 8 - 3 = 5   a=5 b=3 

    printf("%d, %d\n", a, b);

    return 0;
}
// Saída: a = 5 e b = 3.
// O programa faz a troca dos valores de a e b sem o uso de uma variável auxiliar, usando somente ponteiros.