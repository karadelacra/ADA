#include <stdio.h>
#include <stdlib.h>

void MergeSort(int A[], int p, int r);
void Merge(int A[],int p, int q, int r);

int main(int argc, char *argv[])
{
    int i, j, n, *A;

    // Recibir por argumento el tamaño de n y el valor a buscar
	if (argc != 2)
	{
		printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n", argv[0]);
		exit(1);
	}

	// Tomar el argumento del main
	n = atoi(argv[1]);
	A = malloc(n * sizeof(int));
	if (A == NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n", n);
		exit(1);
	}

	// Leer de la entrada estándar los n valores y colocarlos en el arreglo de números
	for (i = 0; i < n; i++)
		scanf("%d", &A[i]);

    MergeSort(A,0,n-1);
    printf("\nArreglo ordenado: \n");
    for (i = 0; i < n; i++)
	
        printf("%d: %d \n",i+1 , A[i]);


	free(A);



    return 0;
}

/*
MergeSort
Recibe:
	A[]: arreglo
	p: posici�n primer elemento
	r: posici�n �ltimo elemento

*/
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

/*
Recibe:
	A[]: Arreglo
	p: posici�n primer elemento
	q: posici�n elemento a la mitad
	r: posici�n final

	l: longitud de arreglo

*/
void Merge(int A[], int p, int q, int r)
{
	int k, l=r-p+1, i=p, j=q+1;
	//int C[l];
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
		//printf("C[%d] = %d\n",k, C[k]);
	}
	for(k=p,i=0;k<=r;k++,i++)
	{
		A[k]=C[i];
	}

	free(C);
}
