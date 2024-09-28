#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAREFAS 100
#define MAX_DESCRICAO 100

typedef struct {
    char descricao[MAX_DESCRICAO];
    char prioridade[10]; // alta, média, baixa
} Tarefa;

Tarefa lista_tarefas[MAX_TAREFAS];
int count_tarefas = 0;

void adicionar_tarefa() {
    if (count_tarefas >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido!\n");
        return;
    }

    Tarefa nova_tarefa;
    printf("Digite a descrição da tarefa: ");
    getchar(); // Limpa o buffer
    fgets(nova_tarefa.descricao, MAX_DESCRICAO, stdin);
    nova_tarefa.descricao[strcspn(nova_tarefa.descricao, "\n")] = '\0'; // Remove nova linha

    printf("Digite a prioridade da tarefa (alta/média/baixa): ");
    scanf("%s", nova_tarefa.prioridade);

    // Validação da prioridade
    while (strcmp(nova_tarefa.prioridade, "alta") != 0 &&
           strcmp(nova_tarefa.prioridade, "média") != 0 &&
           strcmp(nova_tarefa.prioridade, "baixa") != 0) {
        printf("Prioridade inválida! Digite novamente (alta/média/baixa): ");
        scanf("%s", nova_tarefa.prioridade);
    }

    lista_tarefas[count_tarefas++] = nova_tarefa;
    printf("Tarefa adicionada com sucesso!\n");
}

void exibir_tarefas() {
    if (count_tarefas == 0) {
        printf("Nenhuma tarefa cadastrada.\n");
        return;
    }

    printf("Tarefas:\n");
    for (int i = 0; i < count_tarefas; i++) {
        printf("[%d] %s - Prioridade: %s\n", i + 1, lista_tarefas[i].descricao, lista_tarefas[i].prioridade);
    }
}

void concluir_tarefa() {
    int numero;
    printf("Digite o número da tarefa que deseja concluir: ");
    scanf("%d", &numero);

    if (numero < 1 || numero > count_tarefas) {
        printf("Número de tarefa inválido!\n");
        return;
    }

    // Remover tarefa
    for (int i = numero - 1; i < count_tarefas - 1; i++) {
        lista_tarefas[i] = lista_tarefas[i + 1];
    }
    count_tarefas--;
    printf("Tarefa concluída e removida da lista!\n");
}

int main() {
    int opcao;

    while (1) {
        printf("================ GERENCIADOR DE TAREFAS =====================\n");
        printf("Escolha uma opção:\n");
        printf("1 - Adicionar tarefa\n");
        printf("2 - Exibir tarefas\n");
        printf("3 - Concluir tarefa\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_tarefa();
                break;
            case 2:
                exibir_tarefas();
                break;
            case 3:
                concluir_tarefa();
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
