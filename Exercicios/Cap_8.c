#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define ex01

#ifdef ex01

/*
    1 - Receba 2 string de ate 10 caracteres via teclado, compare-as usando ponteiros
    e mostre como resultado se s�o IGUAIS ou DIFERENTES.
*/

int main()
{
    setlocale(LC_ALL, "Portuguese");
    char C;
    char opcao = 's';

    while(opcao == 's' || opcao == 'S')
    {

        _Bool stringsIguais(char s1[], char s2[]);

        char s1[10];
        char s2[10];
        char *ps1;
        char *ps2;


        printf("Digite alguma palavra(max de 10 caracteres): ");
        scanf("%s", &s1);
        printf("Digite outra palavra (max de 10 caracteres): ");
        scanf("%s", &s2);

        ps1=&s1;
        ps2=&s2;

        if(stringsIguais(ps1,ps2))
        {
            printf(" S�o iguais\n");
        }
        else
        {
            printf(" N�o s�o iguais\n");
        }

        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();
    }
}

_Bool stringsIguais(char str1[], char str2[])
{

    int contador = 0;
    int igual = 0;
    while (str1[contador] != '\0' || str2[contador] != '\0')
    {
        if (str1[contador] == str2[contador])
        {
            ++igual;
        }
        ++contador;
    }
    if (igual == contador)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif

#ifdef ex02

/*

2 - Com a estrutura abaixo, defina um vetor de estruturas de 4 elementos.
    Receba os dados pelo teclado usando ponteiros e imprima-os no video
    tamb�m usando ponteiros. Utilize um comando de loop. (vetor de estruturas)
              nome, end, cidade, estado, cep

*/
struct cadastro
{
    char nome[20];
    char end[30];
    char cidade[20];
    char estado[20];
    char cep[9];
};

struct cadastro cliente[4];
struct cadastro *p[4];

void main()
{
    int op, i = 0, j;

    setlocale(LC_ALL, "Portuguese");

    while(op!=3)
    {


        printf("\n\t\t     ##### MENU #####\n\n\n");
        printf("\t\t1-Cadastrar cliente.\n\n");
        printf("\t\t2-Lista de clientes.\n\n");
        printf("\t\t3-Fechar programa.\n\n");

        printf("\n\t\tInforme a fun��o desejada: ");
        scanf_s("%d", &op);

        switch(op)
        {
        case 1:
            system("cls");

            if (i <= 3)
            {
                printf("\n\t\t     ##### CADASTRO DO CLIENTE #####\n\n\n");
                getchar();
                printf("\t\tInforme o nome do cliente: ");
                gets(cliente[i].nome);
                printf("\n\t\tInforme o endere�o do cliente: ");
                gets(cliente[i].end);
                printf("\n\t\tInforme a cidade: ");
                gets(cliente[i].cidade);
                printf("\n\t\tInforme estado: ");
                gets(cliente[i].estado);
                printf("\n\t\tInforme o CEP: ");
                gets(cliente[i].cep);
                printf("\n\t\t");

                p[0] = &cliente[0];
                p[1] = &cliente[1];
                p[2] = &cliente[2];
                p[3] = &cliente[3];
                i++;
            }
            else
            {
                system("cls");
                printf("\n\t\tLista lotada!\n\n\n\t\t");

            }

            system("pause");
            system("cls");
            break;

        case 2:
            system("cls");
            printf("\n\t\t     ##### DADOS DOS CLIENTES #####\n\n\n");

            if (i == 0)
            {
                system("cls");
                printf("\n\t\tLista vazia!\n\n\n\t\t");
            }
            else
            {
                for (j = 0; j < i; j++)
                {
                    printf("\n\t\tNOME: %s", p[j]->nome);
                    printf("\n\t\tENDERE�O: %s", p[j]->end);
                    printf("\n\t\tCIDADE: %s", p[j]->cidade);
                    printf("\n\t\tESTADO: %s", p[j]->estado);
                    printf("\n\t\tCEP: %s\n", p[j]->cep);

                }
            }
            printf("\n\t\t");
            system("pause");
            system("cls");
            break;

        default:
            system("cls");
            if(op!=3)
            {
                printf("\n\t\tA op��o informada n�o existe!\n\n\n\t\t");
                system("pause");
                system("cls");
                break;
            }
            else
            {
                printf("\n\t\t\PROGRAMA ENCERRADO !\n\n\t\t");
            }
        }

    }
}

#endif

#ifdef ex03
/*

3 - Receba um caracter via teclado usando ponteiros e compara com o vetor abaixo
    usando ponteiros. Mostre como resultado se EXISTE ou NAO EXISTE.
    vetor -> b,d,f,h,j,l,m,o,q,s,u,w,y

*/


main()
{

    setlocale(LC_ALL, "Portuguese");
    char opcao = 's';

    while(opcao == 's' || opcao == 'S')
    {

        static char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
        char letra;
        char *pc;
        int i,cont=0;

        printf("Digite uma letra: ");
        letra = getchar();
        printf("Resultado: ");

        pc=&letra;

        for(i=0; i<14; i++)
        {
            if(*pc==vetor[i])
            {
                printf("Valor Encontrado");
                cont++;
            }

        }

        if(cont==0)
        {
            printf("Valor N�O encontrado");
        }

        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();
        getchar();

    }
}

#endif



#ifdef ex04

/*
4 - Escreva um programa que receba via teclado usando ponteiros um char,
    int, long, unsigned,float, double, unsigned long e unsigned char,
    e imprima-os no video utilizando ponteiros e o operador de conteudo *
    no seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
*/

main()
{

    setlocale(LC_ALL, "Portuguese");
    char opcao = 's';
    char *pc,c;
    int *pi,i;
    long *pl,l;
    unsigned *pu,u;
    float *pf,f;
    double *pd,d;
    unsigned long *pul,ul;
    unsigned char *puc,uc;

    while(opcao == 's' || opcao == 'S')
    {

        printf("Char: ");
        c = getchar();

        printf("\nInt: ");
        scanf("%d",&i);

        printf("\nLong: ");
        scanf("%ld",&l);

        printf("\nUnsigned: ");
        scanf("%u",&u);

        printf("\nFloat: ");
        scanf("%f",&f);

        printf("\nDouble: ");
        scanf("%lf",&d);

        printf("\nUnsigned Long: ");
        scanf("%ul",&ul);

        printf("\nUnsigned Char: ");
        scanf("%u",&uc);

        pc = &c;
        pi = &i;
        pl = &l;
        pu = &u;
        pf = &f;
        pd = &d;
        pul = &ul;
        puc = &uc;

        printf("        10        20        30        40        50        60\n");
        printf("123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %d                   %ld                   %u        \n",*pi,*pl,*pu);
        printf("              %.2f               %.2f                 %c\n",*pf,*pd,*pc);
        printf("         %ul                  %u\n",*pul,*puc);

        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();

    }

}
#endif

#ifdef ex05

/*
5 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcular
    a media dos valores digitados e mostrar o resultado. Todos os calculos devem ser
    feitos usando ponteiro.
*/

main()
{

    system("color 1F");
    setlocale(LC_ALL, "Portuguese");

    char opcao = 's';
    float p=0;
    float cont=0;
    float *ponteiro = 0;
    float media = 0;


    while(opcao == 's' || opcao == 'S')
    {


        do
        {

            printf("\nDigite um n�mero: ");
            scanf("%f",&p);

            if(p>0)
            {

                ponteiro = &p;
                cont++;
                media+=*ponteiro;
            }

        }
        while(p>=0);

        if(media>0)
        {
            printf("\nM�dia: %.2f", media/cont);
            media=0; // � zerado para poder iniciar novamente sem bug.
            p=0;    // � zerado para poder iniciar novamente sem bug.
            cont=0; // � zerado para poder iniciar novamente sem bug.
        }

        else
        {
            printf("O usu�rio digitou apenas n�meros nulos 0 (zero) !");
        }

        printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();


    }

}

#endif

#ifdef ex06

/*
6 - Escreva um programa que contenha uma estrutura representando uma data valida.
    Essa estrutura deve conter os campos dia, mes e ano.

    Em seguida,leia duas datas e armazene nessa estrutura usando ponteiros.
    Calcule e exiba o numero de dias que decorreram entre as duas datas usando ponteiros.

*/
struct data
{
    int dia;
    int mes;
    int ano;
    int soma;
};

main()


{
    setlocale(LC_ALL, "Portuguese");

    static struct data dados[2], *ponteiro;
    ponteiro = &dados[0];

    int mesTrinta=0;
    int mesTrintaUm=0;
    int mesVinteOito=0;
    int soma=0;
    int diferencaDias=0;
    int somaDiferencaDias =0;
    int somaTotal=0;
    int mesmoMes=0;
    int bissexto=0;
    int contaAnos=0;
    int somaAnos =0;
    char opcao = 's';

    while(opcao == 's' || opcao == 'S')
    {



    for(int i=0; i<2; i++)          //La�o de repeti��o usado para coletar os dados.
    {

            system("color 07");

            do{
            printf("\tPor favor, informe uma data: \n\n");
            printf("Por favor, digite o %d dado: \n",i+1);      //O primeiro ano deve ser MENOR que o segundo ano!.
            printf("[Dia]: ");
            scanf("%d", &(*(ponteiro + i)).dia);


            if(((*(ponteiro + i)).dia < 1 || (*(ponteiro + i)).dia >31))
            {
                printf("\nN�mero Inv�lido !\n");
                printf("Digite um n�mero entre 1 e 31\n");
                system("color 40");
            }

            }while(((*(ponteiro + i)).dia < 1 || (*(ponteiro + i)).dia >31));       //La�o de repeti��o para valida��o de Dias


            system("color 07");
            do{
            printf("[M�s]: ");
            scanf("%d", &(*(ponteiro + i)).mes);

            if (((*(ponteiro + i)).mes <= 0) || (*(ponteiro + i)).mes >12)
            {
                printf("\nN�mero Inv�lido !\n");
                printf("Digite um n�mero entre 1 e 12\n");
                system("color 40");

            }

            }while(((*(ponteiro + i)).mes <= 0) || (*(ponteiro + i)).mes >12);    //La�o de repeti��o para valida��o de M�s


            system("color 07");
            do{
            printf("[Ano]: ");
            scanf("%d", &(*(ponteiro + i)).ano);


            if  ( (*(ponteiro + i)).ano <= 1900 || (*(ponteiro + i)).ano > 2100 && (2100 - (*(ponteiro + i)).ano <200))
            {
                printf("\nN�mero Inv�lido !\n");
                printf("Digite um n�mero entre 1900 e no m�ximo 2100\n");
                system("color 40");

            }

            }while( (*(ponteiro + i)).ano <= 1900 || (*(ponteiro + i)).ano > 2100 && (2100 - (*(ponteiro + i)).ano <200));        //La�o de repeti��o para valida��o: Ano limitado entre 1900 a 2100.






            if ((*(ponteiro + i)).mes == 4  || (*(ponteiro + i)).mes == 6  || (*(ponteiro + i)).mes == 9 || (*(ponteiro + i)).mes == 11) // Limitar meses selecionados, a inserir no m�ximo 30 dias.
            {


                if((*(ponteiro + i)).dia>=31)
                {
                    printf("A data digitada %d � inv�lida para o m�s digitado %d.\n",(*(ponteiro + i)).dia,(*(ponteiro + i)).mes);
                }


            }



            if ((*(ponteiro + i)).mes == 1 || (*(ponteiro + i)).mes == 3  || (*(ponteiro + i)).mes == 5 || (*(ponteiro + i)).mes == 7 || (*(ponteiro + i)).mes == 8 || (*(ponteiro + i)).mes == 10 || (*(ponteiro + i)).mes == 12) // Limitar meses selecionados, a inserir no m�ximo 31 dias.
            {

                if((*(ponteiro + i)).dia>=31)
                {
                    printf("A data digitada %d � inv�lida para o m�s digitado %d.\n",(*(ponteiro + i)).dia,(*(ponteiro + i)).mes);
                }

            }



            if ( (*(ponteiro + i)).ano % 400 == 0 || (*(ponteiro + i)).ano % 4 == 0 && (*(ponteiro + i)).ano % 100 != 0)            // Verifica��o ano bissexto.
            {

                bissexto=1;
                if((*(ponteiro + i)).mes==2 && (*(ponteiro + i)).dia > 29)
                {
                    printf("\nA data digitada %d � inv�lida para o m�s digitado.\n",(*(ponteiro + i)).dia);
                    printf("\ Ano Bissexto m�s de fevereiro (29 DIAS)\n");


                }

            }

            if(bissexto==0)                                                                         // Verifica��o m�s fevereiro m�x. 28 dias.
            {
                if((*(ponteiro + i)).mes==2 && (*(ponteiro + i)).dia > 28)
                {
                    printf("\nA data digitada %d � inv�lida para o m�s digitado.\n",(*(ponteiro + i)).dia);
                    printf("\M�s de fevereiro (28 DIAS)\n");

                }


            }

            bissexto=0;

    }


            //Processamento dos dados inseridos.


            contaAnos = abs((*(ponteiro + 0)).ano -(*(ponteiro + 1)).ano); //Conta para diferen�a de anos

            if((*(ponteiro + 0)).mes > (*(ponteiro + 1)).mes)          //Se o primeiro m�s for maior que o segundo m�s
            {
                (*(ponteiro + 1)).mes = (*(ponteiro + 1)).mes + 12;
            }




    if ((*(ponteiro + 0)).ano == (*(ponteiro + 1)).ano)       ////Ano Igual e Bissexto, mas n�o conta o m�s com 29 dias, pois data informada � acima de fevereiro.
    {

    if((*(ponteiro + 0)).ano % 400 == 0 || (*(ponteiro + 0)).ano % 4 == 0 && (*(ponteiro + 0)).ano % 100 != 0 && (*(ponteiro + 0)).mes > 2)
    {

        for(int i=(*(ponteiro + 0)).mes+1; i < (*(ponteiro + 1)).mes; i++)
        {

            if(i==4 || i == 6 || i == 9 || i == 11)
            {
                mesTrinta++;
            }
            else if (i==2)
            {
                mesVinteOito++;
            }

            else if (i==1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                mesTrintaUm++;
            }


            else if (i > 12)
            {
                i = 0;
                (*(ponteiro + 1)).mes = (*(ponteiro + 1)).mes - 12;
            }

        }


    }

    else if((*(ponteiro + 0)).ano % 400 == 0 || (*(ponteiro + 0)).ano % 4 == 0 && (*(ponteiro + 0)).ano % 100 != 0 && (*(ponteiro + 0)).mes <=2)   //Ano Igual e Bissexto, Conta o m�s com 29 dias!
    {
        bissexto+=1;

        for(int i=(*(ponteiro + 0)).mes+1; i < (*(ponteiro + 1)).mes; i++)
        {

            if(i==4 || i == 6 || i == 9 || i == 11)
            {
                mesTrinta++;
            }
            else if (i==2)
            {
                mesVinteOito++;
            }

            else if (i==1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                mesTrintaUm++;
            }


            else if (i > 12)
            {
                i = 0;
               (*(ponteiro + 1)).mes = (*(ponteiro + 1)).mes - 12;
            }

        }


    }

    else
    {

        for(int i=(*(ponteiro + 0)).mes+1; i < (*(ponteiro + 1)).mes; i++)
        {

            if(i==4 || i == 6 || i == 9 || i == 11)
            {
                mesTrinta++;
            }
            else if (i==2)
            {
                mesVinteOito++;
            }

            else if (i==1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            {
                mesTrintaUm++;
            }


            else if (i > 12)
            {
                i = 0;
                (*(ponteiro + 1)).mes = (*(ponteiro + 1)).mes - 12;
            }

        }


    }


}


        if(contaAnos > 1)      //Se Diferen�a de anos Maior que 1 ano
        {
            if((*(ponteiro + 0)).mes >2)
            {
                (*(ponteiro + 0)).ano = (*(ponteiro + 0)).ano + 1; //Aumenta um ano do ano original, para n�o entrar no c�lculo.

                for(int A=(*(ponteiro + 0)).ano; A < (*(ponteiro + 1)).ano; A++)
                {

                    if(A % 400 == 0 || A % 4 == 0 && A % 100 != 0)
                    {
                        bissexto++;
                    }

                }

            }

            else
            {

                for(int A=(*(ponteiro + 0)).ano; A < (*(ponteiro + 1)).ano; A++)
                {

                    if(A % 400 == 0 || A % 4 == 0 && A % 100 != 0)
                    {
                        bissexto++;
                    }

                }

            }


            for(int i=(*(ponteiro + 0)).mes+1; i < (*(ponteiro + 1)).mes; i++)
            {

                if(i==4 || i == 6 || i == 9 || i == 11)
                {
                    mesTrinta++;
                }
                else if (i==2)
                {
                    mesVinteOito++;
                }

                else if (i==1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    mesTrintaUm++;
                }


                else if (i > 12)
                {
                    i = 0;
                    (*(ponteiro + 0)).mes = (*(ponteiro + 1)).mes - 12;
                }

            }


        }


        if (contaAnos == 1)       //Anos com diferen�a de no m�ximo 1 (um) ano.
        {

            if((*(ponteiro + 0)).mes >2)
            {

                for(int A=(*(ponteiro + 0)).ano; A < (*(ponteiro + 1)).ano; A++)
                {

                    if(A % 400 == 0 || A % 4 == 0 && A % 100 != 0)
                    {
                        bissexto=0;
                    }

                }

            }

            else if ((*(ponteiro + 0)).mes <=2)
            {
                bissexto+=1;

            }


            for(int i=(*(ponteiro + 0)).mes+1; i < (*(ponteiro + 1)).mes; i++)
            {

                if(i==4 || i == 6 || i == 9 || i == 11)
                {
                    mesTrinta++;
                }
                else if (i==2)
                {
                    mesVinteOito++;
                }

                else if (i==1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
                {
                    mesTrintaUm++;
                }


                else if (i > 12)
                {
                    i = 0;
                    (*(ponteiro + 1)).mes = (*(ponteiro + 1)).mes- 12;
                }

            }


        }

                //C�lculo de Dias

        if ((*(ponteiro + 0)).mes == (*(ponteiro + 1)).mes)
        {
            mesmoMes = abs((*(ponteiro + 0)).dia - (*(ponteiro + 1)).dia);
        }


        else if((*(ponteiro + 0)).mes==4 || (*(ponteiro + 0)).mes == 6 || (*(ponteiro + 0)).mes == 9 || (*(ponteiro + 0)).mes == 11)
        {
            diferencaDias = 30 - (*(ponteiro + 0)).dia;
        }


        else if ((*(ponteiro + 0)).mes==2)
        {
            diferencaDias = 28 - (*(ponteiro + 0)).dia;
        }


        else if ((*(ponteiro + 0)).mes==1 || (*(ponteiro + 0)).mes == 3 || (*(ponteiro + 0)).mes == 5 || (*(ponteiro + 0)).mes == 7 || (*(ponteiro + 0)).mes == 8 || (*(ponteiro + 0)).mes == 10 || (*(ponteiro + 0)).mes == 12)
        {
            diferencaDias = 31 - (*(ponteiro + 0)).dia;
        }



                        //C�lculo de Exce��es


        if( (*(ponteiro + 0)).dia == (*(ponteiro + 1)).dia && (*(ponteiro + 0)).mes == (*(ponteiro + 1)).mes && (*(ponteiro + 0)).ano != (*(ponteiro + 1)).ano)
        {
            somaAnos = contaAnos * 365;
        }


        if((*(ponteiro + 0)).mes!=(*(ponteiro + 1)).mes)
        {
            somaDiferencaDias = diferencaDias + dados[1].dia;
        }

        soma = (mesTrinta * 30) + (mesVinteOito * 28) + (mesTrintaUm * 31);


        if(contaAnos >1)
        {
            somaAnos = contaAnos * 365;
        }

        else if(contaAnos >=1 && (*(ponteiro + 0)).mes - (*(ponteiro + 1)).mes <2)

        {
            somaAnos = contaAnos * 365;
        }


                                    //Sa�da de Dados !


        (*(ponteiro + 0)).soma = somaDiferencaDias + soma + mesmoMes + somaAnos + bissexto;
        system("cls");
        system("color 1F");
        printf("\n\n\n\t\t\t\t ###############################################");
        printf("\n\t\t\t\t Os dias que decorreram entre as duas datas = %d. \n", (*(ponteiro + 0)).soma);
        printf("\t\t\t\t ###############################################\n\n");

        system("pause");

         printf("\nTecle 's' se deseja continuar\n\n");
        opcao = getch();


    }

}




#endif



