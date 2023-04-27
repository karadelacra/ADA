#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "ABB.h"


void insertar(Nodo** raiz, int dato) {
    if (*raiz == NULL) {
        *raiz = (Nodo*) malloc(sizeof(Nodo));
        (*raiz)->dato = dato;
        (*raiz)->izquierda = NULL;
        (*raiz)->derecha = NULL;
    } else if (dato < (*raiz)->dato) {
        insertar(&((*raiz)->izquierda), dato);
    } else if (dato > (*raiz)->dato) {
        insertar(&((*raiz)->derecha), dato);
    }
}

Nodo* buscar(Nodo* raiz, int dato) {
    if (raiz == NULL || dato == raiz->dato) {
        return raiz;
    } else if (dato < raiz->dato) {
        return buscar(raiz->izquierda, dato);
    } else {
        return buscar(raiz->derecha, dato);
    }
}

void imprimirInOrder(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirInOrder(raiz->izquierda);
        printf("%d ", raiz->dato);
        imprimirInOrder(raiz->derecha);
    }
}

void liberarArbol(Nodo* raiz) {
    if (raiz != NULL) {
        liberarArbol(raiz->izquierda);
        liberarArbol(raiz->derecha);
        free(raiz);
    }
}
