/*-----------------------------------------------------------------*
*                      FATEC Ipiranga                              *
* Disciplina: Programaçao Estruturada e Modular                    *
*          Prof. Veríssimo                                         *
*------------------------------------------------------------------*
* Objetivo do Programa: Ordenar os dados utilizando Insertion      *
* Data - 16/05/2025                                                * 
* Autor:Eric Inácio de Toledo                                      *
*------------------------------------------------------------------*/

#include <stdio.h>

// Aqui vamos utilizar uma função que vai ordenar um vetor usando o algoritmo Insertion Sort
// Parâmetros: - valores: ponteiro para o vetor
//             - quantidade: número total de elementos
void ordenarInsertion(int *valores, int quantidade) {
    for (int i = 1; i < quantidade; i++) {
        // Vamos acessar o valor atual com a utilização de um ponteiro
        int chave = *(valores + i);
        int j = i - 1;

        // Movemos os elementos maiores (números) que a chave para frente
        while (j >= 0 && *(valores + j) > chave) {
            // Deslocamos os elemento para a direita
            *(valores + j + 1) = *(valores + j); 
            j--;
        }

        // Vamos arrumar deixando a chave em uma posição correta
        *(valores + j + 1) = chave;
    }
}

// Utilizaremos uma função onde vamos buscar imprimir os valores do vetor
void mostrarLista(int *v, int n) {
    for (int i = 0; i < n; i++) {
        // Essa soma *(v + i) é responsável por acessar o elemento "i" via ponteiro
        printf("%d\n", *(v + i));
    }
}

int main() {
    // Variável responsável por armazenar a quantidade de números que devemos ordenar
    int total;  

    // Já aqui perguntamos ao usuário a quantidade de números que ele gostaria de ordenar
    printf("Quantos números deseja ordenar com Insertion Sort? ");
    if (scanf("%d", &total) != 1 || total <= 0) {
        // Essa mensagem vai aparecer se o usuário acabar digitando uma letra ou um número menor que 1 
        printf("Quantidade inválida.\n");
        return 1;
    }

    // O vetor lista terá tamanho definido em tempo de execução, conforme o valor da variável "total" fornecido pelo usuário
    int lista[total];

    // Aqui usamos o for para lê os valores inseridos pelo usuário e os armazena no vetor
    for (int i = 0; i < total; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &lista[i]);  
    }

    // Aqui vamos chamar a função de ordenação e o vetor é passado como ponteiro, e a variável total é passada por valor
    ordenarInsertion(lista, total);  

    // E por último mostra os valores ordenados
    printf("\nNúmeros ordenados atraves do Insertion Sort:\n");
    mostrarLista(lista, total);  

    return 0;
}
