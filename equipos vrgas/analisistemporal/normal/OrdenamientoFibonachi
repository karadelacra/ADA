#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[], int p, int r);
void Merge(int A[],int p, int q, int r);
int min(int x, int y);
int BusquedaFibonacci(int A[], int n, int x);

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
    
    MergeSort(A,0,n-1);

    posicion = BusquedaFibonacci(A, n, x);

    if (posicion == 0)
    {
        printf("El valor no se encuentra ");
    }
    else
    {
        printf("Valor encontrado en la posición: %d",posicion);
    }



}

void Merge(int A[], int p, int q, int r)
{
	int k, l=r-p+1, i=p, j=q+1;

	int *C = malloc(l * sizeof(int));
	if (C == NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n", l);
		exit(1);
	}

	for(k=0;k<l;k++)
	{
		if(i<=q&&j<=r)
		{
			if(A[i]<A[j])
			{
				C[k]=A[i];
				i++;
			}
			else
			{
				C[k]=A[j];
				j++;
			}
		}
		else if(i<=q)
		{
			C[k]=A[i];
			i++;
		}
		else
		{
			C[k]=A[j];
			j++;
		}
	}
	for(k=p,i=0;k<=r;k++,i++)
	{
		A[k]=C[i];
	}

	free(C);
}

#include <stdio.h>
#include <stdlib.h>

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int BusquedaFibonacci(int A[], int n, int x) 
{
    int FibAnterior1 = 1, FibAnterior2 = 0, FibActual = FibAnterior1 + FibAnterior2;
    int posicion = -1;

    // Calcular el número de Fibonacci más grande menor o igual al tamaño del arreglo
    while (FibActual < n)
    {
        FibAnterior2 = FibAnterior1;
        FibAnterior1 = FibActual;
        FibActual = FibAnterior1 + FibAnterior2;
    }

    // Realizar la búsqueda
    while (FibActual > 1)
    {
        int i = min(posicion + FibAnterior2, n - 1);

        if (A[i] < x)
        {
            FibActual = FibAnterior1;
            FibAnterior1 = FibAnterior2;
            FibAnterior2 = FibActual - FibAnterior1;
            posicion = i;
        }
        else if (A[i] > x)
        {
            FibActual = FibAnterior2;
            FibAnterior1 = FibAnterior1 - FibAnterior2;
            FibAnterior2 = FibActual - FibAnterior1;
        }
        else
        {
            return i;
        }
    }

    if (FibAnterior1 == 1 && A[posicion + 1] == x)
    {
        return posicion + 1;
    }

    return 0;
}


