#include <stdio.h>
#include <stdlib.h>

void Shell(int *A, int n);

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

    Shell(A, n);
    printf("\nArreglo ordenado: \n");
    for (i = 0; i < n; i++)
	
        printf("%d: %d \n",i+1 , A[i]);


	free(A);



    return 0;
}

void Shell(int *A, int n)
{
    int i,k,b,temp;
    k=trunc(n/2);
    while(k>=1){
        b = 1;
        while (b!=0){
            b=0;
            for (i=k; i<n; i++){
                if (A[i-k] > A[i]){
                    temp=A[i];
                    A[i]=A[i-k];
                    A[i-k]=temp;
                    b=b+1;
                }
            }

        }
        k=trunc(k/2);
    }
}