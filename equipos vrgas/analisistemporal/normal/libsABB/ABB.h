#ifndef __ABB_H
#define __ABB_H


typedef struct nodo {
    int dato;
    struct nodo* izquierda;
    struct nodo* derecha;
} Nodo;

void insertar(Nodo** raiz, int dato);
Nodo* buscar(Nodo* raiz, int dato);
void imprimirInOrder(Nodo* raiz);
void liberarArbol(Nodo* raiz);

#endif // __TADABB_H