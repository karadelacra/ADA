// este programa ordenará el arreglo de números que se
//  le dé recibiendo los datos desde la consola

#include <stdio.h>
#include <stdlib.h>

void BurbujaSimple(int *A, int n);

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

    BurbujaSimple(A, n);
    printf("\nArreglo ordenado: \n");
    for (i = 0; i < n; i++)
	
        printf("%d: %d \n",i+1 , A[i]);


	free(A);



    return 0;
}

void BurbujaSimple(int *A, int n)
{
	int i, j, aux;
	
	for (i=0; i <= n-2; i++)
    {
        for (j=0; j <= (n-2); j++)
        {
            if (A[j] > A[j+1])
            {
                aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}