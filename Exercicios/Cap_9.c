#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex01

#ifdef ex01
void recepcao();
void exibicao(char *pc, int *pi, long int *pl, unsigned *pu, float *pf, double *pd, unsigned long *plu, unsigned char *puc);



main()
{

    /*
    1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura � uma variavel local na fun��o main().Receba via teclado o
    conteudo de cada um dos membros numa fun��o e imprima-os no video no
    seguinte formato(tamb�m numa fun��o).

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long

    */

    setlocale(LC_ALL, "Portuguese");
    char opcao = 's';
    while(opcao == 's' || opcao == 'S')
    {
        recepcao();





        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();
        getchar();


    }

}

void recepcao()
{
    char c;
    int i;
    long l;
    unsigned u;
    float f;
    double d;
    unsigned long lu;
    unsigned char uc;

    puts("Char: ");
    c = getchar();

    puts("\nInt: ");
    scanf("%d",&i);

    puts("\nLong: ");
    scanf("%ld",&l);

    puts("\nUnsigned: ");
    scanf("%u",&u);

    puts("\nFloat: ");
    scanf("%f",&f);

    puts("\nDouble: ");
    scanf("%lf",&d);

    puts("\nUnsigned Long: ");
    scanf("%u",&lu);

    puts("\nUnsigned Char: ");
    scanf("%u",&uc);

    exibicao(&c, &i, &l, &u, &f, &d, &lu, &uc);
}


void exibicao(char *pc, int *pi, long int *pl, unsigned *pu, float *pf, double *pd, unsigned long *plu, unsigned char *puc)
{
    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %d                   %ld                   %u        \n",*pi,*pl,*pu);
    printf("              %.2f               %.2f                 %c\n",*pf,*pd,*pc);
    printf("         %u                  %u\n",*plu,*puc);

}

#endif

#ifdef ex02
/*
    2 - Escreva um programa que receba n valores via teclado, receba tamb�m a opera��o a ser executada.

        Quando for digitado "=" o programa deve mostrar o resultado acumulado dos n valores.

        As opera��es aritmeticas e a entrada de dados devem ser fun��es que recebe os valores usando ponteiros.

*/

int soma(int x, int y);
int subt(int x, int y);
int multi(int x, int y);
float divis(int x, int y);

main()
{

    setlocale(LC_ALL, "Portuguese");

    int num1, num2, res = 0;
    int *numA,*numB, *resultado;
    numA = &num1;
    numB = &num2;
    resultado = &res;

    char op;
    char *pont;
    pont = &op;


    char opcao = 's';

    while(opcao == 's' || opcao == 'S')
    {

        printf("Digite um numero: ");
        scanf("%d",&numA);

        do
        {
            printf("\nDigite a opera��o escolhida:");
            printf("\nSoma(+): ");
            printf("\nSubtra��o(-): ");
            printf("\nDivis�o(/): ");
            printf("\nMultiplica��o(*):\n");
            op = _getche();
            if(op == '=')
            {
                break;
            }
            printf("\nDigite outro numero: ");
            scanf("%d",&numB);
            system("clear||cls");//comando para limpar a tela.

            switch(op)
            {
            case '+':
                res += soma(numA,numB);
                printf("\nSe deseja parar digite o s�mbolo de igual (=)");
                break;
            case '-':
                res -= subt(numA,numB);
                printf("\nSe deseja parar digite o s�mbolo de igual (=)");
                break;
            case '*':
                res *= multi(numA,numB);
                printf("\nSe deseja parar digite o s�mbolo de igual (=)");
                break;
            case '/':
                res /= (int) divis(numA,numB);
                printf("\nSe deseja parar digite o s�mbolo de igual (=)");
                break;
            }
            num1 = res;
            printf("\n\n");
        }
        while(1==1);
        resultado = res;
        printf("\nUltimo resultado: %d", resultado);
        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();

    }

}

//Fun��es
int soma(int x, int y)
{
    return x + y;
}

int subt(int x, int y)
{
    return x - y;
}

int multi(int x, int y)
{
    return x * y;
}

float divis(int x, int y)
{
    return (float) x / (float) y;
}

#endif


#ifdef ex03
_Bool pesquisa(char letra, char *vetor, int tamanho);

main()
{
    /*

    3 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa no
    video na funcao main(). O vetor � uma variavel local na fun��o main().Passe
    como parametro para a funcao o vetor e a letra digitada usando ponteiros.
    Pesquise usando ponteiros. (utilize o comando return)
    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

    */

    static char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    char letra;
    char *pc;
    char *vet;
    setlocale(LC_ALL, "Portuguese");
    char opcao = 's';

    while(opcao == 's' || opcao == 'S')
    {

        puts("Digite uma letra: ");
        letra = getchar();
        pc=&letra;
        puts("Resultado: ");

        vet=&vetor;
        if(pesquisa(letra,&vetor[0],sizeof(vet)))
        {
            puts("Valor encontrado !");
        }
        else
        {
            puts("Valor N�O encontrado");
        }

        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();
        getchar();

    }


}

_Bool pesquisa(char letra,char *vetor,int tamanho)
{
    int i;
    for(i=0; i<tamanho; i++)
    {
        if(letra==vetor[i])
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

#endif

#ifdef ex04

/*
    4 - Escreva um programa que receba em 1 funcao 2 strings de ate' 10 caracteres.
        Os vetores sao declaradas como variavel local na fun��o main().

        Escreva uma funcao que recebe as 2 strings como parametros usando ponteiros
        e compare estas 2 strings.

        Retorne como resultado da comparacao
        0 se forem DIFERENTES,
        1 se forem IGUAIS,
        2 se a string 1 for maior que a string 2,
        3 se a string 2 for maior que a string 1 e
        4 se as string tem tamanhos iguais mas s�o diferentes.

*/


int main()
{
    setlocale(LC_ALL, "Portuguese");
    char C;
    char opcao = 's';

    while(opcao == 's' || opcao == 'S')
    {

        int stringsIguais(char s1[], char s2[]);

        char s1[10];
        char s2[10];
        char *p1;
        char *p2;

        printf("Digite alguma palavra(max de 10 caracteres): ");
        scanf("%s", &s1);
        printf("Digite outra palavra (max de 10 caracteres): ");
        scanf("%s", &s2);

        p1=&s1;
        p2=&s2;

        stringsIguais(p1,p2);  //ponteiros sendo usados como parametros.

        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();
    }
}

int stringsIguais(char str1[], char str2[])
{

    int i = 0;
    int igual = 0;
    int x=0,y=0;

    while (str1[i] != '\0' || str2[i] != '\0')  //Verificar igual das strings
    {
        if (str1[i] == str2[i])
        {
            igual++;
        }
        i++;

    }

    for(int j =0; str1[j] != '\0';j++){   //Verificar tamanho das strings
        x++;
    }

    for(int k=0; str2[k] != '\0'; k++){
         y++;
    }


    if(x==y && igual==i)        //Selecionando conforme pedido no enunciado
    {
        printf("1");
    }

    else if(x > y)
    {
        printf("0 e 2");
    }

    else if(x < y)
    {
        printf("0 e 3");
    }
    else{
        printf("4");
    }



}

#endif

#ifdef ex05

/*


5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel local na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa fun��o e imprima todos os registros no
    video em outra funcao. Fa�a um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a op��o de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
                nome, end, cidade, estado, cep

*/

struct dados
{
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(struct dados *pessoas);
void exibicao(struct dados *pessoas);

main()
{
    int i, op;
    struct dados pessoas[3];
    do
    {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados\n3 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op)
        {
        case 1:
            recepcao(pessoas);
            break;
        case 2:
            exibicao(pessoas);
            break;
        case 3:
            printf("\nEncerrando...\n");
            break;
        }
    }
    while(op != 3);
}

void recepcao(struct dados *pessoas)
{
    int i;
    for(i=0; i<3; i++)
    {
        puts("Digite seu nome: ");
        gets(pessoas[i].nome);
        puts("Digite seu endereco: ");
        gets(pessoas[i].end);
        puts("Digite sua cidade: ");
        gets(pessoas[i].cidade);
        puts("Digite seu estado: ");
        gets(pessoas[i].estado);
        puts("Digite seu cep: ");
        gets(pessoas[i].cep);
        printf("\n");
    }
}

void exibicao( struct dados *pessoas)
{
    int i;
    for(i=0; i<3; i++)
    {
        printf("\n");
        printf("Nome: %s\n",pessoas[i].nome);
        printf("Endereco: %s\n",pessoas[i].end);
        printf("Cidade: %s\n",pessoas[i].cidade);
        printf("Estado: %s\n",pessoas[i].estado);
        printf("Cep: %s\n",pessoas[i].cep);
    }
}



#endif

#ifdef ex06

/*

6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro.

*/

struct dados
{
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(struct dados *pessoas);
void exibicao(struct dados *pessoas);
void procurar(struct dados *pessoas);
void alterar(struct dados *pessoas);
void excluir(struct dados *pessoas);
int checarNome(char *nome, struct dados *pessoas);

main()
{
    int i, op; //             nome, end, cidade, estado, cep
    struct dados pessoas[3] = {"Diego Brandao","Rua Irineu","Santos","sp","11029000",
                               "Lucas braga","Rua Joaquim","Santos","sp","11029000",
                               "Lucas caldas","Avenida Brasil","Santos","sp","11087000"};
    do
    {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados \n3 - Procurar\n4 - Alterar\n5 - Excluir\n6 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op)
        {
        case 1:
            recepcao(pessoas);
            break;
        case 2:
            exibicao(pessoas);
            break;
        case 3:
            procurar(pessoas);
            break;
        case 4:
            alterar(pessoas);
            break;
        case 5:
            excluir(pessoas);
            break;
        case 6:
            printf("\nEncerrando...\n");
            break;
        }
    }
    while(op != 6);
}

void recepcao(struct dados *pessoas)
{
    int i;
    for(i=0; i<3; i++)
    {
        puts("Digite seu nome: ");
        gets(pessoas[i].nome);
        puts("Digite seu endereco: ");
        gets(pessoas[i].end);
        puts("Digite sua cidade: ");
        gets(pessoas[i].cidade);
        puts("Digite seu estado: ");
        gets(pessoas[i].estado);
        puts("Digite seu cep: ");
        gets(pessoas[i].cep);
        printf("\n");
    }
}

void exibicao(struct dados *pessoas)
{
    int i;
    for(i=0; i<3; i++)
    {
        printf("\n");
        printf("Nome: %s\n",pessoas[i].nome);
        printf("Endereco: %s\n",pessoas[i].end);
        printf("Cidade: %s\n",pessoas[i].cidade);
        printf("Estado: %s\n",pessoas[i].estado);
        printf("Cep: %s\n",pessoas[i].cep);
    }
}

void procurar(struct dados *pessoas)
{
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, pessoas);
    if(i >= 0)
    {
        printf("\nNome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\n", pessoas[i].nome,pessoas[i].end,pessoas[i].cidade,pessoas[i].estado,pessoas[i].cep);
    }
}

void alterar(struct dados *pessoas)
{
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, pessoas);
    if(i >= 0)
    {
        puts("Digite seu novo nome: ");
        gets(pessoas[i].nome);
        puts("Digite seu novo endereco: ");
        gets(pessoas[i].end);
        puts("Digite sua nova cidade: ");
        gets(pessoas[i].cidade);
        puts("Digite seu novo estado: ");
        gets(pessoas[i].estado);
        puts("Digite seu novo cep: ");
        gets(pessoas[i].cep);
        printf("\n");
    }
}

void excluir(struct dados *pessoas)
{
    int i, j;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, pessoas);
    if(i >= 0)
    {
        strcpy(pessoas[i].nome,"");
        strcpy(pessoas[i].end,"");
        strcpy(pessoas[i].cidade,"");
        strcpy(pessoas[i].estado,"");
        strcpy(pessoas[i].cep,"");
        printf("\n\"Excluido\"\n");
    }
}

int checarNome(char *nome, struct dados *pessoas)
{
    int i,j,c = 0;
    for(i=0; i<3; i++)
    {
        if(strlen(nome)==strlen(pessoas[i].nome))
        {
            for(j=0; j<strlen(nome); j++)
            {
                if(nome[j]==pessoas[i].nome[j])
                {
                    c++;
                }
            }
            if(c == strlen(pessoas[i].nome))
            {
                puts("Nome encontrado!");
                return i;
            }
            else
            {
                c = 0;
            }
        }
    }
    puts("Nome nao encontrado!");
    return -1;

}

#endif



