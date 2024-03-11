/*
    Autor: Matheus Sousa
    Objetivo: Resolução de exercício

    Uma empresa contrata um encanador a R$ 45,00 por dia. Faça um programa que solicite o número de dias trabalhados
    pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo que são descontados 8% para imposto de 
    renda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");

    float valorPago, impostoRenda;
    int diasTrabalhados = 0;

    printf("Digite a quantidade de dias trabalhados: ");
    scanf("%d", &diasTrabalhados);

    valorPago = 45.00 * diasTrabalhados;
    impostoRenda = valorPago * 0.08;
    valorPago -= impostoRenda;

    printf("\n\tValor do imposto de renda: R$%.2f\n", impostoRenda);
    printf("\tQuantidade líquida a ser paga: R$%.2f\n", valorPago);

    return 0;
}