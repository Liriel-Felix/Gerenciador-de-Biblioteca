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
                printf("Título: ");
                scanf(" %[^\n]", novo_livro.titulo);
                printf("Autor: ");
                scanf(" %[^\n]", novo_livro.autor);
                printf("Gênero: ");
                scanf(" %[^\n]", novo_livro.genero);
                printf("Ano: ");
                scanf("%d", &novo_livro.ano);
                printf("Editora: ");
                scanf(" %[^\n]", novo_livro.editora);
                printf("Número de Páginas: ");
                scanf("%d", &novo_livro.num_paginas);
                inserir_livro(&biblioteca, novo_livro);
                break;
            case 3:
                printf("Informe o gênero: ");
                scanf(" %[^\n]", genero);
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