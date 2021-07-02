#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//nao lista todos os enderecos iguais


/*      PROGRAMA  DESAFIO 2.

1 - Escreva um programa que tem a estrutura de dados abaixo. O programa tem as seguintes op��es de menu:

   1 � entrada dados.
   2 � lista todos os dados na tela.
   3 � pesquisar um registro pelo nome completo.
   4 � pesquisar por endere�o completo
   5 � pesquisar os aniversariantes de um determinado m�s.
   6 � pesquisar por faixa salarial
   7 - altera valor do sal�rio, pesquisado pelo nome completo
   8 � altera dados, pesquisado pelo nome completo.
   9 � exclui dados, pesquisado pelo nome completo.
   10 � sa�da pelo usu�rio

Estrutura: nome, endere�o, data de nascimento, sal�rio.

A �nica estrutura de dados do programa deve ser vari�vel local na fun��o main(). Portanto a passagem da estrutura para as fun��es utiliza ponteiro.

Cada uma das op��es do menu � uma fun��o no programa.

Todas as opera��es devem ser feitas direto no arquivo. (utilize a fun��o fseek).

O programa tem um �nico arquivo de dados. N�o pode usar nenhum arquivo auxiliar.

O programa deve ser finalizado pelo usu�rio.

N�o pode usar nenhuma fun��o de biblioteca. Somente as fun��es de manipula��o de arquivos.

*/

int op;
struct dados
{
    char nome [25];
    char endereco [25];
    char dataNascimento[10];
    double salario;
};

void inserir(struct dados *p, FILE *KP);
void listar(struct dados *p, FILE *KP);
int pesquisarNome(struct dados *p, FILE *KP);
int pesquisarEndereco(struct dados *p, FILE *KP);
int pesquisarNiver(struct dados *p, FILE *KP);
int pesquisarSalario(struct dados *p, FILE *KP);
void alterarSalario(struct dados *p, FILE *KP);
void alterarDados(struct dados *p, FILE *KP);
void excluir(struct dados *p, FILE *KP);


main()
{
    static struct dados funcionario;
    struct dados *p;

    p = &funcionario;

    FILE *KP;
    setlocale(LC_ALL,"Portuguese");


    printf("\n");
    printf("**********************************************************************\n");
    printf("*               DESAFIO 2 - LINGUAGEM 'C' - PROF� RUI                *\n");
    printf("*                         -    GRUPO 04    -                         *\n");
    printf("* LUCAS BRAGA PERES - DIEGO DE SOUSA BRAND�O - LUCAS CALDAS DA SILVA *\n");
    printf("**********************************************************************\n");


    do
    {


        printf("\n");
        printf("\t01. Entrada de Dados\n");
        printf("\t02. Listagem de Dados\n");
        printf("\t03. Pesquisar um registro pelo nome completo\n");
        printf("\t04. Pesquisar por endere�o completo\n");
        printf("\t05. Pesquisar os aniversariantes do m�s, digite o m�s desejado: \n");
        printf("\t06. Pesquisar por faixa salarial\n");
        printf("\t07. Alterar valor do sal�rio, pesquisado pelo nome completo\n");
        printf("\t08. Alterar dados, pesquisado pelo nome completo.\n");
        printf("\t09. Exclui dados, pesquisado pelo nome completo.\n");
        printf("\t10. Sa�da pelo usu�rio\n");
        printf("\n");
        system("color 1E");


        printf("Selecione uma op��o: ");
        scanf("%d",&op);
        getchar();

        switch(op)
        {
        case 1:
            inserir(p,KP);
            break;
        case 2:
            listar(p,KP);
            break;
        case 3:
            pesquisarNome(p,KP);
            break;
        case 4:
            pesquisarEndereco(p,KP);
            break;
        case 5:
            pesquisarNiver(p,KP);
            break;
        case 6:
            pesquisarSalario(p,KP);
            break;
        case 7:
            alterarSalario(p,KP);
            break;
        case 8:
            alterarDados(p,KP);
            break;
        case 9:
            excluir(p,KP);
            break;
        case 10:
            system("cls");
            printf("\n\n\t\t\tPrograma sendo Encerrado...\n\n");
            system("color 0F");
            break;
        default:
            system("cls");
            system("color 4F");
            printf("\n\n\t\t\t\t****************************");
            printf("\n\t\t\t\t\tOp��o Inv�lida!\n");
            printf("\t\t\t\tPor favor, digite outra op��o.\n");
            printf("\t\t\t\t****************************\n\n");
        }

        printf("\n");
        system("pause");
        system("cls");
    }
    while(op!=10);

}



void inserir(struct dados *p, FILE *KP)
{
    KP = fopen("funcionarios.txt","a");

    printf("\n\t\tInsira seu nome: ");
    gets(p->nome);

    printf("\n\t\tInsira seu endere�o: ");
    gets(p->endereco);

    printf("\n\t\tInsira seu m�s de nascimento (DD/MM/AAAA): ");
    gets(p->dataNascimento);

    printf("\n\t\tInsira seu sal�rio: ");
    scanf("%lf",&p->salario);

    fwrite(p,sizeof(*p),1,KP);

    fclose(KP);
}


void listar(struct dados *p, FILE *KP)
{
    int i;

    KP = fopen("funcionarios.txt","r");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }

    else
    {
        system("cls");



        printf("\n\n\t\t\%c%c%c%c%c LISTAGEM FUNCION�RIOS %c%c%c%c%c \n\n",4,4,4,4,4,4,4,4,4,4);



        printf("\n\t\t _________________________________________________________________________________");
        printf("\n\t\t|                   |                     |                    |                  |");
        printf("\n\t\t|       NOME        |      ENDERE�O       |   M�S ANIVERS�RIO  |     SAL�RIO      |");
        printf("\n\t\t|___________________|_____________________|____________________|__________________|");



        while(1)
        {
            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
                if(p->nome[0] != '*')
                {


                    printf("\n            %18s %26s %14s %20.2lf", p->nome, p->endereco, p->dataNascimento, p->salario);

                }
            }
            else
            {
                break;
            }
        }

        fclose(KP);

        printf("\n\n\n\n\t\t");
    }
}



int pesquisarNome(struct dados *p, FILE *KP)
{
    int i, j, cont = 0;
    unsigned char pesq[25] = "\0";

    KP = fopen("funcionarios.txt","r");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLISTA VAZIA!\n");
        printf("\t\t\t\t############\n\n");
    }
    else
    {
        system("cls");

        printf("\n\n\t\t\t%c%c%c PESQUISAR NOME DE FUNCION�RIO %c%c%c\n\n",4,4,4,4,4,4);

        printf("\n\t\tInsira o nome do funcion�rio: ");
        gets(pesq);

        while(1)
        {
            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
                if(p->nome[0] != '*')
                {
                    for (j = 0; p->nome[j] != '\0'; j++)
                    {
                        if (p->nome[j] != pesq[j])
                        {
                            break;
                        }
                    }
                }

                cont++;

                if (p->nome[j] == '\0' && pesq[j] == '\0')
                {

                    printf("\n\t\t _________________________________________________________________________________");
                    printf("\n\t\t|                   |                     |                    |                  |");
                    printf("\n\t\t|       NOME        |      ENDERE�O       |   M�S ANIVERS�RIO  |     SAL�RIO      |");
                    printf("\n\t\t|___________________|_____________________|____________________|__________________|");




                    printf("\n            %18s %26s %14s %20.2lf\n\n", p->nome, p->endereco, p->dataNascimento, p->salario);


                    fclose(KP);

                    return (cont);
                }
            }
            else
            {
                break;
            }
        }
        system("cls");
        system("color 02");
        printf("\n\n\n\t\t\t\tFUNCION�RIO N�O ENCONTRADO!\n");
        fclose(KP);

        return (-1);
    }
}

int pesquisarEndereco(struct dados *p, FILE *KP)
{
    int i, j, cont = 0;
    unsigned char pesq[25] = "\0";

    KP = fopen("funcionarios.txt","r");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }
    else
    {
        system("cls");

        printf("\n\n\t\t\t%c%c%c PESQUISAR ENDERE�O DE FUNCION�RIO %c%c%c\n\n",4,4,4,4,4,4);

        printf("\n\t\tInsira o endere�o do funcion�rio: ");
        gets(pesq);

        while(1)
        {
            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
                if(p->endereco[0] != '*')
                {


                    for (j = 0; p->endereco[j] != '\0'; j++)
                    {
                        if (p->endereco[j] != pesq[j])
                        {
                            break;
                        }
                    }
                }

                cont++;

                if (p->endereco[j] == '\0' && pesq[j] == '\0')
                {

                    printf("\n\t\t _________________________________________________________________________________");
                    printf("\n\t\t|                   |                     |                    |                  |");
                    printf("\n\t\t|       NOME        |      ENDERE�O       |   M�S ANIVERS�RIO  |     SAL�RIO      |");
                    printf("\n\t\t|___________________|_____________________|____________________|__________________|");




                    printf("\n            %18s %26s %14s %20.2lf\n\n", p->nome, p->endereco, p->dataNascimento, p->salario);


                    fclose(KP);

                    return (cont);
                }
            }
            else
            {
                break;
            }
        }
        system("cls");
        system("color 02");
        printf("\n\n\n\t\t\t\tENDERE�O N�O ENCONTRADO!\n");
        fclose(KP);

        return (-1);
    }
}


int pesquisarNiver(struct dados *p, FILE *KP)
{
    int i, j, cont=0;
    char niverMes[3];

    KP = fopen("funcionarios.txt","r");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }
    else
    {
        system("cls");

        printf("\n\n\t\t\t%c%c%c PESQUISAR ANIVERSARIANTES DO M�S %c%c%c\n\n",4,4,4,4,4,4);

        printf("\n\t\tInsira o m�s desejado (MM): ");
        gets(niverMes);

        while(1)
        {
            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
                if(p->nome[0] != '*')
                {

                    if(p->dataNascimento[3]  == niverMes[0] && p->dataNascimento[4] == niverMes[1] )
                    {
                        if(cont == 0)
                        {
                            printf("\n\t\t _________________________________________________________________________________");
                            printf("\n\t\t|                   |                     |                    |                  |");
                            printf("\n\t\t|       NOME        |      ENDERE�O       |   M�S ANIVERS�RIO  |     SAL�RIO      |");
                            printf("\n\t\t|___________________|_____________________|____________________|__________________|");

                            cont++;
                        }


                        printf("\n            %18s %26s %14s %20.2lf\n\n", p->nome, p->endereco, p->dataNascimento, p->salario);


                    }
                }
            }
            else
            {
                break;
            }
        }

        printf("\n\n\n\n\t\t");

        fclose(KP);

        if(cont == 0)
        {
            system("cls");
            system("color 02");
            printf("\n\n\n\t\t\t\tN�O H� ANIVERSARIANTES NESTE M�S!\n");

        }
    }
}


int pesquisarSalario(struct dados *p, FILE *KP)
{
    int i, j, cont=0;
    double valorA,valorB;

    KP = fopen("funcionarios.txt","r");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }
    else
    {
        system("cls");

        printf("\n\n\t\t\t%c%c%c PESQUISAR FAIXA SALARIAL %c%c%c\n\n",4,4,4,4,4,4);

        printf("\n\t\tInsira o valor m�nimo: ");
        scanf("%lf",&valorA);
        printf("\n\t\tInsira o valor m�ximo: ");
        scanf("%lf",&valorB);

        while(1)
        {
            i = fread(p,sizeof(*p),1,KP);

            if(i == 1)
            {
                if(p->nome[0] != '*')
                {

                    if(p->salario >=valorA && p->salario <= valorB)
                    {
                        if(cont == 0)
                        {
                            printf("\n\t\t _________________________________________________________________________________");
                            printf("\n\t\t|                   |                     |                    |                  |");
                            printf("\n\t\t|       NOME        |      ENDERE�O       |   M�S ANIVERS�RIO  |     SAL�RIO      |");
                            printf("\n\t\t|___________________|_____________________|____________________|__________________|");

                            cont++;
                        }


                        printf("\n            %18s %26s %14s %20.2lf\n\n", p->nome, p->endereco, p->dataNascimento, p->salario);


                    }
                }
            }
            else
            {
                break;
            }
        }

        printf("\n\n\n\n\t\t");

        fclose(KP);

        if(cont == 0)
        {
            system("cls");
            system("color 02");
            printf("\n\n\n\t\t\t\tN�O H� SAL�RIOS NESTA FAIXA!\n");

        }
    }
}


void alterarSalario(struct dados *p, FILE *KP)
{

    int k, y;

    KP = fopen("funcionarios.txt","r+");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }


    else
    {
        k = pesquisarNome(p, KP);

        if(k == -1)
        {
            printf("\t\t\t\tErro no processo!");
        }


        else
        {

            printf("\n\n\t\tInsira o novo sal�rio: ");
            scanf("%lf",&p->salario);

            KP = fopen("funcionarios.txt","r+");

            y = sizeof(*p)*(k-1);

            fseek(KP,y,0);

            fwrite(p,sizeof(*p),1,KP);

            fclose(KP);

        }

        printf("\n\n\t\t");

    }
}

void alterarDados(struct dados *p, FILE *KP)
{

    int k, y;

    KP = fopen("funcionarios.txt","r+");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }


    else
    {
        k = pesquisarNome(p, KP);

        if(k == -1)
        {
            printf("\t\t\t\tErro no processo!");
        }


        else
        {
            printf("\n\t\tALTERANDO DADOS: \n");

            printf("\n\t\tInsira seu nome: ");
            gets(p->nome);

            printf("\n\t\tInsira seu endere�o: ");
            gets(p->endereco);

            printf("\n\t\tInsira seu m�s de nascimento (DD/MM/AAAA): ");
            gets(p->dataNascimento);

            printf("\n\n\t\tInsira o novo sal�rio: ");
            scanf("%lf",&p->salario);

            KP = fopen("funcionarios.txt","r+");

            y = sizeof(*p)*(k-1);

            fseek(KP,y,0);

            fwrite(p,sizeof(*p),1,KP);

            fclose(KP);

        }

        printf("\n\n\t\t");

    }
}

void excluir(struct dados *p, FILE *KP)
{
    int k, y;

    KP = fopen("funcionarios.txt","r+");

    if(KP == NULL)
    {
        system("cls");
        system("color F0");
        printf("\n\n\t\t\t\t############");
        printf("\n\t\t\t\tLista vazia!\n");
        printf("\t\t\t\t############\n\n");
    }
    else
    {
        k = pesquisarNome(p, KP);

        if(k == -1)
        {
            printf("\t\t\t\tErro no processo!");
        }
        else
        {

            p->nome[0] = '*';
            p->endereco[0] = '*';
            p->dataNascimento[0] = '*';
            p->salario = 0;

            KP = fopen("funcionarios.txt","r+");

            y = sizeof(*p)*(k-1);

            fseek(KP,y,0);

            fwrite(p,sizeof(*p),1,KP);

            fclose(KP);

            printf("\n\t\t\t***** DADOS DO FUNCION�RIO EXCLU�DOS *****\n\n");

            printf("\n\n\t\t");
        }
    }
}


