typedef struct dados
{
    char nome[20];
    char cpf[20];
    int operacao;
    float valor;

} Dados;

typedef struct efila
{
    struct efila *proximo;
    Dados dados;
} EFila;

typedef struct fila
{
    EFila *inicio;
    EFila *fim;
    int qtd;
} Fila;

Fila *criaFila();
EFila *criaElemento(Dados dl);
void insereFila(Fila *f, EFila *ef);
EFila *removeFila(Fila *f);
void mostraDadosElementoFila(Dados dl, int c);
int quantidadeElementos(Fila *f);
void mostraFila(Fila *f);
void menu(Fila *f);
