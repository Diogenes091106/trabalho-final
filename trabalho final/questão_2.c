#include <stdio.h>

#define MAX_ASSENTOS 5

// Estrutura para representar os assentos
typedef struct {
    int numero;
    int reservado; // 0 - disponível, 1 - reservado
} Assento;

void mostrarAssentos(Assento assentos[]) {
    printf("Assentos disponíveis: [");
    for (int i = 0; i < MAX_ASSENTOS; i++) {
        if (assentos[i].reservado == 0) {
            printf("%d", assentos[i].numero);
            if (i < MAX_ASSENTOS - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
}

int reservarAssento(Assento assentos[], int numero) {
    for (int i = 0; i < MAX_ASSENTOS; i++) {
        if (assentos[i].numero == numero) {
            if (assentos[i].reservado == 0) {
                assentos[i].reservado = 1;
                return 1; // Reserva realizada
            } else {
                return 0; // Assento já reservado
            }
        }
    }
    return -1; // Assento inválido
}

int main() {
    Assento assentos[MAX_ASSENTOS] = {
        {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}
    };
    int numero;

    printf("======= SISTEMA DE RESERVA =======\n");

    while (1) {
        mostrarAssentos(assentos);
        printf("Deseja reservar qual assento? ");
        scanf("%d", &numero);

        int resultado = reservarAssento(assentos, numero);
        
        if (resultado == 1) {
            printf("-------------------------------------\n");
            printf("Assento %d reservado com sucesso!\n", numero);
        } else if (resultado == 0) {
            printf("-------------------------------------\n");
            printf("Desculpe, o assento %d já está reservado.\n", numero);
        } else {
            printf("-------------------------------------\n");
            printf("Assento inválido!\n");
        }
    }

    return 0;
}
