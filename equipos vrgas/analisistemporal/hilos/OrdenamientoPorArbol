#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *izquierdo, *derecho;
} Nodo;

void crear_arbol(int *A, int n, Nodo **raiz);
void insertar(Nodo **raiz, int valor);
int buscar(Nodo *raiz, int valor);

int main(int argc, char *argv[])
{
    int i, j, n, *A;
    int x,valor=0;
    Nodo *raiz = NULL;
    
	if (argc != 3)
	{
		printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n", argv[0]);
		exit(1);
	}

    n = atoi(argv[1]);
	A = malloc(n * sizeof(int));
    x = atoi(argv[2]);

    for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

    crear_arbol(A, n, &raiz);

    valor=buscar(raiz,x);

    if (valor==0)
    {
         printf("valor no encontrado");
    }
    else{
        printf("Valor encontrado y es: %d",valor);
    }
    
    

}

void crear_arbol(int *A, int n, Nodo **raiz) {
    int i;
    for (i = 0; i < n; i++) {
        insertar(raiz, A[i]);
    }
}

void insertar(Nodo **raiz, int valor) {
    if (*raiz == NULL) {
        *raiz = malloc(sizeof(Nodo));
        (*raiz)->valor = valor;
        (*raiz)->izquierdo = NULL;
        (*raiz)->derecho = NULL;
    } else if (valor < (*raiz)->valor) {
        insertar(&((*raiz)->izquierdo), valor);
    } else {
        insertar(&((*raiz)->derecho), valor);
    }
}

int buscar(Nodo *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz->valor;
    } else if (valor < raiz->valor) {
        return buscar(raiz->izquierdo, valor);
    } else {
        return buscar(raiz->derecho, valor);
    }
}