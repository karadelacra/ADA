#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int BusquedaBinaria(int A[], int inicio, int fin, int x);
int BusquedaExponencial(int A[], int n, int x);

int main(int argc, char *argv[])
{
    int i, j, n, *A;
    int x,posicion=0;

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
     
    posicion=BusquedaExponencial(A,n,x);

    if (posicion==0)
    {
         printf("valor no encontrado\n");
    }
    else{
        printf("Valor encontrado en la posición: %d \n",posicion);
    }
    

}

int BusquedaExponencial(int A[], int n, int x) {
    
    if (A[0] == x)
    return 0;

    int i = 1;

    while (i < n && A[i] < x)
        i = i * 2;
    
    return BusquedaBinaria(A, i / 2, fmin(i, n - 1), x);
}

int BusquedaBinaria(int A[], int inicio, int fin, int x) 
{
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        if (A[medio] == x)
            return medio;
        else if (A[medio] < x)
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return 0;  
}
