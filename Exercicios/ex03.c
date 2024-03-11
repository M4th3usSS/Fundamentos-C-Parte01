/*
    Autor: Matheus Sousa;
    Objetivo: Resolu��o de exerc�cio;

    Fa�a um programa em C para trocar o valor de duas vari�veis inteiras sem utilizar nenhuma vari�vel auxiliar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    int a, b;

    printf("Digite o valor da vari�vel A: ");
    scanf("%d", &a);

    printf("Digite o valor da vari�vel B: ");
    scanf("%d", &b);
    
    a = a + b;
    b = a - b;
    b = b - a;

    printf("Novo valor de A: %d\nNovo valor de B: %d", a, b);

    return 0;
}