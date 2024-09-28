#include <stdio.h>

int main() {
    float temperaturas[10];
    float menor_temp, maior_temp, media_temp = 0.0;
    int dias_inferiores_media = 0;

    // Coleta das temperaturas
    printf("========== TEMPERATURAS DIÁRIAS =========\n");
    for (int i = 0; i < 10; i++) {
        printf("Entre com a %da temperatura: ", i + 1);
        scanf("%f", &temperaturas[i]);
    }

    // Inicializa menor e maior temperatura
    menor_temp = temperaturas[0];
    maior_temp = temperaturas[0];

    // Cálculo da menor, maior e média
    for (int i = 0; i < 10; i++) {
        if (temperaturas[i] < menor_temp) {
            menor_temp = temperaturas[i];
        }
        if (temperaturas[i] > maior_temp) {
            maior_temp = temperaturas[i];
        }
        media_temp += temperaturas[i];
    }
    media_temp /= 10;

    // Contagem dos dias abaixo da média
    for (int i = 0; i < 10; i++) {
        if (temperaturas[i] < media_temp) {
            dias_inferiores_media++;
        }
    }

    // Impressão dos resultados
    printf("============= Resultado =================\n");
    printf("Menor temp. –: %.2f\n", menor_temp);
    printf("Maior temp. –: %.2f\n", maior_temp);
    printf("Temperatura média –: %.2f\n", media_temp);
    printf("Dias temp. inf. média -: %d\n", dias_inferiores_media);

    return 0;
}
