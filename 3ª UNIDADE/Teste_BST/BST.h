#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct noBst {
    int val;
    struct noBst* esq;
    struct noBst* dir;
};

/**
 * Funcao que aloca um novo noBst, e
 * ajusta os ponteiros esq e dir para NULL.
 **/
struct noBst* alocarNovoNo(int val) {
    struct noBst* no = (struct noBst*)malloc(sizeof(struct noBst));
    no->val = val;
    no->esq = NULL;
    no->dir = NULL;
    
    return no;
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * insere um novo valor na BST. Tamanho deve
 * ser incrementado.
 * Ambos tamanho e raiz são passados por referência.
 **/
void inserir(struct noBst** raiz, int val, int* tamanho) {
    if ((*raiz) == NULL) {
        (*raiz) = alocarNovoNo(val);
        (*tamanho)++;
    }
    else if (val <= (*raiz)->val) {
        inserir(&((*raiz)->esq), val, tamanho);
    }
    else {
        inserir(&((*raiz)->dir), val, tamanho);
    }
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * verifica se a mesma contém um dado valor.
 **/
bool buscar(struct noBst* raiz, int val) {
    if (raiz == NULL) {
        return false;
    }
    else if (val == raiz->val) {
        return true;
    }
    else if (val <= raiz->val) {
        return buscar(raiz->esq, val);
    }
    else {
        return buscar(raiz->dir, val);
    }
}

/**
 * Funcao que retorna o maior valor de uma BST. O maior valor a gente sabe que está do lado direito
 **/
int max(struct noBst* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else if (raiz->dir == NULL) {
        return raiz->val;
    }
    else {
        return max(raiz->dir);
    }
}

/**
 * Funcao que retorna o menor valor de uma BST. O menor valor a gente sabe que está do lado esquerdo
 **/
int min(struct noBst* raiz) {
    if (raiz == NULL) {
        return 0;
    }
    else if (raiz->esq == NULL) {
        return raiz->val;
    }
    else {
        return min(raiz->esq);
    }
}

/**
 * Funcao que retorna a altura de uma BST.
 * A altura de uma BST é dada pela quantidade
 * de arestas entre a raiz e a folha mais distante. 
 **/
int altura(struct noBst* raiz) {
    if (raiz == NULL || (raiz->esq == NULL && raiz->dir == NULL)) {
        return 0;
    }
    
    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);
    if (alturaEsq > alturaDir) {
        return (alturaEsq + 1);
    }
    else {
        return (alturaDir + 1);
    }
}

/**
 * Funcao que navega em-ordem na BST e
 * imprime seus elementos.
 **/
void emOrdem(struct noBst* raiz) {
    if (raiz == NULL) {
        return;
    }
    emOrdem(raiz->esq);
    printf("%d", raiz->val);
    emOrdem(raiz->dir);
}

/**
 * Funcao que navega pre-ordem na BST e
 * imprime seus elementos.
 **/
void preOrdem(struct noBst* raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("%d", raiz->val);
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

/**
 * Funcao que navega pos-ordem na BST e
 * imprime seus elementos.
 **/
void posOrdem(struct noBst* raiz) {
    if (raiz == NULL) {
        return;
    }
    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d", raiz->val);
}

/**
 * Funcao que recebe a raiz de uma BST, e
 * remove o no que contem o valor passado como
 * argumento. Tamanho deve ser decrementado.
 * Tamanho é passado por referência.
 **/
struct noBst* remover(struct noBst* raiz, int val, int* tamanho) {
    if (raiz == NULL) {
        return raiz;
    }
    if (raiz->val > val) {
        raiz->esq = remover(raiz->esq, val, tamanho--);
        return raiz;
    }
    else if (raiz->val < val) {
        raiz->dir = remover(raiz->dir, val, tamanho--);
        return raiz;
    }

    noBst* temp = NULL;

    if (raiz->esq == NULL) {
        temp = raiz->dir;
        delete raiz;
        return temp;
    }
    else if (raiz->dir == NULL) {
        temp = raiz->esq;
        delete raiz;
        return temp;
    }
    else {
        temp = raiz;
        noBst* prox = raiz->dir;

        while (prox->esq != NULL) {
            temp = prox;
            prox = prox->esq;
        }

        if (temp != raiz){
            temp->esq = prox->dir;
        }
        else {
            temp->dir = prox->dir;
        }
        raiz->val = prox->val;
        delete prox;
        return raiz;
    }
}