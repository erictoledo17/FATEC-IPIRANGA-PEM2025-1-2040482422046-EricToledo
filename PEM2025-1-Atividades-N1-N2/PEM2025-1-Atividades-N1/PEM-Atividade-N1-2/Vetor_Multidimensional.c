/*-----------------------------------------------------------------*
*                      FATEC Ipiranga                              *
* Disciplina: Programaçao Estruturada e Modular                    *
*          Prof. Veríssimo                                         *
*------------------------------------------------------------------*
* Objetivo do Programa: matriz multidimensional com 3 dimensões    *
* Data - 03/03/2025                                                * 
* Autor:Eric Inácio de Toledo                                      *
*------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_RUAS 3
#define NUM_POSICOES 10
#define MAX_COD 20

typedef struct {
    char codigo[MAX_COD];
} Produto;

Produto estoque[NUM_RUAS][NUM_POSICOES];

void inicializarEstoque() {
    for (int r = 0; r < NUM_RUAS; r++) {
        for (int p = 0; p < NUM_POSICOES; p++) {
            estoque[r][p].codigo[0] = '\0';  // Inicializa como uma string vazia
        }
    }
}

int ruaParaIndice(char rua) {
    switch (toupper(rua)) {
        case 'A': return 0;
        case 'B': return 1;
        case 'C': return 2;
        default:  return -1;
    }
}

char indiceParaRua(int i) {
    return (i >= 0 && i < NUM_RUAS) ? ('A' + i) : '?';
}

int buscarProduto(char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD], const char *codigo, int *ruaEncontrada, int *posEncontrada) {
    for (int r = 0; r < NUM_RUAS; r++) {
        for (int p = 0; p < NUM_POSICOES; p++) {
            if (strcmp(estoque[r][p], codigo) == 0) {
                *ruaEncontrada = r;
                *posEncontrada = p;
                return 1;
            }
        }
    }
    return 0;
}

void salvarEstoque(char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD]) {
    FILE *file = fopen(ARQUIVO_ESTOQUE, "w");
    if (file) {
        for (int r = 0; r < NUM_RUAS; r++) {
            for (int p = 0; p < NUM_POSICOES; p++) {
                if (estoque[r][p][0] != '\0') {
                    fprintf(file, "%c %d %s\n", indiceParaRua(r), p + 1, estoque[r][p]);
                }
            }
        }
        fclose(file);
    }
}

void carregarEstoque(char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD]) {
    FILE *file = fopen(ARQUIVO_ESTOQUE, "r");
    if (file) {
        char rua;
        int pos;
        char codigo[MAX_COD];
        while (fscanf(file, " %c %d %s", &rua, &pos, codigo) == 3) {
            int r = ruaParaIndice(rua);
            if (r != -1 && pos >= 1 && pos <= NUM_POSICOES) {
                strcpy(estoque[r][pos - 1], codigo);
            }
        }
        fclose(file);
    }
}

void mostrarEstoque(char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD]) {
    printf("\n--- ESTOQUE ATUAL ---\n");
    for (int r = 0; r < NUM_RUAS; r++) {
        printf("Rua %c: ", indiceParaRua(r));
        for (int p = 0; p < NUM_POSICOES; p++) {
            if (estoque[r][p][0] != '\0') {
                printf("[%d: %s] ", p + 1, estoque[r][p]);
            } else {
                printf("[%d: Vazio] ", p + 1);
            }
        }
        printf("\n");
    }
}

int main() {
    char estoque[NUM_RUAS][NUM_POSICOES][MAX_COD] = {""};
    carregarEstoque(estoque);

    int opcao;
    do {
        printf("         GESTAO DE ESTOQUE (3D)         \n");
        printf("1 - Estocar Produto\n");
        printf("2 - Retirar Produto\n");
        printf("3 - Mostrar Estoque\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            char codigo[MAX_COD];
            printf("\nDigite o codigo do produto: ");
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = '\0';

            int ruaE, posE;
            if (buscarProduto(estoque, codigo, &ruaE, &posE)) {
                printf("O produto %s ja esta armazenado na Rua %c, Posicao %d.\n", codigo, indiceParaRua(ruaE), posE + 1);
            } else {
                char ruaChar;
                int posicao;
                printf("Digite a Rua (A, B ou C): ");
                scanf(" %c", &ruaChar);
                printf("Digite a Posicao (1..10): ");
                scanf("%d", &posicao);

                int r = ruaParaIndice(ruaChar);
                int p = posicao - 1;
                if (r >= 0 && r < NUM_RUAS && p >= 0 && p < NUM_POSICOES && estoque[r][p][0] == '\0') {
                    strcpy(estoque[r][p], codigo);
                    printf("Produto %s estocado em Rua %c, Posicao %d.\n", codigo, toupper(ruaChar), posicao);
                    salvarEstoque(estoque);
                } else {
                    printf("Posicao invalida ou ja ocupada.\n");
                }
            }
        } else if (opcao == 2) {
            char codigo[MAX_COD];
            printf("\nDigite o codigo do produto a retirar: ");
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = '\0';

            int ruaE, posE;
            if (buscarProduto(estoque, codigo, &ruaE, &posE)) {
                estoque[ruaE][posE][0] = '\0';
                printf("Produto %s retirado do estoque (Rua %c, Posicao %d).\n", codigo, indiceParaRua(ruaE), posE + 1);
                salvarEstoque(estoque);
            } else {
                printf("Produto nao encontrado no estoque.\n");
            }
        } else if (opcao == 3) {
            mostrarEstoque(estoque);
        } else if (opcao == 4) {
            printf("\nSaindo do programa...\n");
        } else {
            printf("\nOpcao invalida!\n");
        }
    } while (opcao != 4);

    return 0;
}
