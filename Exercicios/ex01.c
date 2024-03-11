/*
    Autor: Matheus Sousa
    Objetivo: Resolução do exercício:

    Leia a idade, peso, altura e sexo[M/F] de uma pessoa. Imprima essas informações;
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "portuguese");

    int idade;
    float peso, altura;
    char sexo;

    printf("Digite a sua idade, peso, altura e sexo [M/F] em ordem:\n");
    scanf("%d%f%f %c", &idade, &peso, &altura, &sexo);

    printf(
        "\n\tIdade = %d\
        \n\tPeso = %.2f\
        \n\tAltura = %.2f\
        \n\tSexo = %c\n\n",
        idade, peso, altura, sexo
    );

    return 0;
}
