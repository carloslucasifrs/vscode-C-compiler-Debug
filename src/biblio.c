#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Fila *criaFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    f->qtd = 0;
    return f;
}

EFila *criaElemento(Dados dl)
{
    EFila *ef = (EFila *)malloc(sizeof(EFila));
    ef->proximo = NULL;
    ef->dados = dl;
    return ef;
}

void insereFila(Fila *f, EFila *ef)
{
    ef->proximo = NULL;
    if (f->inicio == NULL)
    {
        f->inicio = ef;
    }
    else
    {
        f->fim->proximo = ef;
    }
    f->fim = ef;
    f->qtd++;
}

EFila *removeFila(Fila *f)
{
    EFila *aux = f->inicio;
    if (aux == NULL)
    {
        printf("\nFILA VAZIA\n");
    }
    else
    {
        if (aux->proximo == NULL)
        {
            f->fim = NULL;
            f->inicio = NULL;
        }
        else
        {
            f->inicio = aux->proximo;
        }
        f->qtd--;
        aux->proximo = NULL;
    }

    return aux;
}

void mostraDadosElementoFila(Dados dl, int c)
{
    printf("\nDados do Cliente %d \n", c);
    printf("\n\t Codigo: %s%d Nome: %s e CPF: %s, Operação %d e Valor %2.2f \n", dl.identCodigo, dl.codigo, dl.nome, dl.cpf, dl.operacao, dl.valor);
}

int codigo(Dados dl)
{
    int codigo = dl.codigo + 1;

    return codigo;
}

void mostraFila(Fila *f)
{
    EFila *aux = f->inicio;
    int ct = 1;
    if (aux == NULL)
    {
        printf("\nFila Vazia\n");
    }
    else
    {
        printf("\nMostra Fila de Clientes\n");
        while (aux != NULL)
        {
            mostraDadosElementoFila(aux->dados, ct++);
            aux = aux->proximo;
        }
    }
}
int quantidadeElementos(Fila *f)
{
    return f->qtd;
}

void menu(Fila *f)
{
    int op = 1;
    EFila *removido;
    Dados dl;
    do
    {
        printf("\noperações de Fila");
        printf("\n\t 1 - Insere na Fila");
        printf("\n\t 2 - Remove da Fila");
        printf("\n\t 3 - mostra Fila");
        printf("\n\t 4 - mostra primeiro elemento Fila");
        printf("\n\t 5 - mostra ultimo  elemento Fila");
        printf("\n\t 6 - mostra quantifade de elemento Fila");
        printf("\n\t 0 - para sair");
        printf("\nInforme a opção: ");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            printf("\nInforme seu nome ");
            scanf("%s", dl.nome);
            printf("\nInforme seu cpf ");
            scanf("%s", dl.cpf);
            printf("\nInforme seu operacao ");
            scanf("%d", &dl.operacao);
            printf("\nInforme seu valor ");
            scanf("%f", &dl.valor);
            insereFila(f, criaElemento(dl));
            printf("\nElemento Inserido\n ");
            break;
        case 2:
            removido = removeFila(f);
            if (removido != NULL)
            {
                mostraDadosElementoFila(removido->dados, 0);
            }
            break;
        case 3:
            mostraFila(f);
            break;
        case 4:
            mostraDadosElementoFila(f->inicio->dados, 1);
            break;
        case 5:
            mostraDadosElementoFila(f->fim->dados, f->qtd);
            break;
        case 6:
            printf("\nTotal de elementos na fila: %d ", quantidadeElementos(f));
            break;

        default:
            printf("\nFim do programa\n");
        }
    } while (op != 0);
}

Dados entradaDadosCliente(Fila *f, char *identCodigo)
{
    Dados dl;
    printf("\nInforme seu nome ");
    scanf("%s", dl.nome);
    printf("\nInforme seu cpf ");
    scanf("%s", dl.cpf);
    printf("\nInforme seu operacao ");
    scanf("%d", &dl.operacao);
    printf("\nInforme seu valor ");
    scanf("%f", &dl.valor);
    strcpy(dl.identCodigo, identCodigo);
    if (f->fim == NULL)
    {
        dl.codigo = 1;
    }
    else
    {
        dl.codigo = codigo(f->fim->dados);
    }
    printf("\nFicha para atentidmento do cliente numero %s%d\n", dl.identCodigo, dl.codigo);
    return dl;
}

void menuCliente(Fila *correntista, Fila *ncorrentista, Fila *prioritaria)
{
    Dados dl;
    int op = 1;
    do
    {

        printf("\nTipo de Cliente");
        printf("\n\t 1 - Correntista");
        printf("\n\t 2 - Não Correntista");
        printf("\n\t 3 - Prioritario");
        printf("\n\t 0 - Voltar");
        printf("\nInforme a opção: ");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            dl = entradaDadosCliente(correntista, "C");
            insereFila(correntista, criaElemento(dl));
            break;
        case 2:
            dl = entradaDadosCliente(ncorrentista, "NC");
            insereFila(ncorrentista, criaElemento(dl));
            break;
        case 3:
            dl = entradaDadosCliente(prioritaria, "P");
            insereFila(prioritaria, criaElemento(dl));
            break;
        }
    } while (op != 0);
}

EFila *chamaCliente(Fila *correntista, Fila *ncorrentista, Fila *prioritaria, UltimoChamado *uc)
{
    EFila *ef;
    if (prioritaria->qtd > 0)
    {
        ef = removeFila(prioritaria);
        uc->codigoPrioritaria = ef->dados.codigo;
        return ef;
    }
    else if (correntista->qtd > 0)
    {
        ef = removeFila(correntista);
        uc->codigoCorrentista = ef->dados.codigo;
        return ef;
    }
    else if (ncorrentista->qtd > 0)
    {
        ef = removeFila(ncorrentista);
        uc->codigoNCorrentista = ef->dados.codigo;
        return ef;
    }
    else
    {
        printf("\nFila Vazia \n");
    }
    return NULL;
}

float operacaoCaixa(EFila *el, float saldo)
{
    int op = 0;
    float valor;
    do
    {
        printf("\nTipo de Operação");
        printf("\n\t 1 - Deposito");
        printf("\n\t 2 - Saque");
        printf("\n\t 3 - Saldo");
        printf("\n\t 0 - Voltar");
        printf("\nInforme a opção: ");
        scanf(" %d", &op);
        switch (op)
        {
        case 1:
            printf("\nDeposito\n");
            printf("Informe o Valor\n");
            scanf(" %f", &valor);
            saldo += valor;
            break;
        case 2:
            printf("\nSaque\n");
            printf("Informe o Valor\n");
            scanf(" %f", &valor);
            saldo -= valor;
            break;
        case 3:
            printf("\nSaldo %2.2f\n", saldo);
            break;
        }
    } while (op != 0);

    return saldo;
}