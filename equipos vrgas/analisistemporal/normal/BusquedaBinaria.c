#include <stdio.h>
#include <stdlib.h>

int BusquedaBinaria(int A[], int n, int x);

int main(int argc, char *argv[])
{
    int i, j, n, *A;
    int x,posicion=0;

    // Recibir por argumento el tamaño de n y el valor a buscar
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
    
    posicion=BusquedaBinaria(A,n,x);

    if (posicion==0)
    {
         printf("valor no encontrado");
    }
    else{
        printf("Valor encontrado en la posición: %d",posicion);
    }
    

}

int BusquedaBinaria(int A[], int n, int x)
{
    int izquierda = 0;
    int derecha = n - 1;
    while (izquierda <= derecha)
    {
        int medio = (izquierda + derecha) / 2;
        if (A[medio] == x)
            return medio;
        else if (A[medio] < x)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }
    return 0;
}

