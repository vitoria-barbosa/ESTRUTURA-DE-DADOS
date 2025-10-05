#include <stdio.h>

int main(void) {
    char s[3] = "um";
    char t[3] = "um";

    if(s == t) puts ("iguais");
    else puts ("diferentes");

    return 0;
}
// A saída é "diferentes" pois ele compara o endereço de mémoria das variáveis s e t.
// Para comparar o conteúdo das varíáveis temos que usar a função strcmp (string compare) da <string.h>