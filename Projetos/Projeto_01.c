/********************************************************************************
1 – Pesquise as funções de biblioteca abaixo que manipulam arquivos.

fopen();
fclose();
fwrite(); cuidado com esta função
fread(); cuidado com esta função
fseek();
exit(0);

2 - Escreva um programa que tem 1 vetores bidimensional produto[3][20]
e 1 vetores quantidade[3] declaradas como variáveis globais.

Na função main() faça um menu com as seguintes funções:

1 – entrada de dados.
2 – lista todos os dados na tela.
3 – pesquisa um produto com o nome completo e mostra na tela
4 – pesquisa os produtos pela 1. letra e mostra todos na tela.
5 – altera dados. Com pesquisa pelo produto com o nome completo.
6 – exclui dados. Com pesquisa pelo produto com o nome completo.
7 - saída

OBS: Os 2 vetores devem ser escritos e lidos de um arquivo.

********************************************************************************/

/*
P1 - Linguagem C - Prof Rui

Grupo 04:
Lucas Braga Peres
Diego de Sousa Brandão
Lucas Caldas da Silva
*/

/* Bibliotecas */
#include <stdio.h>
#include <locale.h>

/* Variáveis Globais */

int const tam_produto = 20;
int const tam_quantidade = 4;

char produto[3][20]; // Vetor bidimensional 3 linhas 20 colunas
int quantidade[3]; // Vetor tamanho 3

char palavra[20];

int opcao;

void menu(); // ok
int quantidade_disponivel(); // ok
void carregar_arquivo(); // ok
void gravar_arquivo(); // ok
void inserir_registro(); // ok
void listar(); // ok

void buscar_produto(); // ok
void buscar_letra();

void alterar_registro();
void excluir_registro();

/* Método MAIN */
main()
{
    setlocale(LC_ALL, "Portuguese");

    carregar_arquivo();

    printf("\n");
    printf("**********************************************************************\n");
    printf("*               DESAFIO 1 - LINGUAGEM 'C' - PROFº RUI                *\n");
    printf("**********************************************************************\n");

    do
    {
        menu(); // Executa MENU de opção até usuário sair (opção 7)

    }
    while (opcao != 7);

}

/* Tela de Opções + Switch Case */
void menu()
{
    int opcaoDesejada;
    printf("\n*****************************************\n\n");
    printf("Quantidade disponível: %d\n\n", quantidade_disponivel());
    printf("*****************************************\n\n");
    printf("1. Inserir produto\n");
    printf("2. Listar produtos\n");
    printf("3. Pesquisar produto\n");
    printf("4. Pesquisar produto pela primeira letra\n");
    printf("5. Alterar dados\n");
    printf("6. Excluir dados\n");
    printf("7. Sair\n\n");
    printf("Selecione a opcao desejada: ");
    scanf("%d", &opcao);
    printf("\n\n");

    switch (opcao)
    {
    case 1:
        inserir_registro();
        break;
    case 2:
        listar();
        break;
    case 3:
        buscar_produto();
        break;
    case 4:
        buscar_letra();
        break;
    case 5:
        alterar_registro();
        break;
    case 6:
        excluir_registro();
        break;
    case 7:
        printf ("FIM!\n");
        break;
    default :
        printf ("Valor inválido!\n");
    }
}

// Calcula quantos espaços do vetor estão disponíveis (0 a 3)
// A quantidade aparece no Menu
int quantidade_disponivel()
{
    int qtd = 3;
    if (produto[0][0] != '\0' && produto[0][0] != '*')
        qtd--;

    if (produto[1][0] != '\0' && produto[1][0] != '*')
        qtd--;

    if (produto[2][0] != '\0' && produto[2][0] != '*')
        qtd--;

    return qtd;
}

void carregar_arquivo()
{

    FILE* arquivo = fopen("dados_desafio.txt", "r");
    // Abre um arquivo texto para leitura.
    // O arquivo deve existir antes de ser aberto.

    if (!arquivo)
    {
        arquivo = fopen("dados_desafio.txt", "w");
        // Abrir um arquivo texto para gravação.
        // Se o arquivo não existir, ele será criado.
        return;
    }

    // SEEK_SET = Inicio do arquivo
    //

    fread(&produto[0], tam_produto, 1, arquivo);

    fread(&quantidade[0], tam_quantidade, 1, arquivo);

    fread(&produto[1], tam_produto, 1, arquivo);

    fread(&quantidade[1], tam_quantidade, 1, arquivo);

    fread(&produto[2], tam_produto, 1, arquivo);

    fread(&quantidade[2], tam_quantidade, 1, arquivo);

    fclose(arquivo);
}


void gravar_arquivo()
{
    FILE* arquivo = fopen("dados_desafio.txt", "r+");
    if (!arquivo)
    {
        printf("Ocorreu um erro inesperado ao tentar gravar o arquivo...");
        exit(-1);
    }

    fwrite(&produto[0], tam_produto, 1, arquivo);

    fwrite(&quantidade[0], tam_quantidade, 1, arquivo);

    fwrite(&produto[1], tam_produto, 1, arquivo);

    fwrite(&quantidade[1], tam_quantidade, 1, arquivo);

    fwrite(&produto[2], tam_produto, 1, arquivo);

    fwrite(&quantidade[2], tam_quantidade, 1, arquivo);

    fclose(arquivo);
}


// CASE 01
void inserir_registro()
{
    if (quantidade_disponivel() == 0)
    {
        printf("\nO arquivo de dados está cheio!");
        printf("\nPor favor exclua um registro antes de continuar.\n\n");
    }

    printf("Digite o produto: ");
    scanf("%s", &produto[0]);
    printf("\nDigite a quantidade: ");
    scanf("%d", &quantidade[0]);

    printf("Digite o produto: ");
    scanf("%s", &produto[1]);
    printf("\nDigite a quantidade: ");
    scanf("%d", &quantidade[1]);

    printf("Digite o produto: ");
    scanf("%s", &produto[2]);
    printf("\nDigite a quantidade: ");
    scanf("%d", &quantidade[2]);

    gravar_arquivo();
    printf("\nRegistro armazenado com sucesso!\n\n");
}

// CASE 02
void listar()
{

    printf("*****************************************\n");
    printf("\nLista de Produtos\n");

    if (quantidade_disponivel() == 3)
    {
        printf("\nNão há registros a serem exibidos!\n\n");
        printf("\n*****************************************\n");
    }
    else
    {
        for(int i=0; i<3; i++)
        {
            if(produto[i][0] != '*')
                printf("\n-- Produto nº %d\nDescrição:%s\nQuantidade:%d\n", i+1, produto[i], quantidade[i]);
        }
    }
}

// CASE 03
void buscar_produto()
{
    int stringsIguais(char palavra[], char produto[]);

    printf("Digite alguma palavra: ");
    scanf("%s", &palavra);

    if(stringsIguais(palavra,produto[0]))
    {
        printf("Produto 01\n");
    }
    else if(stringsIguais(palavra,produto[1]))
    {
        printf("Produto 02\n");
    }
    else if(stringsIguais(palavra,produto[2]))
    {
        printf("Produto 03\n");
    }
    else
    {
        printf("Produto não encontrado!\n");
    }
}

// CASE 04
void buscar_letra()
{
    char letra;

    printf("Digite uma letra: ");
    getchar();
    scanf("%c", &letra);

    for(int i=0; i<3; i++)
    {
        if (letra == produto[i][0])
        {
            printf("Produto encontrado!\nProduto nº%i: %s\n", i+1, produto[i]);
            return;
        }
    }
    printf("Produto não encontrado!");
}

// CASE 05
void alterar_registro()
{
    int stringsIguais(char palavra[], char produto[]);

    char palavra[20];

    printf("Digite alguma palavra: ");
    scanf("%s", &palavra);

    if(stringsIguais(palavra,produto[0]))
    {
        printf("Digite o produto: ");
        scanf("%s", &produto[0]);
        printf("\nDigite a quantidade: ");
        scanf("%d", &quantidade[0]);
        printf("\nRegistro armazenado com sucesso!\n\n");

    }
    else if(stringsIguais(palavra,produto[1]))
    {
        printf("Digite o produto: ");
        scanf("%s", &produto[1]);
        printf("\nDigite a quantidade: ");
        scanf("%d", &quantidade[1]);
        printf("\nRegistro armazenado com sucesso!\n\n");
    }
    else if(stringsIguais(palavra,produto[2]))
    {
        printf("Digite o produto: ");
        scanf("%s", &produto[2]);
        printf("\nDigite a quantidade: ");
        scanf("%d", &quantidade[2]);
        printf("\nRegistro armazenado com sucesso!\n\n");
    }
    else
    {
        printf("Produto não encontrado!\n");
    }
    gravar_arquivo();
}

// CASE 06
void excluir_registro()
{
    int stringsIguais(char palavra[], char produto[]);

    printf("Digite alguma palavra: ");
    scanf("%s", &palavra);

    if(stringsIguais(palavra,produto[0]))
    {
       produto[0][0] = '*';

    }
    else if(stringsIguais(palavra,produto[1]))
    {
       produto[1][0] = '*';

    }
    else if(stringsIguais(palavra,produto[2]))
    {
       produto[2][0] = '*';

    }
    else
    {
        printf("Produto não encontrado!\n");
    }
    gravar_arquivo();
}

int stringsIguais(char palavra[], char produto[])
{
    int contador = 0;
    int igual = 0;
    while (palavra[contador] != '\0' || produto[contador] != '\0')
    {
        if (palavra[contador] == produto[contador])
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
