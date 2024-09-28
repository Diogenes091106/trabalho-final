#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100
#define MAX_NOME 100
#define MAX_CARGO 100

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char cargo[MAX_CARGO];
} Funcionario;

Funcionario funcionarios[MAX_FUNCIONARIOS];
int count = 0;

void carregar_funcionarios() {
    FILE *file = fopen("funcionarios.txt", "r");
    if (file == NULL) {
        printf("Nenhum arquivo encontrado. Iniciando com uma lista vazia.\n");
        return;
    }

    while (fscanf(file, "%99[^,],%d,%99[^\n]\n", funcionarios[count].nome, &funcionarios[count].idade, funcionarios[count].cargo) == 3) {
        count++;
    }

    fclose(file);
}

void salvar_funcionarios() {
    FILE *file = fopen("funcionarios.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s,%d,%s\n", funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].cargo);
    }

    fclose(file);
}

void adicionar_funcionario() {
    if (count >= MAX_FUNCIONARIOS) {
        printf("Limite de funcionários atingido!\n");
        return;
    }

    Funcionario novo_funcionario;

    printf("Digite o nome do funcionário: ");
    getchar(); // Limpa o buffer
    fgets(novo_funcionario.nome, MAX_NOME, stdin);
    novo_funcionario.nome[strcspn(novo_funcionario.nome, "\n")] = '\0'; // Remove nova linha

    printf("Digite a idade do funcionário: ");
    scanf("%d", &novo_funcionario.idade);

    printf("Digite o cargo do funcionário: ");
    getchar(); // Limpa o buffer
    fgets(novo_funcionario.cargo, MAX_CARGO, stdin);
    novo_funcionario.cargo[strcspn(novo_funcionario.cargo, "\n")] = '\0'; // Remove nova linha

    funcionarios[count++] = novo_funcionario;
    salvar_funcionarios(); // Salva no arquivo
    printf("Funcionário adicionado com sucesso!\n");
}

void listar_funcionarios() {
    if (count == 0) {
        printf("Nenhum funcionário cadastrado.\n");
        return;
    }
    
    printf("================ FUNCIONÁRIOS =====================\n");
    printf("Nome, Idade, Cargo\n");
    printf("---------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s, %d, %s\n", i + 1, funcionarios[i].nome, funcionarios[i].idade, funcionarios[i].cargo);
    }
}

void buscar_por_cargo() {
    char cargo_busca[MAX_CARGO];
    printf("Digite o cargo que deseja buscar: ");
    getchar(); // Limpa o buffer
    fgets(cargo_busca, MAX_CARGO, stdin);
    cargo_busca[strcspn(cargo_busca, "\n")] = '\0'; // Remove nova linha

    int found = 0;
    printf("Funcionários com o cargo '%s':\n", cargo_busca);
    for (int i = 0; i < count; i++) {
        if (strcmp(funcionarios[i].cargo, cargo_busca) == 0) {
            printf("Nome: %s, Idade: %d\n", funcionarios[i].nome, funcionarios[i].idade);
            found = 1;
        }
    }
    if (!found) {
        printf("Nenhum funcionário encontrado com o cargo '%s'.\n", cargo_busca);
    }
}

int main() {
    carregar_funcionarios(); // Carrega os funcionários ao iniciar

    int opcao;
    while (1) {
        printf("================ MENU =====================\n");
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar funcionário\n");
        printf("2 - Listar funcionários\n");
        printf("3 - Buscar funcionários por cargo\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_funcionario();
                break;
            case 2:
                listar_funcionarios();
                break;
            case 3:
                buscar_por_cargo();
                break;
            case 4:
                printf("Saindo do programa...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
