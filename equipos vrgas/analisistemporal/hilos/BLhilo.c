/*
BLhilo.c
Busqueda Lineal implementando hilos
V 24 / 04 / 23
Autor: Karel R. Padilla
Autor; Mauricio Morales Franco
*/


 /*Forma de compilación:
 gcc BLhilo.c -o BLhilo -w tiempo.c (Linux)

 gcc = compilador, BLhilo.c = nombre del archivo fuente, -o BLhilo.exe = nombre del ejecutable, -w = no mostrar advertencias, tiempo.c = archivo de funciones de tiempo
*/


/*Implementación del ordenamiento por burbuja en C basada en el un pseudo Toma n números enteros de la entrada estándar
en la forma:
BLhilo a n < nums.txt (Linux)

a= num buscado, n = longitud del arrreglo, nums.txt= archivo de texto a leer
Imprime la posición del valor encontrado o retorna -1 en caso de encontrar a o no respectivamente, junto al número de operaciones 
que se realizaron para encontrar el valor.*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "tiempo.h"


int NumThreads;			//Número de threads
int N;
int i, n, a, *A, pos;

void* procesar(void* id)
{	
	int n_thread=(int)id;
	int inicio,fin,i,pos;

	//Revisar la parte de los datos a procesar	
	inicio=(n_thread*N)/NumThreads;
	if(n_thread==NumThreads-1)	
		fin=N;
	else
		fin=((n_thread+1)*N)/NumThreads-1;

    pos = BL(A, inicio, fin, a);
    if (pos != -1)
    { 
        printf("\nposición[-> %d <-]",pos);
       
    }
}


int BL(int *A, int m, int n, int a)
{
    int i;
    for (i = m; i < n; i++)
    {
        if (A[i] == a)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    // Variables para el algoritmo
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
	uswtime(&utime0, &stime0, &wtime0);

    pthread_t *thread;
	if (argc<2) 
	{
		printf("Indique el número de threads - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
		exit(-1);
	}  
	NumThreads=atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));

	//***************************************************************************************************************************
	//Saber cuál es el tamaño del problema N
	//***************************************************************************************************************************	
	//Si no se introduce correctamente N
	if (argc<3) 
	{
		printf("\nIndique el tamaño de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	N=atoi(argv[2]);

    // Recibir por argumento el tamaño de n y el valor a buscar
    if (argc != 4)
    {
        printf("\nIndique tamanio de n y el valor a buscar - Ejemplo: [user@equipo]$ %s 100 5\n", argv[0]);
        exit(1);
    }
    a = atoi(argv[3]);
    A = malloc(N * sizeof(int));
    if (A == NULL)
    {
        printf("\nError al intentar reservar memoria para %d elementos\n", n);
        exit(1);
    }

    // Leer de la entrada estándar los n valores y colocarlos en el arreglo de números
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    	    
    for (i=1; i<NumThreads; i++) 
	{
		if (pthread_create (&thread[i], NULL, procesar,(void*)i) != 0 ) 
		{
			perror("El thread no  pudo crearse");
			exit(-1);
		}
	}
	
	//El main ejecuta el thread 0
	procesar(0);
	
	//Esperar a que terminen los threads (Saludar)
	for (i=1; i<NumThreads; i++) pthread_join (thread[i], NULL);


    uswtime(&utime1, &stime1, &wtime1);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}
