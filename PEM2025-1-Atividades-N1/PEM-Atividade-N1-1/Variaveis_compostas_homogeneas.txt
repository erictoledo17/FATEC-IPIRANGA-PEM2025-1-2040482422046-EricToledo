/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Variáveis Compostas Homogêneas               *
* Data - 28/02/2006                                      * 
* Autor: Eric Inácio de Toledo; RA:2040482422046             *
*--------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

int main() {
    int numCandidatos;
    printf("A tabela sera realizada com quantos candidatos??(Numero maximo de Candidatos eh 50!!)\n");
    while (1) {
        scanf("%d", &numCandidatos);
        if (numCandidatos > 0 && numCandidatos <= 50) {
            break;
        } else {
            printf("Digite um numero valido (entre 1 a 50)\n");
        }
    }

    float notasFinais[numCandidatos];
    char nomesCandidatos[numCandidatos][15];

    for (int i = 0; i < numCandidatos; i++) {
        int notasPE[4], notasAC[5], notasPP[10], notasEB[3];
        int somaPE = 0, somaAC = 0, somaPP = 0, somaEB = 0;
        int maiorPE = 0, menorPE = 0, maiorAC = 0, menorAC = 0;
        int maiorPP = 0, menorPP = 0, maiorEB = 0, menorEB = 0;

        char nome[15];
        printf("Digite o nome do candidato\n");
        scanf(" %14s", nome);
        strcpy(nomesCandidatos[i], nome);
        printf("Candidato %s Reconhecido\n", nome);

        printf("Digite a Primeira nota PE.\n");
        scanf("%d", &notasPE[0]);
        maiorPE = menorPE = notasPE[0];

        for (int j = 1; j < 4; j++) {
            printf("Digite a Proxima nota PE.\n");
            scanf("%d", &notasPE[j]);
            somaPE += notasPE[j];
            if (notasPE[j] > maiorPE) {
                maiorPE = notasPE[j];
            }
            if (notasPE[j] < menorPE) {
                menorPE = notasPE[j];
            }
        }

        printf("Digite a Primeira nota AC.\n");
        scanf("%d", &notasAC[0]);
        maiorAC = menorAC = notasAC[0];
        for (int j = 1; j < 5; j++) {
            printf("Digite a Proxima nota AC.\n");
            scanf("%d", &notasAC[j]);
            somaAC += notasAC[j];
            if (notasAC[j] > maiorAC) {
                maiorAC = notasAC[j];
            }
            if (notasAC[j] < menorAC) {
                menorAC = notasAC[j];
            }
        }

        printf("Digite a Primeira nota PP.\n");
        scanf("%d", &notasPP[0]);
        maiorPP = menorPP = notasPP[0];
        for (int j = 1; j < 10; j++) {
            printf("Digite a Proxima nota PP.\n");
            scanf("%d", &notasPP[j]);
            somaPP += notasPP[j];
            if (notasPP[j] > maiorPP) {
                maiorPP = notasPP[j];
            }
            if (notasPP[j] < menorPP) {
                menorPP = notasPP[j];
            }
        }

        printf("Digite a Primeira nota EB.\n");
        scanf("%d", &notasEB[0]);
        maiorEB = menorEB = notasEB[0];
        for (int j = 1; j < 3; j++) {
            printf("Digite a Proxima nota EB.\n");
            scanf("%d", &notasEB[j]);
            somaEB += notasEB[j];
            if (notasEB[j] > maiorEB) {
                maiorEB = notasEB[j];
            }
            if (notasEB[j] < menorEB) {
                menorEB = notasEB[j];
            }
        }

        notasFinais[i] = (((somaPE - maiorPE - menorPE) * 0.3) +
                           ((somaAC - maiorAC - menorAC) * 0.1) +
                           ((somaPP - maiorPP - menorPP) * 0.4) +
                           ((somaEB - maiorEB - menorEB) * 0.2));
        printf("A nota final do candidato foi: %.2f\n", notasFinais[i]);
    }

    for (int i = 0; i < numCandidatos - 1; i++) {
        for (int j = 0; j < numCandidatos - i - 1; j++) {
            if (notasFinais[j] < notasFinais[j + 1]) { 
                float tempNota = notasFinais[j];
                notasFinais[j] = notasFinais[j + 1];
                notasFinais[j + 1] = tempNota;

                char tempNome[15];
                strcpy(tempNome, nomesCandidatos[j]);
                strcpy(nomesCandidatos[j], nomesCandidatos[j + 1]);
                strcpy(nomesCandidatos[j + 1], tempNome);
            }
        }
    }

    printf("Candidatos Aprovados:\n");
    for (int i = 0; i < numCandidatos && i < 15; i++) {
        printf("%d. %s - Nota: %.2f\n", i + 1, nomesCandidatos[i], notasFinais[i]);
    }

    return 0;
}