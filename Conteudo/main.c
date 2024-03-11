#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void aula_03() {

    /*
        Dica: N�o usar a fun��o system pause!
        
        A fun��o system pause s� funciona em sistemas Windows, usar essa fun��o nos c�digos fonte ir� trazer problemas 
        de incompatibilidade em outros sistemas;
        Uma forma de contarnar isso � usar recursos da biblioteca padr�o da linguagem C: como a fun��o getchar;
    */

    printf("\n\tDica: N�o usar system pause!\n\t");
    printf("\nPressione qualquer tecla para finalizar.");
    getchar();
}

void aula_04() {

   /*
        Declara��o de vari�veis int e a fun��o para entrada de dados scanf
   */

    int valor01;
    int valor02;

    printf("Digite o primeiro n�mero: ");
    scanf("%d", &valor01);  // "&" - Usado para refer�nciar o endere�o de mem�ria da vari�vel <valor01>
                            // "%d" - Placeholder do tipo int;

    printf("Digite o segundo n�mero: ");
    scanf("%d", &valor02);  // "&" Usado para refer�nciar o endere�o de mem�ria da vari�vel <valor02>
                            // "%d" - Placeholder do tipo int;

    printf("\n\nOs n�meros digitados foram %d e %d\n\n", valor01, valor02);
}

void aula_05() {

    /*
        Declara��o de vari�veis float e a fun��o para entrada de dados scanf
    */

    float valor01;
    float valor02;

    printf("Digite o primeiro n�mero: ");
    scanf("%f", &valor01); // "&" - Usado para refer�nciar o endere�o de mem�ria da vari�vel <valor01>
                           // "%f" Placeholder do tipo float;

    printf("Digite o segundo n�mero: ");
    scanf("%f", &valor02); // "&" - Usado para refer�nciar o endere�o de mem�ria da vari�vel <valor02>
                           // "%f" Placeholder do tipo float;

    printf("\n\nOs n�meros digitados foram %.2f e %.2f\n\n", valor01, valor02);
}

void aula_06() {

    /*
        Declara��o de vari�veis char e a fun��o para entrada de dados scanf
    */

    char letra = 'M';

    printf("\nValor da vari�vel letra = %c\n", letra);

    printf("Digite apenas uma letra: ");
    scanf("%c", &letra); // "&" - Usado para refer�nciar o endere�o de mem�ria da vari�vel <letra>
                         // "%c" - Placeholder do tipo char;

    printf("\n\nValor da vari�vel letra = %c\n\n", letra);
}

void aula_07() {

    /*
        Vari�veis char e a fun��o de leitura getchar
    */

    char letra;

    printf("Digite uma letra: ");
    letra = getchar();

    printf("A letra digitada foi: %c\n", letra);

}

void aula_08() {

    /*
        Vari�veis char e a fun��o de leitura getc
    */

    char letra;

    printf("Digite um caracter: ");
    letra = getc(stdin);

    printf("Caracter lido: %c\n", letra);

}

void aula_09() {

    /*
        Vari�veis char e a fun��o de leitura  fgetc
    */

    char letra;

    printf("Digite um caracter: ");
    letra = fgetc(stdin);

    printf("Caracter lido: %c\n", letra);
}

void aula_10() {

    /*
        Lendo m�ltiplas vari�veis:
        
        No programa voc� pode inserir cada vari�vel isoladamente apertando <ENTER> ou inserir todas ao mesmo tempo, 
        separando seus valores por <ESPA�OS>, mas lembre-se de inserir os valores na ordem correta!
    */

    int num1, num2, num3;

    printf("Digite tr�s valores inteiros\n");
    scanf("%d%d%d", &num1, &num2, &num3);

    printf("\nPrimeiro n�mero = %d\nSegundo n�mero = %d\nTerceiro n�mero = %d\n", num1, num2, num3);
}

void aula_11() {

    /*
        Exerc�cio 01 - Lendo m�ltiplas vari�veis de tipos diferentes
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

        O que acontece se lermos o caracter por �ltimo ?
     
        Qualquer comando do teclado pode ser representada por um caracter em C (ver tabela ASCII), o pr�prio <Enter> � 
        um caracter e pertence ao CONJUNTO DE CARACTERES DE CONTROLE. Logo, ao pressionar a tecla <Enter>, o carater 
        de quebra de linha (\n) ser� adicionado ao buffer do teclado. Esse \n no buffer do teclado ser� atribuido a 
        vari�vel sexo quando a fun��o scanf iterar pelo buffer, que por sua vez, possui o \n na fila.
     
        Isso causa estranheza j� que esse comportamento n�o � comum para a maioria das fun��es de leitura das
        linguagens de programa��o mais modernas.
     
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
        Perceba que nosso programa pulou a leitura da vari�vel do tipo caracter, isso aconteceu pois quando apertamos
        <Enter> para confirmar a inser��o da vari�vel anterior, o \n foi inserido no buffer do teclado, esse \n foi
        inserido em nossa vari�vel do tipo caracter pois o buffer continha esse caracter especial. Mas como resolver 
        isso ?
    */
}

void aula_12_02() {

    /*
        Problema ao ler caracter com a linguagem C

        Para solucionar o problema que o caracter \n presente no buffer causou, adicione um espa�o antes do
        placeholder de caracter. Esse espa�o serve como um comando para o compilador descartar o \n (e outros
        caracteres de controle) que est�o presentes no buffer do teclado;

        Com o buffer limpo, agora nossa l�gica funciona como esperado:
    */

    char sexo;
    int idade;
    float peso, altura;

    printf("Digite sua idade, peso, altura e sexo[F/M] respectivamente:\n");
    scanf("%d%f%f %c", &idade, &peso, &altura, &sexo); // Adicionamos o espa�o!

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

        Aten��o ao buffer do teclado!
        Use espa�o antes do %c para eliminar caracteres de controle (\n \t <Espa�os>):
    */

    char letra_01, letra_02;
    printf("Digite duas letras: ");
    scanf(" %c %c", &letra_01, &letra_02);
    printf("Primeira letra: %c\nSegunda letra: %c", letra_01, letra_02);

}

void aula_14() {

    /*
        Lendo dois caracteres consecutivos 

        Aten��o ao buffer do teclado!
        Use espa�o antes do %c para eliminar caracteres de controle (\n \t <Espa�os>):
    */

    char a, b;

    printf("Digite uma letra: ");
    scanf(" %c", &a);
    printf("Digite outra letra: ");
    scanf(" %c", &b); // Espa�o para limpar o \n do buffer!

    printf("\nValor da primeira letra = %c\nValor da segunda letra = %c\n",a, b);
}

/* Aula 15
    
    Explica��o das unidades de armazenamento:
 
    A palavra bit vem do ingl�s e � uma abrevia��o de binary digit (d�gito bin�rio).
    O bit � a menor unidade de armazenamento, suportando um �nico d�gito bin�rio 0 ou 1. Na sequ�ncia, temos �s 
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
        Como descobrir o tamanho em mem�ria de cada tipo de dado ?
        Use o operador sizeof
    */

    printf("Tamanho de um char (Nessa arquitetura): %d bytes(%d bits)\n", sizeof(char), sizeof(char) * 8);
    printf("Tamanho de um int (Nessa arquitetura): %d bytes (%d bits)\n", sizeof(int), sizeof(int) * 8);
    printf("Tamanho de um fload (Nessa arquitetura): %d bytes (%d bits)\n", sizeof(float), sizeof(float) * 8);
    printf("Tamanho de um double (Nessa arquitetura): %d bytes (%d bits)\n", sizeof(double), sizeof(double) * 8);
}

void aula_17() {

    /*
        Reduzindo o consumo de mem�ria com o operador short

        Operador short para o tipo int: short int
        Intervalo convencional de um int = -2.147.483.648 at� 2.147.483.647 (4 bytes);
        Intervalo do short int: = -32.768 at� 32.767 (2 bytes);

        OBS.: Atribui��o de valores fora do range da vari�vel ir� causar falhas de mem�ria;
        
        Placeholders para short int = %hi ou %d

    */

    short int x = 32767;

    printf("Quantidade de bytes de uma vari�vel do tipo short int: %d bytes (%d bits)\n", sizeof x, sizeof x * 8);

    printf("Valor de x: %d\n", x);
    x++;
    printf("Valor de (x + 1): %d (Estouro de vari�vel)\n", x); // Exemplo de um estouro de vari�vel

}

void aula_18() {

    /*
        Aula 18 - Somei 2 n�meros positivos e o resultado ficou negativo
        Intervalo do int = -2.147.483.648 at� 2.147.483.647
    */

    int x = 2147483647;

    printf("Valor de x: %d\n", x);
    x++;
    printf("Valor de (x + 1): %d (Estouro de variavel)\n", x); // Exemplo de um estouro de vari�vel

}

void aula_19() {

    /*
        Aula 19 - Como aumentar o esp�o de mem�ria para um int com o operador long ?

        O  espa�o de um long int, assim como dos outros tipos, depende da arquitetura do sistema;
        No meu computador por exemplo, sizeof int == sizeof long int;
        Isso acontece porque arquiteturas recentes, como a do meu computador, consideram int com espa�o de 32 bits;
        Podemos adicionar mais um long, com isso, aumentar ainda mais o espa�o em mem�ria, dobrando para 64 bits;
        
        OBS.: N�o podemos usar o operador short duas vezes!
        
        PlaceHolders para long int %li / %ld
        PlaceHolders para long long int %lli / %lld
    */
 

    long int x = 2147483647;
    printf("Valor de x: %li\n", x);
    x++;
    printf("Valor de (x + 1): %ld\n", x); // Houve um estouro de vari�vel pois int e long int possui a mesma quantidade
                                          // de bytes na arquitetura do meu computador;

    printf("Quantidade de bytes de uma vari�vel do tipo long int: %d bytes (%d bits)\n\n", sizeof x, sizeof x * 8);


    long long int y = 2147483647;
    printf("Valor de y: %lli\n", y);
    y++;
    printf("Valor de (y + 1): %lld\n", y); // N�o ocorreu estouro de vari�vel pois aumentamos seu tamanho na mem�ria,
                                           // consequentemente tamb�m aumentamos o seu range;

    printf("Quantidade de bytes de uma vari�vel do tipo long long int: %d bytes (%d bits)\n", sizeof y, sizeof y * 8);
}

void aula_20() {

    /*
        Tipo primitivo para n�meros reais - float
        
        Placeholder do float: %f
    */

    float x = 3.1415;

    printf("Imprimindo um n�mero float: %f\n", x);
    printf("Um float precisa de %d bytes de mem�ria.\n", sizeof x);
    printf("Um float precisa de %d bytes de mem�ria.\n\n", sizeof(float));

}

void aula_21() {

    /*
        Tipo primitivo para n�meros reais com dupla precis�o - double

        Placeholder do double: %lf
    */

    double x = 3.1415;

    printf("Imprimindo um n�mero double: %lf\n", x);
    printf("Um double precisa de %d bytes de mem�ria.\n", sizeof x);
    printf("Um double precisa de %d bytes de mem�ria.\n\n", sizeof(double));

}

void aula_22() {

    /*
        Como usar o operador long para o tipo primitivo double ?

        OBS.:
        Por padr�o, o tipo double e o tipo float imprimem n�meros com 6 casas decimais;
        Podemos alterar isso adionando instru��es no placeholder de impress�o.

        ATEN��O:
        Aqui temos uma situa��o interessante que mostra como os compiladores de sistema operacionais distintos
        tratam os c�digos C para gerar os programas execut�veis:
       
        Placeholder do double -> %lf (Comum para sistemas Linux e Windows);
        Placeholder do long double -> %Lf (Sistemas Linux)
        Para imprimir um long double no Windows, devemos usar uma fun��o especial:
        __mingw_prinff(); -> (Devemos usar essa fun��o em vez de printf() para sistemas Windows);

        Veja a situa��o.:
    */

    double x = 234.54324235235262;
    long double y = 3.1415926535897932384626433832795;

    printf("Um doble precisa de %d bytes de mem�ria (Nessa arquitetura).\n", sizeof x);
    printf("Um long double precisa de %d bytes de mem�ria (Nessa arquitetura).\n", sizeof y);
    printf("Valor de x (double - comum para Linux e Windows): %.10lf\n", x);

    printf("Valor de y (long double - base Linux): %.15Lf\n", y); // Para sistema baseado em Linux (Causa falha de
                                                                  // impress�o em sistema Windows);

    __mingw_printf("Valor de y (long double - base Windows): %.15Lf\n", y); // Para sistemas Windons (Adapta��o que 
                                                                            // deve ser feita);

}

void aula_23() {

    /*
        Caracteres de escape

        Quebra de linha -> \n
        Tabula��o       -> \t
        Aspa dupla      -> \"
        Aspa simples    -> \'
        Contrabarra     -> \\
    */

    printf("\n\n\tIsto � uma \"mensagem\" a ser \'impressa\' na tela. \\ Contra barra \\\n\n");

}

void aula_24() {

    /*
        Operadores matem�ticos

        Adi��o              +
        Subtra��o           -
        Multiplica��o       *
        Divis�o             /
    */

    printf("\nAdi��o: %d\n", 10 + 20);
    printf("\nSubtra��o: %d\n", 10 - 20);
    printf("\nMultipli��o: %d\n", 10 * 20);
    printf("\nDivis�o (int): %d\n", 10 / 20);
    printf("\nDivis�o (fload): %f\n", 10.0 / 20.0);

}

void aula_25() {

    /*
        O que significa Casting ou convers�o de tipos na linguagem C?

        Casting � um processo explicito ou implicito de alterar o tipo de uma vari�vel, um exemplo que precisa de um 
        casting explicito � a divis�o de dois n�meros do tipo int. O resultado da divis�o de dois n�meros inteiros
        retorna tamb�m um n�mero inteiro (divis�o inteira). Para divis�es de n�meros inteiros onde a casa decimal 
        importa para o programa, deve-se fazer o casting de pelo menos um dos operandos da divis�o. Mas atente-se para
        o uso de casting, informa��es podem ser perdidas nesse processo, como no caso de converter um n�mero float com
        casa decimal para um n�mero int, a parte decimal do n�mero � perdida!

        Veja o alguns exemplos:
    */

    int a = 10, b = 20;

    printf("\nAdi��o: %d\n", a + b);
    printf("\nSubtra��o: %d\n", a - b);
    printf("\nMultipli��o: %d\n", a * b);
    printf("\nDivis�o (int): %d\n", a / b);
    printf("\nDivis�o (fload): %f\n", (float)a / (float)b);

    float pi = 3.1415926;
    int pi_int = (int)pi;
    printf("\n\n\tValor de pi(float) = %f\n\tValor de pi(int) = %d\n\n",pi, pi_int);

}

void aula_26() {

    /*
        Operador resto da divis�o - %
    */

    int a = 10;
    int b = 20;
    printf("Resto da divis�o inteira de %d por %d = %d\n",a, b, a % b);

    a = 20;
    b = 10;
    printf("Resto da divis�o inteira de %d por %d = %d\n",a, b, a % b);

}

void aula_27() {

    /*
        Operador de incremento ++

        Sin�nimos:
        contador++;
        contador += 1;
        contador = contador + 1;
    */

    // operador de incremento pr�-fixo (++variavel): incrementa na vari�vel antes de us�-la em uma opera��o:
    int contador_pre_fixo = 0;
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);
    printf("Valor = %d\n", ++contador_pre_fixo);

    // operador de incremento p�s-fixo (variavel++): incrementa na vari�vel ap�s us�-la em uma opera��o:
    int contador_pos_fixo = 0;
    printf("\nValor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);
    printf("Valor = %d\n", contador_pos_fixo++);

    // Incremento pr�-fixo na atribui��o:
    int contador_01 = 0;
    int resultado_01 = ++contador_01; // primeiro incrementa no contador, depois atribui o valor na vari�vel resultado;
    printf("\nResultado do incremento pr�-fixo na atribuicao: %d\n", resultado_01);

    // Incremento p�s-fixo na atribui��o:
    int contador_02 = 0;
    int resultado_02 = contador_02++; // primeiro atribui o valor � vari�vel resultado, depois incrementa no contador;
    printf("\nResultado do incremento p�s-fixo na atribuicao: %d\n", resultado_02);

    /*
        Podemos concluir que tanto o pr�-fixo quanto o p�s-fixo tem o mesmo objetivo, mas s�o diferentes quanto a ordem
        das opera��es!
    */
}

void aula_28() {

    /*
        Operador de decremento --

        Sin�nimos:
        contador--
        contador -= 1;
        contador = contador - 1;
    */

    // operador de decremento pr�-fixo (--vari�vel): decrementa na vari�vel antes de us�-la em uma opera��o:
    int contador_pre_fixo = 10;
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);
    printf("Valor = %d\n", --contador_pre_fixo);

    // operador de decremento p�s-fixo (vari�vel--): decrementa na vari�vel ap�s us�-la em uma opera��o:
    int contador_pos_fixo = 10;
    printf("\nValor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);
    printf("Valor = %d\n", contador_pos_fixo--);


    // Decremento pr�-fixo na atribui��o:
    int contador_01 = 0;
    int resultado_01 = --contador_01; // primeiro decrementa do contador, depois atribui o valor na vari�vel resultado;
    printf("\nResultado do decremento pr�-fixo na atribuicao: %d\n", resultado_01);

    // Decremento p�s-fixo na atribui��o:
    int contador_02 = 0;
    int resultado_02 = contador_02--; // primeiro atribui o valor � vari�vel resultado, depois decrementa do contador;
    printf("\nResultado do decremento p�s-fixo na atribuicao: %d\n", resultado_02);

    /*
        Podemos concluir que tanto o pr�-fixo quanto o p�s-fixo tem o mesmo objetivo, mas s�o diferentes quanto a ordem
        das opera��es!
    */
}

void aula_29() {

    /*
        Operador unsigned

        O operador unsigned � usado para representar apenas n�meros positivos;
        Intervalo do int = -2.147.483.648 at� 2.147.483.647
        Intervalo do unsigned int = 0 at� 4.294.967.295
        Placeholder para imprimir unsigned int: %u
    */


    unsigned int x = 2147483647;
    printf("\n\t%u\n\n", ++x); // => Com o operador de incremento pr�-fixo, o valor imprimido sera: 2147483648
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
        Tabela ASCII e acentua��o

        intervalo do byte (8 Bits) -> -128 at� 127
        intervalo do usigned byte  ->    0 at� 255

        Alguns caracteres da tabela ASCII:

        =============================================================
        Snais de controle (n�o-imprim�veis)
        
        Bin         oct     Dec     Hex     Abrev       C�digo escape
        0000 0000   000     00      00      NULL        \0
        0000 1010	012     10      0A      LF          \n
        0000 1001	011     09      09      HT          \t
        ...
        =============================================================

        =============================================
        Sinais gr�ficos (imprim�veis)

        Bin         oct     Dec     Hex      Sinal
        0010 0000   040     32      20     (espa�o)
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
        Acentu��o

        Para resolver o problema de acentua��o do cmd (Windows), devemos adicionar o include <locale.h>
        Ao adicionar essa biblioteca estamos pedindo ao compilador para usar a tabela ASCII estendida;
        Mas tamb�m precisamos de adicionar na fu��o main a fun��o setlocale() com o atributo "Portuguese";
        O Encoding padr�o utilizado para escrever esse c�digo foi: ISO-8859-1 (Padr�o do CMD Windows 10);
    */

    printf("Cora��o\n\n");

}

int main() {
    // Encoding utilizado - ISO 8859-1
    // setlocale(LC_ALL, NULL);        -> configura��o padr�o da linguagem (tabela ASCII simplificada);
    // setlocale(LC_ALL, "");          -> configura��o padr�o do sistema;
    // setlocale(LC_ALL, "Portuguese") -> For�ando para portugu�s;

    printf("%s\n\n", setlocale(LC_ALL, "Portuguese"));

    // Adicione a fun��o da aula aqui:
    aula_30();

    return 0;
}

