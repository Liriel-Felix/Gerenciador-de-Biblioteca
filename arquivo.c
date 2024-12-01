#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

No* carregar_livros(char* nome_arquivo, No* raiz) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s.\n", nome_arquivo);
        return raiz;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // Ignorar o cabeçalho

    while (fgets(linha, sizeof(linha), arquivo)) {
        Livro livro;
        char *token = strtok(linha, ",");

        if (token) livro.codigo = atoi(token); 

        token = strtok(NULL, ",");
        if (token) strncpy(livro.titulo, token, sizeof(livro.titulo) - 1);
        livro.titulo[sizeof(livro.titulo) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token) strncpy(livro.autor, token, sizeof(livro.autor) - 1);
        livro.autor[sizeof(livro.autor) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token) strncpy(livro.genero, token, sizeof(livro.genero) - 1);
        livro.genero[sizeof(livro.genero) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token) livro.ano = atoi(token);

        token = strtok(NULL, ",");
        if (token) strncpy(livro.editora, token, sizeof(livro.editora) - 1);
        livro.editora[sizeof(livro.editora) - 1] = '\0';

        token = strtok(NULL, ",");
        if (token) livro.num_paginas = atoi(token);

        if (buscar_por_codigo(raiz, livro.codigo) == NULL) {
            inserir_livro(&raiz, livro);
        }
    }
    
    fclose(arquivo);
    return raiz;
}
