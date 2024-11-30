#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct Livro {
    int codigo;
    char titulo[100];
    char autor[100];
    char genero[50];
    int ano;
    char editora[100];
    int num_paginas;
} Livro;

typedef struct No {
    Livro livro;
    struct No* esquerda;
    struct No* direita;
} No;

// Funções de árvore
No* inicializar_arvore();
void inserir_livro(No** raiz, Livro livro);
void buscar_por_genero(No* raiz, char genero[]);
void exibir_arvore(No* raiz);
void liberar_arvore(No* raiz);

// Funções de arquivo
No* carregar_livros(char* nome_arquivo, No* raiz);

#endif