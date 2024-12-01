#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    No* biblioteca = inicializar_arvore();
    int opcao;
    char genero[50];
    Livro novo_livro;

    do {
        printf("\n--- Gerenciador de Biblioteca ---\n");
        printf("1. Carregar livros do CSV\n");
        printf("2. Inserir novo livro\n");
        printf("3. Buscar livros por gênero\n");
        printf("4. Exibir todos os livros\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                biblioteca = carregar_livros("livros.csv", biblioteca);
                break;
            case 2:
                printf("Código: ");
                scanf("%d", &novo_livro.codigo);
                getchar(); 

                printf("Título: ");
                fgets(novo_livro.titulo, sizeof(novo_livro.titulo), stdin);
                novo_livro.titulo[strcspn(novo_livro.titulo, "\n")] = '\0';

                printf("Autor: ");
                fgets(novo_livro.autor, sizeof(novo_livro.autor), stdin);
                novo_livro.autor[strcspn(novo_livro.autor, "\n")] = '\0';

                printf("Gênero: ");
                fgets(novo_livro.genero, sizeof(novo_livro.genero), stdin);
                novo_livro.genero[strcspn(novo_livro.genero, "\n")] = '\0';

                printf("Ano: ");
                scanf("%d", &novo_livro.ano);
                getchar();

                printf("Editora: ");
                fgets(novo_livro.editora, sizeof(novo_livro.editora), stdin);
                novo_livro.editora[strcspn(novo_livro.editora, "\n")] = '\0';

                printf("Número de Páginas: ");
                scanf("%d", &novo_livro.num_paginas);

                if (buscar_por_codigo(biblioteca, novo_livro.codigo) != NULL) {
                    printf("Livro com código %d já existe.\n", novo_livro.codigo);
                } else {
                    inserir_livro(&biblioteca, novo_livro);
                }
                break;
            case 3:
                printf("Informe o gênero: ");
                fgets(genero, sizeof(genero), stdin);
                genero[strcspn(genero, "\n")] = '\0';
                buscar_por_genero(biblioteca, genero);
                break;
            case 4:
                exibir_arvore(biblioteca);
                break;
            case 5:
                liberar_arvore(biblioteca);
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    return 0;
}
