/*-----------------------------------------------------------------*
*                      FATEC Ipiranga                              *
* Disciplina: Programaçao Estruturada e Modular                    *
*          Prof. Veríssimo                                         *
*------------------------------------------------------------------*
* Objetivo do Programa: Ordenar os dados utilizando Bubblesort     *
* Data - 16/05/2025                                                * 
* Autor:Eric Inácio de Toledo                                      *
*------------------------------------------------------------------*/
#include <stdio.h>

// Aqui utilizaremos a função que irá ordenar um vetor usando o algoritmo Bubble Sort
// Os parâmetros utilizados são: - valores: ponteiro para o vetor a ser ordenado
//                               - quantidade: ponteiro para a quantidade de elementos do vetor
void ordenarBubble(int *valores, int *quantidade) {
    // Usamos a variável *quantidade para acessar o valor apontado
    for (int i = 0; i < *quantidade; i++) {  
        for (int j = 0; j < *quantidade - i - 1; j++) {
            // Vamos acessar os elementos por meio da aritmética dos ponteiros
            if (*(valores + j) > *(valores + j + 1)) {
                 // Aqui ocorre uma troca entre os valores com a utilização dos ponteiros
                int aux = *(valores + j);
                *(valores + j) = *(valores + j + 1);
                *(valores + j + 1) = aux;
            }
        }
    }
}

// Agora vamos utilizar outra função que irá imprimir os valores do vetor
// Os parâmetros utilizados são: - v: ponteiro para o vetor
//                               - n: quantidade de elementos
void mostrarLista(int *v, int n) {
    for (int i = 0; i < n; i++) {
        //Fazemos a soma *(v + i) a fim de acessar o elemento na posição i (uso de ponteiro)
        printf("%d\n", *(v + i));
    }
}

int main() {
    // Aqui implementamos uma variável para armazenar a quantidade de números
    int total;  

    // Já aqui perguntamos ao usuário a quantidade de números que ele gostaria de ordenar
    printf("Quantos números deseja ordenar com Bubble Sort? ");
    if (scanf("%d", &total) != 1 || total <= 0) {
    // Essa mensagem vai aparecer se o usuário acabar digitando uma letra ou um número menor que 1   
        printf("Quantidade inválida.\n");
        return 1;
    }

    // O vetor lista terá tamanho definido em tempo de execução, conforme o valor da variável "total" fornecido pelo usuário.
    int lista[total];

    // Aqui usamos o for para lê os valores inseridos pelo usuário e os armazena no vetor
    for (int i = 0; i < total; i++) {
        printf("Digite o %dº número: ", i + 1);
    // Nesse caso, lista[i] é equivalente a *(lista + i)
        scanf("%d", &lista[i]);  
    }

    // Aqui vamos chamar a função de ordenação e o vetor é passado como ponteiro, e a variável total é passada por valor
    ordenarBubble(lista, &total);  

    // E por último mostra os valores ordenados
    printf("\nNúmeros ordenados atraves do Bubble Sort:\n");
    mostrarLista(lista, total);  

    return 0;
}