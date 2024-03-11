#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aula_03() {

    /*
        Dica: Não usar a função system pause!
        
        A função system pause só funciona em sistemas Windows, usar essa função nos códigos fonte irá trazer problemas 
        de incompatibilidade em outros sistemas;
        Uma forma de contornar isso é usar recursos da biblioteca padrão da linguagem C: como a função getchar;
    */

    printf("\n\tDica: Não usar system pause!\n\t");
    printf("\nPressione qualquer tecla para finalizar.");
    getchar();
}

void aula_04() {

   /*
        Declaração de variáveis int e a função para entrada de dados scanf
   */

    int valor01;
    int valor02;

    printf("Digite o primeiro número: ");
    scanf("%d", &valor01);  // "&" - Usado para referênciar o endereço de memória da variável <valor01>
                            // "%d" - Placeholder do tipo int;

    printf("Digite o segundo número: ");
    scanf("%d", &valor02);  // "&" Usado para referênciar o endereço de memória da variável <valor02>
                            // "%d" - Placeholder do tipo int;

    printf("\n\nOs números digitados foram %d e %d\n\n", valor01, valor02);
}

void aula_05() {

    /*
        Declaração de variáveis float e a função para entrada de dados scanf
    */

    float valor01;
    float valor02;

    printf("Digite o primeiro número: ");
    scanf("%f", &valor01); // "&" - Usado para referênciar o endereço de memória da variável <valor01>
                           // "%f" Placeholder do tipo float;

    printf("Digite o segundo número: ");
    scanf("%f", &valor02); // "&" - Usado para referênciar o endereço de memória da variável <valor02>
                           // "%f" Placeholder do tipo float;

    printf("\n\nOs números digitados foram %.2f e %.2f\n\n", valor01, valor02);
}

void aula_06() {

    /*
        Declaração de variáveis char e a função para entrada de dados scanf
    */

    char letra = 'M';

    printf("\nValor da variável letra = %c\n", letra);

    printf("Digite apenas uma letra: ");
    scanf("%c", &letra); // "&" - Usado para referênciar o endereço de memória da variável <letra>
                         // "%c" - Placeholder do tipo char;

    printf("\n\nValor da variável letra = %c\n\n", letra);
}

void aula_07() {

    /*
        Variáveis char e a função de leitura getchar
    */

    char letra;

    printf("Digite uma letra: ");
    letra = getchar();

    printf("A letra digitada foi: %c\n", letra);

}

void aula_08() {

    /*
        Variáveis char e a função de leitura getc
    */

    char letra;

    printf("Digite um caracter: ");
    letra = getc(stdin);

    printf("Caracter lido: %c\n", letra);

}

void aula_09() {

    /*
        Variáveis char e a função de leitura  fgetc
    */

    char letra;

    printf("Digite um caracter: ");
    letra = fgetc(stdin);

    printf("Caracter lido: %c\n", letra);
}

void aula_10() {

    /*
        Lendo múltiplas variáveis:
        
        No programa você pode inserir cada variável isoladamente apertando <ENTER> ou inserir todas ao mesmo tempo, 
        separando seus valores por <ESPAÇOS>, mas lembre-se de inserir os valores na ordem correta!
    */

    int num1, num2, num3;

    printf("Digite três valores inteiros\n");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("\nPrimeiro número = %d\nSegundo número = %d\nTerceiro número = %d\n", num1, num2, num3);
}

void aula_11() {

    /*
        Exercício 01 - Lendo múltiplas variáveis de tipos diferentes
    */

    char sexo;
    int idade;
    float peso, altura;

    printf("Digite seu sexo[F/M], idade, peso e altura respectivamente:\n");
    scanf("%c%d%f%f", &sexo, &idade, &peso, &altura);

    printf("\n\n =============== Dados ================\n\n");
    printf("    Sexo: %c\n", sexo);
    printf("    Idade: %d anos\n", idade);
    printf("    Peso: %.2f Kg\n", peso);
    printf("    Altura: %.2f metros\n", altura);
    printf("\n ======================================\n\n");

}

void aula_12_01() {

    /*
        Problema ao ler caracter com a linguagem C

        O que acontece se lermos o caracter por último ?
     
        Qualquer comando do teclado pode ser representada por um caracter em C (ver tabela ASCII), o próprio <Enter> é 
        um caracter e pertence ao CONJUNTO DE CARACTERES DE CONTROLE. Logo, ao pressionar a tecla <Enter>, o carater 
        de quebra de linha (\n) será adicionado ao buffer do teclado. Esse \n no buffer do teclado será atribuido a 
        variável sexo quando a função scanf iterar pelo buffer, que por sua vez, possui o \n na fila.
     
        Isso causa estranheza já que esse comportamento não é comum para a maioria das funções de leitura das
        linguagens de programação mais modernas.
     
        Tente rodar esse exemplo e veja o problema do qual estamos falando:
    */

    char sexo;
    int idade;
    float peso, altura;

    printf("Digite sua idade, peso, altura e sexo[F/M] respectivamente:\n");
    scanf("%d%f%f%c", &idade, &peso, &altura, &sexo);

    printf("\n\n =============== Dados ================\n\n");
    printf("    Sexo: %c\n", sexo);
    printf("    Idade: %d anos\n", idade);
    printf("    Peso: %.2f Kg\n", peso);
    printf("    Altura: %.2f metros\n", altura);
    printf("\n ======================================\n\n");

    /*
        Perceba que nosso programa pulou a leitura da variável do tipo caracter, isso aconteceu pois quando apertamos
        <Enter> para confirmar a inserção da variável anterior, o \n foi inserido no buffer do teclado, esse \n foi
        inserido em nossa variável do tipo caracter pois o buffer continha esse caracter especial. Mas como resolver 
        isso ?
    */
}

void aula_12_02() {

    /*
        Problema ao ler caracter com a linguagem C

        Para solucionar o problema que o caracter \n presente no buffer causou, adicione um espaço antes do
        placeholder de caracter. Esse espaço serve como um comando para o compilador descartar o \n (e outros
        caracteres de controle) que estão presentes no buffer do teclado;

        Com o buffer limpo, agora nossa lógica funciona como esperado:
    */

    char sexo;
    int idade;
    float peso, altura;

    printf("Digite sua idade, peso, altura e sexo[F/M] respectivamente:\n");
    scanf("%d%f%f %c", &idade, &peso, &altura, &sexo); // Adicionamos o espaço!

    printf("\n\n =============== Dados ================\n\n");
    printf("    Sexo: %c\n", sexo);
    printf("    Idade: %d anos\n", idade);
    printf("    Peso: %.2f Kg\n", peso);
    printf("    Altura: %.2f metros\n", altura);
    printf("\n ======================================\n\n");
}

void aula_13() {

    /*
        Lendo dois caracteres consecutivos

        Atenção ao buffer do teclado!
        Use espaço antes do %c para eliminar caracteres de controle (\n \t <Espaços>):
    */

    char letra_01, letra_02;
    printf("Digite duas letras: ");
    scanf(" %c %c", &letra_01, &letra_02);
    printf("Primeira letra: %c\nSegunda letra: %c", letra_01, letra_02);

}

void aula_14() {

    /*
        Lendo dois caracteres consecutivos 

        Atenção ao buffer do teclado!
        Use espaço antes do %c para eliminar caracteres de controle (\n \t <Espaços>):
    */

    char a, b;

    printf("Digite uma letra: ");
    scanf(" %c", &a);
    printf("Digite outra letra: ");
    scanf(" %c", &b); // Espaço para limpar o \n do buffer!

    printf("\nValor da primeira letra = %c\nValor da segunda letra = %c\n",a, b);
}

/* Aula 15
    
    Explicação das unidades de armazenamento:
 
    A palavra bit vem do inglês e é uma abreviação de binary digit (dígito binário).
    O bit é a menor unidade de armazenamento, suportando um único dígito binário 0 ou 1. Na sequência, temos às 
    seguintes unidades:

    1 Byte = 8 bits.
    1 Kilobyte = 1024 bytes
    1 Megabyte = 1024 Kilobytes ou KB
    1 Gigabyte = 1024 Megabytes ou MB
    1 Terabyte = 1024 Gigabytes ou GB
    1 Petabyte = 1024 Terabytes ou TB
    1 Exabyte = 1024 Petabytes ou PB
    1 Zettabyte = 1024 Exabytes ou EB
    1 Yottabyte = 1024 Zettabytes ou ZB
 
*/

void aula_16() {

    /*
        Como descobrir o tamanho em memória de cada tipo de dado ?
        Use o operador sizeof
    */

    printf("Tamanho de um char (Nessa arquitetura): %d bytes(%d bits)\n", sizeof(char), sizeof(char) * 8);
    printf("Tamanho de um int (Nessa arquitetura): %d bytes (%d bits)\n", sizeof(int), sizeof(int) * 8);
    printf("Tamanho de um fload (Nessa arquitetura): %d bytes (%d bits)\n", sizeof(float), sizeof(float) * 8);
    printf("Tamanho de um double (Nessa arquitetura): %d bytes (%d bits)\n", sizeof(double), sizeof(double) * 8);
}

void aula_17() {

    /*
        Reduzindo o consumo de memória com o operador short

        Operador short para o tipo int: short int
        Intervalo convencional de um int = -2.147.483.648 até 2.147.483.647 (4 bytes);
        Intervalo do short int: = -32.768 até 32.767 (2 bytes);

        OBS.: Atribuição de valores fora do range da variável irá causar falhas de memória;
        
        Placeholders para short int = %hi ou %d

    */

    short int x = 32767;

    printf("Quantidade de bytes de uma variável do tipo short int: %d bytes (%d bits)\n", sizeof x, sizeof x * 8);

    printf("Valor de x: %d\n", x);
    x++;
    printf("Valor de (x + 1): %d (Estouro de variável)\n", x); // Exemplo de um estouro de variável

}

void aula_18() {

    /*
        Aula 18 - Somei 2 números positivos e o resultado ficou negativo
        Intervalo do int = -2.147.483.648 até 2.147.483.647
    */

    int x = 2147483647;

    printf("Valor de x: %d\n", x);
    x++;
    printf("Valor de (x + 1): %d (Estouro de variavel)\n", x); // Exemplo de um estouro de variável

}

void aula_19() {

    /*
        Aula 19 - Como aumentar o espço de memória para um int com o operador long ?

        O  espaço de um long int, assim como dos outros tipos, depende da arquitetura do sistema;
        No meu computador por exemplo, sizeof int == sizeof long int;
        Isso acontece porque arquiteturas recentes, como a do meu computador, consideram int com espaço de 32 bits;
        Podemos adicionar mais um long, com isso, aumentar ainda mais o espaço em memória, dobrando para 64 bits;
        
        OBS.: Não podemos usar o operador short duas vezes!
        
        PlaceHolders para long int %li / %ld
        PlaceHolders para long long int %lli / %lld
    */
 

    long int x = 2147483647;
    printf("Valor de x: %li\n", x);
    x++;
    printf("Valor de (x + 1): %ld\n", x); // Houve um estouro de variável pois int e long int possui a mesma quantidade
                                          // de bytes na arquitetura do meu computador;

    printf("Quantidade de bytes de uma variável do tipo long int: %d bytes (%d bits)\n\n", sizeof x, sizeof x * 8);


    long long int y = 2147483647;
    printf("Valor de y: %lli\n", y);
    y++;
    printf("Valor de (y + 1): %lld\n", y); // Não ocorreu estouro de variável pois aumentamos seu tamanho na memória,
                                           // consequentemente tambám aumentamos o seu range;

    printf("Quantidade de bytes de uma variável do tipo long long int: %d bytes (%d bits)\n", sizeof y, sizeof y * 8);
}

void aula_20() {

    /*
        Tipo primitivo para números reais - float
        
        Placeholder do float: %f
    */

    float x = 3.1415;

    printf("Imprimindo um número float: %f\n", x);
    printf("Um float precisa de %d bytes de memória.\n", sizeof x);
    printf("Um float precisa de %d bytes de memória.\n\n", sizeof(float));

}

void aula_21() {

    /*
        Tipo primitivo para números reais com dupla precisão - double

        Placeholder do double: %lf
    */

    double x = 3.1415;

    printf("Imprimindo um número double: %lf\n", x);
    printf("Um double precisa de %d bytes de memória.\n", sizeof x);
    printf("Um double precisa de %d bytes de memória.\n\n", sizeof(double));

}

void aula_22() {

    /*
        Como usar o operador long para o tipo primitivo double ?

        OBS.:
        Por padrão, o tipo double e o tipo float imprimem números com 6 casas decimais;
        Podemos alterar isso adionando instruções no placeholder de impressão.

        ATENÇÃO:
        Aqui temos uma situação interessante que mostra como os compiladores de sistema operacionais distintos
        tratam os códigos C para gerar os programas executáveis:
       
        Placeholder do double -> %lf (Comum para sistemas Linux e Windows);
        Placeholder do long double -> %Lf (Sistemas Linux)
        Para imprimir um long double no Windows, devemos usar uma função especial:
        __mingw_prinff(); -> (Devemos usar essa função em vez de printf() para sistemas Windows);

        Veja a situação.:
    */

    double x = 234.54324235235262;
    long double y = 3.1415926535897932384626433832795;

    printf("Um doble precisa de %d bytes de memória (Nessa arquitetura).\n", sizeof x);
    printf("Um long double precisa de %d bytes de memória (Nessa arquitetura).\n", sizeof y);
    printf("Valor de x (double - comum para Linux e Windows): %.10lf\n", x);

    printf("Valor de y (long double - base Linux): %.15Lf\n", y); // Para sistema baseado em Linux (Causa falha de
                                                                  // impressão em sistema Windows);

    __mingw_printf("Valor de y (long double - base Windows): %.15Lf\n", y); // Para sistemas Windons (Adaptação que 
                                                                            // deve ser feita);

}

void aula_23() {

    /*
        Caracteres de escape

        Quebra de linha -> \n
        Tabulação       -> \t
        Aspa dupla      -> \"
        Aspa simples    -> \'
        Contrabarra     -> \\
    */

    printf("\n\n\tIsto é uma \"mensagem\" a ser \'impressa\' na tela. \\ Contra barra \\\n\n");

}

void aula_24() {

    /*
        Operadores matemáticos

        Adição              +
        Subtração           -
        Multiplicação       *
        Divisão             /
    */

    printf("\nAdição: %d\n", 10 + 20);
    printf("\nSubtração: %d\n", 10 - 20);
    printf("\nMultiplição: %d\n", 10 * 20);
    printf("\nDivisão (int): %d\n", 10 / 20);
    printf("\nDivisão (fload): %f\n", 10.0 / 20.0);

}

void aula_25() {

    /*
        O que significa Casting ou conversão de tipos na linguagem C?

        Casting é um processo explicito ou implicito de alterar o tipo de uma variável, um exemplo que precisa de um 
        casting explicito é a divisão de dois números do tipo int. O resultado da divisão de dois números inteiros
        retorna também um número inteiro (divisão inteira). Para divisões de números inteiros onde a casa decimal 
        importa para o programa, deve-se fazer o casting de pelo menos um dos operandos da divisão. Mas atente-se para
        o uso de casting, informações podem ser perdidas nesse processo, como no caso de converter um número float com
        casa decimal para um número int, a parte decimal do número é perdida!

        Veja o alguns exemplos:
    */

    int a = 10, b = 20;

    printf("\nAdição: %d\n", a + b);
    printf("\nSubtração: %d\n", a - b);
    printf("\nMultiplição: %d\n", a * b);
    printf("\nDivisão (int): %d\n", a / b);
    printf("\nDivisão (fload): %f\n", (float)a / (float)b);

    float pi = 3.1415926;
    int pi_int = (int)pi;
    printf("\n\n\tValor de pi(float) = %f\n\tValor de pi(int) = %d\n\n",pi, pi_int);

}

void aula_26() {

    /*
        Operador resto da divisão - %
    */

    int a = 10;
    int b = 20;
    printf("Resto da divisão inteira de %d por %d = %d\n",a, b, a % b);

    a = 20;
    b = 10;
    printf("Resto da divisão inteira de %d por %d = %d\n",a, b, a % b);

}

void aula_27() {

    /*
        Operador de incremento ++

        Sinônimos:
        contador++;
        contador += 1;
        contador = contador + 1;
    */

    // operador de incremento pré-fixo (++variavel): incrementa na variável antes de usá-la em uma operação:
    int contador_pre_fixo = 0;
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);

    // operador de incremento pós-fixo (variavel++): incrementa na variável após usá-la em uma operação:
    int contador_pos_fixo = 0;
    printf("\nValor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);

    // Incremento pré-fixo na atribuição:
    int contador_01 = 0;
    int resultado_01 = ++contador_01; // primeiro incrementa no contador, depois atribui o valor na variável resultado;
    printf("\nResultado do incremento pré-fixo na atribuicao: %d\n", resultado_01);

    // Incremento pós-fixo na atribuição:
    int contador_02 = 0;
    int resultado_02 = contador_02++; // primeiro atribui o valor à variável resultado, depois incrementa no contador;
    printf("\nResultado do incremento pós-fixo na atribuicao: %d\n", resultado_02);

    /*
        Podemos concluir que tanto o pré-fixo quanto o pós-fixo tem o mesmo objetivo, mas são diferentes quanto a ordem
        das operações!
    */
}

void aula_28() {

    /*
        Operador de decremento --

        Sinônimos:
        contador--
        contador -= 1;
        contador = contador - 1;
    */

    // operador de decremento pré-fixo (--variável): decrementa na variável antes de usá-la em uma operação:
    int contador_pre_fixo = 10;
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);

    // operador de decremento pós-fixo (variável--): decrementa na variável após usá-la em uma operação:
    int contador_pos_fixo = 10;
    printf("\nValor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);


    // Decremento pré-fixo na atribuição:
    int contador_01 = 0;
    int resultado_01 = --contador_01; // primeiro decrementa do contador, depois atribui o valor na variável resultado;
    printf("\nResultado do decremento pré-fixo na atribuicao: %d\n", resultado_01);

    // Decremento pós-fixo na atribuição:
    int contador_02 = 0;
    int resultado_02 = contador_02--; // primeiro atribui o valor à variável resultado, depois decrementa do contador;
    printf("\nResultado do decremento pós-fixo na atribuicao: %d\n", resultado_02);

    /*
        Podemos concluir que tanto o pré-fixo quanto o pós-fixo tem o mesmo objetivo, mas são diferentes quanto a ordem
        das operações!
    */
}

void aula_29() {

    /*
        Operador unsigned

        O operador unsigned é usado para representar apenas números positivos;
        Intervalo do int = -2.147.483.648 até 2.147.483.647
        Intervalo do unsigned int = 0 até 4.294.967.295
        Placeholder para imprimir unsigned int: %u
    */


    unsigned int x = 2147483647;
    printf("\n\t%u\n\n", ++x); // => Com o operador de incremento pré-fixo, o valor imprimido sera: 2147483648
    x = 4294967295;
    printf("\n\t%u\n\n", x); 

    /*
        Podemos usar usigned com os operadores short e long:
        Placeholder para imprimir unsigned short int: %hu ou %d
        Placeholder para imprimir unsigned long int: %lu
        Placeholder para imprimir unsigned long long int: %llu
    */
    unsigned short int y = 55000;
    printf("\n\t%hu\n\n", y);

    unsigned long int w = 4000000000;
    printf("\n\t%lu\n\n", w);

    unsigned long long int t = 4000000000000000;
    printf("\n\t%llu\n\n", t);
}

void aula_30() {

    /*
        Tabela ASCII e acentuação

        intervalo do byte (8 Bits) -> -128 até 127
        intervalo do usigned byte  ->    0 até 255

        Alguns caracteres da tabela ASCII:

        =============================================================
        Snais de controle (não-imprimíveis)
        
        Bin         oct     Dec     Hex     Abrev       Código escape
        0000 0000   000     00      00      NULL        \0
        0000 1010	012     10      0A      LF          \n
        0000 1001	011     09      09      HT          \t
        ...
        =============================================================

        =============================================
        Sinais gráficos (imprimíveis)

        Bin         oct     Dec     Hex      Sinal
        0010 0000   040     32      20     (espaço)
        0100 0001   101     65      41         A
        0100 0010	102     66      42         B
        0100 0011   103     67      43         C
        0100 0100   104     68      44         D
        ...
        0110 0001   141     97      61         a
        0110 0010   142     98      62         b
        0110 0011   143     99      63         c
        0110 0100   144    100      64         d
        ...
        =============================================

        Tabela completa:
        https://pt.wikipedia.org/wiki/ASCII
        https://web.fe.up.pt/~ee96100/projecto/Tabela%20ascii.htm

    */

    // Vou escrever meu nome usando ACII:
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 77, 97, 116, 104, 101, 117, 115, 32, 83, 111, 117, 115, 97);
    printf("%d%d%d%d%d%d%d%d%d%d%d%d%d\n", 'M', 'a', 't', 'h', 'e', 'u', 's', ' ', 'S', 'o', 'u', 's', 'a');
    printf("%d %d %d %d %d %d %d %d %d %d %d %d %d\n", 'M', 'a', 't', 'h', 'e', 'u', 's', ' ', 'S', 'o', 'u', 's', 'a');

    /*
        Acentução

        Para resolver o problema de acentuação do cmd (Windows), devemos adicionar o include <locale.h>
        Ao adicionar essa biblioteca estamos pedindo ao compilador para usar a tabela ASCII estendida;
        Mas também precisamos de adicionar na fução main a função setlocale() com o atributo "Portuguese";
        O Encoding padrão utilizado para escrever esse código foi: ISO-8859-1 (Padrão do CMD Windows 10);
    */

    printf("Coração\n\n");

}

int main() {
    // Encoding utilizado - ISO 8859-1
    // setlocale(LC_ALL, NULL);        -> configuração padrão da linguagem (tabela ASCII simplificada);
    // setlocale(LC_ALL, "");          -> configuração padrão do sistema;
    // setlocale(LC_ALL, "Portuguese") -> Forçando para português;

    printf("%s\n\n", setlocale(LC_ALL, "Portuguese"));

    // Adicione a função da aula aqui:
    aula_30();

    return 0;
}

