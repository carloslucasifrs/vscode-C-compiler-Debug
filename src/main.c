#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>

// f.Cada cliente será representado por uma estrutura de dados “Cliente”, onde deve ser armazenado, o número de atendimento recebido, o nome do cliente, CPF, a operação a ser realizada e o valor da operação.
// obs.: OPERAÇÃO E VALOR não foram armazenados não pois a função de caixa nao teria como utilizar o ver saldo, então criei uma opção de selecionar deposito, saque ou ver saldo, nao sei se ficou correto mas ficou viavel.

int main()
{
  Fila *correntista = criaFila();
  Fila *ncorrentista = criaFila();
  Fila *prioritaria = criaFila();

  float caixa = 1000;

  menuCliente(correntista, ncorrentista, prioritaria);

  EFila *ef;
  UltimoChamado *uc;
  uc->codigoCorrentista = 0;
  uc->codigoNCorrentista = 0;
  uc->codigoPrioritaria = 0;

  while (correntista->qtd > 0 || ncorrentista->qtd > 0 || prioritaria->qtd > 0)
  {
    ef = chamaCliente(correntista, ncorrentista, prioritaria, uc);

    printf("\nultimos chamados ");

    if (uc->codigoPrioritaria == 0)
    {
      printf("Prioritario --- ");
    }
    else
    {
      printf("Prioritario P%d ", uc->codigoPrioritaria);
    }

    if (uc->codigoCorrentista == 0)
    {
      printf("Correntista --- ");
    }
    else
    {
      printf("Correntista C%d ", uc->codigoCorrentista);
    }

    if (uc->codigoNCorrentista == 0)
    {
      printf("Não Correntista --- ");
    }
    else
    {
      printf("Não Correntista NC%d ", uc->codigoNCorrentista);
    }

    printf("\nCodigo %s%d em atendimento", ef->dados.identCodigo, ef->dados.codigo);
    caixa = operacaoCaixa(ef, caixa);
    printf("\n Saldo em caixa %2.2f \n", caixa);
  }

  // menu(correntista);
  // menu(ncorrentista);
  // menu(prioritaria);

  return 1;
}