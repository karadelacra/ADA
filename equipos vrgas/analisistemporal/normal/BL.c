/*
BL.c
Busqueda Lineal
V 24 / 04 / 23
Autor: Karel R. Padilla
Implementación del ordenamiento por burbuja en C basada en el pseudo=código
proporcionado por el profesor. Toma n números enteros de la entrada estándar
en la forma:
> BL.exe a n < nums.txt
Imprime la posición del valor encontrado o retorna -1 en caso de encontrar a o no respectivamente, junto al número de operaciones 
que se realizaron para encontrar el valor.
*/

#include <stdio.h>
#include <stdlib.h>

int BL(int *A, int n, int a);

int main(int argc, char *argv[])
{
    // Variables para el algoritmo
    int i, n, a, *A, pos;

    // Recibir por argumento el tamaño de n y el valor a buscar
    if (argc != 3)
    {
        printf("\nIndique tamanio de n y el valor a buscar - Ejemplo: [user@equipo]$ %s 100 5\n", argv[0]);
        exit(1);
    }

    // Tomar el argumento del main
    n = atoi(argv[1]);
    a = atoi(argv[2]);
    A = malloc(n * sizeof(int));
    if (A == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        exit(1);
    }

    // Leer de la entrada estándar los n valores y colocarlos en el arreglo de números
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    // Llamar al algoritmo
    pos = BL(A, n, a);
    int r=0;
    if (pos == -1)
    { 
        printf("\nEl valor %d no se encuentra en el arreglo.\n", a); 
       
    }
    else
    {
        printf("\nposición[-> %d <-]",pos);
    }       
    return 0;
}

BL(int *A, int n, int a)
{
    int i, op = 0;
    for (i = 0; i < n; i++)
    {
        op++;
        if (A[i] == a)
        {
            printf("\nOperaciones realizadas: %d", op);
            return i;
        }
    }
    printf("\nOperaciones realizadas: %d", op);
    return -1;
}
