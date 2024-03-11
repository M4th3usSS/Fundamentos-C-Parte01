/*
    Autor: Matheus Sousa
    Objetivo: Resolução de exercício:

    Crie um programa em C que permita fazer a conversão cambial entre Reais e Dólares. Considere como taxa de 
    câmbio US$1,0 = R$5,30. Leia um valor em Reais e mostre o correspondente em Dólares.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    float valorRS, valorUS;

    printf("Digite o valor em Reais: R$");
    scanf("%f", &valorRS);

    valorUS = valorRS / 5.30;

    printf("\n\tValor e Doláres: U$%.2f\n", valorUS);

    return 0;
}