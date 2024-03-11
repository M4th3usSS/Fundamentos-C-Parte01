/*
    Autor: Matheus Sousa
    Objetivo: Resolução de exercício:

    Escreva um programa que leia um valor de despesa de restaurante, o valor da gorjeta (em porcentagem) e o número 
    de pessoas para dividir a conta. Imprima o valor que cada um deve pagar. Assuma que a conta será dividida 
    igualmente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    float despesa, gorjeta, valorTotal, valorPorPessoa;
    int pessoas;

    printf("Digite o valor de despesa: R$ ");
    scanf("%f", &despesa);

    printf("Digite o percentual da gorjeta: ");
    scanf("%f", &gorjeta);

    printf("Digite a quantidade de pessoas que irá dividir a conta: ");
    scanf("%d", &pessoas);

    valorTotal = despesa + despesa * gorjeta / 100;
    valorPorPessoa = valorTotal / pessoas;

    printf("\n\n\tValor da total da conta: R$ %.2f\n", valorTotal);
    printf("\tValor por pessoa (%d pessoas): R$ %.2f\n\n", pessoas, valorPorPessoa);

    return 0;
}