#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *discos;
    int tamanho;
} Torre;

Torre *criarTorre(int capacidade) {
    Torre *novaTorre = (Torre *)malloc(sizeof(Torre));
    novaTorre->discos = (int *)malloc(capacidade * sizeof(int));
    novaTorre->tamanho = 0;
    return novaTorre;
}

void liberarTorre(Torre *torre) {
    free(torre->discos);
    free(torre);
}

void mostrarTorre(Torre *torre) {
    for (int i = torre->tamanho - 1; i >= 0; i--) {
        printf("%d: ", i + 1);
        for (int j = 0; j < torre->discos[i]; j++) {
            printf("X");
        }
        printf("\n");
    }
    printf("\n");
}

void moverDisco(Torre *origem, Torre *destino) {
    if (origem->tamanho > 0 && (destino->tamanho == 0 || origem->discos[origem->tamanho - 1] < destino->discos[destino->tamanho - 1])) {
        destino->discos[destino->tamanho] = origem->discos[origem->tamanho - 1];
        destino->tamanho++;
        origem->tamanho--;
    }
}

int main() {
    int n;
    printf("Digite o número de discos: ");
    scanf("%d", &n);

    Torre *torreA = criarTorre(n);
    Torre *torreB = criarTorre(n);
    Torre *torreC = criarTorre(n);

    for (int i = n - 1; i >= 0; i--) {
        torreA->discos[torreA->tamanho++] = i + 1;
    }

    int movimentos = 0;

    while (1) {
        printf("Estado atual:\n");
        mostrarTorre(torreA);
        mostrarTorre(torreB);
        mostrarTorre(torreC);

        int origem, destino;
        printf("Digite a torre de origem e a torre de destino (ou 0 para sair): ");
        scanf("%d %d", &origem, &destino);

        if (origem == 0 || destino == 0) {
            printf("Saindo...\n");
            break;
        }

        moverDisco((origem == 1 ? torreA : (origem == 2 ? torreB : torreC)),
                   (destino == 1 ? torreA : (destino == 2 ? torreB : torreC)));

        movimentos++;

        // Verificar se o jogador ganhou
        if (torreC->tamanho == n) {
            printf("Parabéns! Você ganhou em %d movimentos.\n", movimentos);
            break;
        }
    }

    liberarTorre(torreA);
    liberarTorre(torreB);
    liberarTorre(torreC);

    return 0;
}