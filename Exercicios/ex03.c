/*
    Autor: Matheus Sousa;
    Objetivo: Resolução de exercício;

    Faça um programa em C para trocar o valor de duas variáveis inteiras sem utilizar nenhuma variável auxiliar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int a, b;

    printf("Digite o valor da variável A: ");
    scanf("%d", &a);

    printf("Digite o valor da variável B: ");
    scanf("%d", &b);
    
    a = a + b;
    b = a - b;
    b = b - a;

    printf("Novo valor de A: %d\nNovo valor de B: %d", a, b);

    return 0;
}