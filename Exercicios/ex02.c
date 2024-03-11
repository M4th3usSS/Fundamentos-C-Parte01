/*
    Autor: Matheus Sousa
    Objetivo: Resolução do exercício:

    Elabore um algoritmo que receba, por meio do teclado, dois valores, um para a variável <a> e um para a variável 
    <b>. Em seguida, faça os passos que julgar necessário para que ao final, a variável <a> possua o valor que 
    inicialmente estava em <b> e a variável <b> possua o valor que inicialmente estava em <a>. Traduza seu 
    algoritmo para a linguagem C e exiba os valores na tela.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "portuguese");

    int a, b, aux;

    printf("Digite o valor da variável A: ");
    scanf("%d", &a);

    printf("Digite o valor da variável B: ");
    scanf("%d", &b);
    
    aux = a;
    a = b;
    b = aux;

    printf("Novo valor de A: %d\nNovo valor de B: %d", a, b);

    return 0;
}