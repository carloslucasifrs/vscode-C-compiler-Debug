
typedef struct dados
{
    int codigo;
    char identCodigo[2];
    char nome[20];
    char cpf[20];
    int operacao;
    float valor;
} Dados;

typedef struct ultimoChamado
{
    int codigoCorrentista;
    int codigoNCorrentista;
    int codigoPrioritaria;
} UltimoChamado;

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
Dados entradaDadosCliente(Fila *f, char *identCodigo);
void menuCliente(Fila *correntista, Fila *ncorrentista, Fila *prioritaria);
EFila *chamaCliente(Fila *correntista, Fila *ncorrentista, Fila *prioritaria, UltimoChamado *uc);
float operacaoCaixa(EFila *ef, float saldo);