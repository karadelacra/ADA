/*
ABB.c
Arbol Binario de Busqueda (ABB)
V 26 / 04 / 23
Autor: Karel R. Padilla
Implementación Busqueda en eun arbon descrito en un arreglo dado por n.
Toma n números enteros de la entrada estándar
en la forma:
> ABB.exe a n < nums.txt
Imprime la posición del valor encontrado o retorna -1 en caso de encontrar a o no respectivamente, junto al número de operaciones 
que se realizaron para encontrar el valor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libsABB/ABB.h"

void insertar(Nodo** raiz, int dato);
Nodo* buscar(Nodo* raiz, int dato);
void imprimirInOrder(Nodo* raiz);
void liberarArbol(Nodo* raiz);

int main(int argc, char *argv[]) {
    Nodo* raiz = NULL;
    int n = atoi(argv[1]);
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = atoi(argv[i+2]);
        insertar(&raiz, a[i]);
    }
    printf("Elementos del arbol en orden ascendente: ");
    imprimirInOrder(raiz);
    printf("\n");
    int x = atoi(argv[n+2]);
    Nodo* resultado = buscar(raiz, x);
    if (resultado == NULL) {
        printf("El elemento %d no se encuentra en el arbol.\n", x);
    } else {
        printf("El elemento %d se encuentra en el arbol.\n", x);
    }
    liberarArbol(raiz);
    return 0;
}
