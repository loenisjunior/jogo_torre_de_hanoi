#include "torre.h"
#include <stdio.h>
#include <stdlib.h>

// Função para mostrar o estado atual da torre
void mostrarTorre(int torre[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; j < torre[i]; j++) {
            printf("X");
        }
        printf("\n");
    }
    printf("\n");
}

// Função para mover um disco de uma torre para outra
void moverDisco(int origem, int destino, int torre[], int n) {
    if (torre[origem] > 0 && (torre[destino] == 0 || torre[origem] < torre[destino])) {
        torre[destino] = torre[origem];
        torre[origem] = 0;
    }
}

// Função para salvar o estado atual da torre em um arquivo
void salvarJogo(int torre[], int n, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(arquivo, "%d\n", torre[i]);
    }
    
    fclose(arquivo);
    printf("Jogo salvo com sucesso!\n");
}

// Função para carregar o estado da torre a partir de um arquivo
void carregarJogo(int torre[], int n, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar.\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fscanf(arquivo, "%d", &torre[i]);
    }
    
    fclose(arquivo);
    printf("Jogo carregado com sucesso!\n");
}
