
#define MAX_PALPITES 100
#define MAX_ANIMAIS 20
#define MAX_NOME 30

typedef struct {
    char nome[MAX_NOME];
    int tamanho;
} Animal;

typedef struct {
    char nome[MAX_NOME];
    Animal animais[MAX_ANIMAIS];
    int count;
} Categoria;

void inicializarCategorias(Categoria categorias[]) {
    // Categorias e animais
    strcpy(categorias[0].nome, "Mamíferos");
    categorias[0].count = 3;
    strcpy(categorias[0].animais[0].nome, "elefante");
    strcpy(categorias[0].animais[1].nome, "tigre");
    strcpy(categorias[0].animais[2].nome, "urso");

    strcpy(categorias[1].nome, "Aves");
    categorias[1].count = 3;
    strcpy(categorias[1].animais[0].nome, "papagaio");
    strcpy(categorias[1].animais[1].nome, "águia");
    strcpy(categorias[1].animais[2].nome, "pinguim");

    strcpy(categorias[2].nome, "Répteis");
    categorias[2].count = 3;
    strcpy(categorias[2].animais[0].nome, "cobras");
    strcpy(categorias[2].animais[1].nome, "lagarto");
    strcpy(categorias[2].animais[2].nome, "tartaruga");

    strcpy(categorias[3].nome, "Peixes");
    categorias[3].count = 3;
    strcpy(categorias[3].animais[0].nome, "tubarão");
    strcpy(categorias[3].animais[1].nome, "salmão");
    strcpy(categorias[3].animais[2].nome, "truta");

    strcpy(categorias[4].nome, "Anfíbios");
    categorias[4].count = 3;
    strcpy(categorias[4].animais[0].nome, "sapo");
    strcpy(categorias[4].animais[1].nome, "salamandra");
    strcpy(categorias[4].animais[2].nome, "perereca");
}

int main() {
    Categoria categorias[5];
    inicializarCategorias(categorias);
    
    int escolha;
    char palpites[MAX_PALPITES][MAX_NOME];
    int cont_palpite = 0;

    printf("===== JOGO DE ADIVINHAÇÃO DE PALAVRAS =====\n");
    printf("Escolha uma categoria de animais:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("%d – %s\n", i + 1, categorias[i].nome);
    }

    printf("Digite o número da categoria desejada: ");
    scanf("%d", &escolha);

    while (escolha < 1 || escolha > 5) {
        printf("Escolha inválida! Tente novamente: ");
        scanf("%d", &escolha);
    }

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));
    int indice = rand() % categorias[escolha - 1].count;
    char* palavra_secreta = categorias[escolha - 1].animais[indice].nome;
    int tamanho_palavra = strlen(palavra_secreta);
    
    printf("------- Vamos Iniciar o Jogo! --------------\n");
    printf("Dica: A palavra tem %d letras.\n", tamanho_palavra);

    char palpite[MAX_NOME];

    while (1) {
        printf("Tente adivinhar a palavra: ");
        getchar(); // Limpa o buffer
        fgets(palpite, MAX_NOME, stdin);
        palpite[strcspn(palpite, "\n")] = '\0'; // Remove nova linha

        // Armazena o palpite
        strcpy(palpites[cont_palpite], palpite);
        cont_palpite++;

        if (strcasecmp(palpite, palavra_secreta) == 0) {
            printf("Parabéns! Você acertou a palavra.\n");
            break;
        } else {
            printf("Palpite incorreto.\n");
        }
    }

    printf("--------------------------------------------\n");
    printf("Número de palpites: %d\n", cont_palpite);
    printf("Palpites realizados: [");
    for (int i = 0; i < cont_palpite; i++) {
        printf("'%s'%s", palpites[i], (i < cont_palpite - 1) ? ", " : "");
    }
    printf("]\n");

    return 0;
}
