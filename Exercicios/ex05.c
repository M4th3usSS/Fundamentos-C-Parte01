/*
    Autor: Matheus Sousa
    Objetivo: Resolu��o de exerc�cio

    Uma empresa contrata um encanador a R$ 45,00 por dia. Fa�a um programa que solicite o n�mero de dias trabalhados
    pelo encanador e imprima a quantia l�quida que dever� ser paga, sabendo que s�o descontados 8% para imposto de 
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
    printf("\tQuantidade l�quida a ser paga: R$%.2f\n", valorPago);

    return 0;
}