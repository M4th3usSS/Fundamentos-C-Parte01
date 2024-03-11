/*
    Autor: Matheus Sousa
    Objetivo: Resolu��o de exerc�cio:

    Fa�a um programa para ler do teclado uma quantidade de segundos e imprimir na tela a convers�o para horas, 
    minutos e segundos.
    Exemplo:
    Entrada: 3672
    Sa�da: 1:1:12
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "portuguese");
    
    int segundos, h, m, s;

    printf("Digite a quantidade de segundos: ");
    scanf("%d", &segundos);

    h = segundos / 3600;
    m = segundos % 3600 / 60;
    s = segundos % 3600 % 60;
    printf("%d:%d:%d",h, m, s);

    return 0;
}