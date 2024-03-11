/*
    Autor: Matheus Sousa
    Objetivo: Resolu��o do exerc�cio:

    Elabore um algoritmo que receba, por meio do teclado, dois valores, um para a vari�vel <a> e um para a vari�vel 
    <b>. Em seguida, fa�a os passos que julgar necess�rio para que ao final, a vari�vel <a> possua o valor que 
    inicialmente estava em <b> e a vari�vel <b> possua o valor que inicialmente estava em <a>. Traduza seu 
    algoritmo para a linguagem C e exiba os valores na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "portuguese");

    int a, b, aux;

    printf("Digite o valor da vari�vel A: ");
    scanf("%d", &a);

    printf("Digite o valor da vari�vel B: ");
    scanf("%d", &b);
    
    aux = a;
    a = b;
    b = aux;

    printf("Novo valor de A: %d\nNovo valor de B: %d", a, b);

    return 0;
}