#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int conteudo;
    struct no *esquerda, *direita;
} No;

typedef struct
{
    No *raiz;
} ArvB;

void inserirDireita(No *no, int valor); // Função precisa ser declarada antes de ser usada

void inserirEsquerda(No *no, int valor)
{
    if (no->esquerda == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->esquerda = novo;
    }
    else
    {
        if (valor < no->esquerda->conteudo)
            inserirEsquerda(no->esquerda, valor);
        if (valor > no->esquerda->conteudo)
            inserirDireita(no->esquerda, valor);
    }
}

void inserirDireita(No *no, int valor)
{
    if (no->direita == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
    }
    else
    {
        if (valor > no->direita->conteudo)
            inserirDireita(no->direita, valor);
        if (valor < no->direita->conteudo)
            inserirEsquerda(no->direita, valor);
    }
}

void inserir(ArvB *arv, int valor)
{
    if (arv->raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        arv->raiz = novo;
    }
    else
    {
        if (valor < arv->raiz->conteudo)
            inserirEsquerda(arv->raiz, valor);
        if (valor > arv->raiz->conteudo)
            inserirDireita(arv->raiz, valor);
    }
}

void imprimir(No *raiz)
{
    if (raiz != NULL)
    {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        imprimir(raiz->direita);
    }
}

int main()
{
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            printf("\nSaindo...\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            printf("\nImpressao da arvore binaria:\n");
            imprimir(arv.raiz);
            break;

        default:
            printf("\nOpcao inavalida...\n");
            break;
        }
    } while (op != 0);
}