#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  Fila *caixa = criaFila();
  menu(caixa);

  return 1;
}