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
#include <dirent.h>
#include <string.h>

void listar_arquivos(const char *caminho, int nivel) {
    struct dirent *entrada;
    DIR *dir = opendir(caminho);
    
    if (dir == NULL) {
        printf("Erro!! Não foi possível abrir o diretório: %s\n", caminho);
        return;
    }

    while ((entrada = readdir(dir)) != NULL) {
        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0) {
            continue;
        }

        // Impressão hierárquica
        printf("%*s|-- %s\n", nivel * 2, "", entrada->d_name);

        char novo_caminho[1024];
        int tam = snprintf(novo_caminho, sizeof(novo_caminho), "%s/%s", caminho, entrada->d_name);
        if (tam < 0 || tam >= sizeof(novo_caminho)) {
            printf("Erro: caminho muito longo!\n");
            closedir(dir);
            return;
        }

        // Verifica se é um diretório de forma segura
        DIR *subdir = opendir(novo_caminho);
        if (subdir) {
            closedir(subdir);
            listar_arquivos(novo_caminho, nivel + 1);
        }
    }

    closedir(dir);
}

int main() {
    const char *caminho_inicial = "."; // Começa no diretório atual
    printf("Árvore de diretórios:\n");
    listar_arquivos(caminho_inicial, 0);
    return 0;
}
