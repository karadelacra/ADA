#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[], int p, int r);
void Merge(int A[],int p, int q, int r);
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
    
    MergeSort(A,0,n-1);

    posicion=BusquedaBinaria(A,n,x);

    if (posicion==0)
    {
         printf("valor no encontrado");
    }
    else{
        printf("Valor encontrado en la posición: %d",posicion);
    }
    

}

void MergeSort(int A[], int p, int r)
{
	int q;

	if (p<r)
	{
		q=(p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
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

