/*-----------------------------------------------------------------------------------------------------------*
*                      FATEC Ipiranga                                                                        *
* Disciplina: Programaçao Estruturada e Modular                                                              *
*          Prof. Veríssimo                                                                                   *
*------------------------------------------------------------------------------------------------------------*
* Objetivo do Programa: Refatorar a atividade N1-2 utilizando modularização, ponteiros e diagram em blocos   *
* Data - 15/03/2025                                                                                          * 
* Autor:Eric Inácio de Toledo                                                                                *
*------------------------------------------------------------------------------------------------------------/
/*
/*
+-----------------------------------+
|       Diagrama de Blocos          |
+-----------------------------------+
|       Início do Programa          |
+-----------------------------------+
                |
                v
+-----------------------------------+
| Chama inicializarEstoque()        |
+-----------------------------------+
                |
                v
+-----------------------------------+
| Exibe Menu de Opções              |
| 1 - Estocar Produto               |
| 2 - Retirar Produto               |
| 3 - Mostrar Estoque               |
| 4 - Sair                          |
+-----------------------------------+
                |
                v
+-----------------------------------+       +-----------------------------------+
| Verifica a opção escolhida        |----->| Chama estocarProduto()           |
+-----------------------------------+       +-----------------------------------+
                |                                       |
                v                                       v
+-----------------------------------+       +-----------------------------------+
| Chama retirarProduto()            |<------| Solicita código do produto       |
+-----------------------------------+       +-----------------------------------+
                |                                       |
                v                                       v
+-----------------------------------+       +-----------------------------------+
| Chama mostrarEstoque()            |<------| Exibe o estado do estoque        |
+-----------------------------------+       +-----------------------------------+
                |
                v
+-----------------------------------+
| Fim do programa                   |
+-----------------------------------+
*/

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
            estoque[r][p].codigo[0] = '\0'; 
        }
    }
}

int ruaParaIndice(char rua) {
    return toupper(rua) - 'A'; 
}

int buscarProduto(char *codigo, int *rua, int *posicao) {
    for (int r = 0; r < NUM_RUAS; r++) {
        for (int p = 0; p < NUM_POSICOES; p++) {
            if (strcmp(estoque[r][p].codigo, codigo) == 0) {
                *rua = r;  
                *posicao = p; 
                return 1; 
            }
        }
    }
    return 0; 
}


void estocarProduto() {
    char codigo[MAX_COD];  
    printf("\nDigite o código do produto: ");
    fgets(codigo, sizeof(codigo), stdin); 
    codigo[strcspn(codigo, "\n")] = '\0'; 
    int rua, posicao;
    if (buscarProduto(codigo, &rua, &posicao)) {
        printf("Produto %s já está armazenado na Rua %c, Posição %d.\n", codigo, 'A' + rua, posicao + 1);
        return;
    }

    char ruaChar;
    printf("Digite a Rua (A, B ou C): ");
    scanf(" %c", &ruaChar); 
    printf("Digite a Posição (1..10): ");
    scanf("%d", &posicao); 
    posicao -= 1; 

    rua = ruaParaIndice(ruaChar); 

    if (rua >= 0 && rua < NUM_RUAS && posicao >= 0 && posicao < NUM_POSICOES) {
        if (estoque[rua][posicao].codigo[0] == '\0') {
            strcpy(estoque[rua][posicao].codigo, codigo); 
            printf("Produto %s armazenado na Rua %c, Posição %d.\n", codigo, 'A' + rua, posicao + 1);
        } else {
            printf("Posição ocupada, tente outra posição.\n");
        }
    } else {
        printf("Posição ou Rua inválida.\n");
    }
}

void retirarProduto() {
    char codigo[MAX_COD];  
    printf("\nDigite o código do produto a retirar: ");
    fgets(codigo, sizeof(codigo), stdin); 
    codigo[strcspn(codigo, "\n")] = '\0'; 
    int rua, posicao;
    if (buscarProduto(codigo, &rua, &posicao)) {
        estoque[rua][posicao].codigo[0] = '\0';
        printf("Produto %s retirado da Rua %c, Posição %d.\n", codigo, 'A' + rua, posicao + 1);
    } else {
        printf("Produto %s não encontrado no estoque.\n", codigo);
    }
}

void mostrarEstoque() {
    printf("\n--- ESTOQUE ATUAL ---\n");
    for (int r = 0; r < NUM_RUAS; r++) {
        printf("Rua %c: ", 'A' + r); 
        for (int p = 0; p < NUM_POSICOES; p++) {
            printf("[%d: %s] ", p + 1, estoque[r][p].codigo[0] != '\0' ? estoque[r][p].codigo : "Vazio"); // Exibe o código ou "Vazio"
        }
        printf("\n");
    }
}

int main() {
    inicializarEstoque(); 

    int opcao;
    do {
        printf("\nGESTÃO DE ESTOQUE\n");
        printf("1 - Estocar Produto\n");
        printf("2 - Retirar Produto\n");
        printf("3 - Mostrar Estoque\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1: estocarProduto(); break;
            case 2: retirarProduto(); break;
            case 3: mostrarEstoque(); break;
            case 4: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}
