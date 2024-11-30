#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

No* inicializar_arvore() {
    return NULL;
}

void inserir_livro(No** raiz, Livro livro) {
    if (*raiz == NULL) {
        No* novo = (No*)malloc(sizeof(No));
        novo->livro = livro;
        novo->esquerda = NULL;
        novo->direita = NULL;
        *raiz = novo;
    } else if (livro.codigo < (*raiz)->livro.codigo) {
        inserir_livro(&((*raiz)->esquerda), livro);
    } else if (livro.codigo > (*raiz)->livro.codigo) {
        inserir_livro(&((*raiz)->direita), livro);
    } else {
        printf("Livro com código %d já existe.\n", livro.codigo);
    }
}

void buscar_por_genero(No* raiz, char genero[]) {
    if (raiz != NULL) {
        buscar_por_genero(raiz->esquerda, genero);
        if (strcmp(raiz->livro.genero, genero) == 0) {
            printf("Código: %d | Título: %s | Autor: %s | Ano: %d | Editora: %s | Páginas: %d\n",
                   raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor,
                   raiz->livro.ano, raiz->livro.editora, raiz->livro.num_paginas);
        }
        buscar_por_genero(raiz->direita, genero);
    }
}

void exibir_arvore(No* raiz) {
    if (raiz != NULL) {
        exibir_arvore(raiz->esquerda);
        printf("Código: %d | Título: %s | Autor: %s | Gênero: %s | Ano: %d | Editora: %s | Páginas: %d\n",
               raiz->livro.codigo, raiz->livro.titulo, raiz->livro.autor,
               raiz->livro.genero, raiz->livro.ano, raiz->livro.editora,
               raiz->livro.num_paginas);
        exibir_arvore(raiz->direita);
    }
}

void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esquerda);
        liberar_arvore(raiz->direita);
        free(raiz);
    }
}