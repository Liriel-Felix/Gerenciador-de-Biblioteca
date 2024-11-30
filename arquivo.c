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
    while (fgets(linha, sizeof(linha), arquivo)) {
        Livro livro;
        sscanf(linha, "%d,%99[^,],%99[^,],%49[^,],%d,%99[^,],%d",
               &livro.codigo, livro.titulo, livro.autor, livro.genero,
               &livro.ano, livro.editora, &livro.num_paginas);
        inserir_livro(&raiz, livro);
    }

    fclose(arquivo);
    return raiz;
}