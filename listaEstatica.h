
#define MAX_CONTATOS 100


// Estrutura para armazenar informações de um contato
typedef struct {
    char nome[100];
    char telefone[15];
    char email[50];
} Contato;

// Funções da agenda

void adicionarContato(Contato agenda[], int *contador);
void listarContatos(Contato agenda[], int contador);
void buscarContato(Contato agenda[], int contador, const char *nome);
void removerContato(Contato agenda[], int *contador, const char *nome);
void Menuagenda();


