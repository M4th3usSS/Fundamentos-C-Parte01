/*
    Autor: Matheus Sousa
    Objetivo: Resolu��o de exerc�cio:

    Crie um programa em C que permita fazer a convers�o cambial entre Reais e D�lares. Considere como taxa de 
    c�mbio US$1,0 = R$5,30. Leia um valor em Reais e mostre o correspondente em D�lares.
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

    printf("\n\tValor e Dol�res: U$%.2f\n", valorUS);

    return 0;
}