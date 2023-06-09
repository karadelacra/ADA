#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "tiempo.h"

int NumThreads;//Número de threads
int x;

int i, n, a, *A, pos, N, cont, logrado = 0;

int min(int a, int y);
int BusquedaFibonacci(int A[], int inicio, int fin, int a);
void* procesar(void* id);


int main(int argc, char *argv[])
{
    // Variables para el algoritmo
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
	uswtime(&utime0, &stime0, &wtime0);

    pthread_t *thread;
	if (argc != 4) 
	{
		printf("El programa se ejecuta como: (numero de threads) (tamaño de N) (valor a buscar) (alcivo en el que se busca)  %s 4\n\n",argv[0]);
		printf("Ejemplo:  %s 4 1000 5 < nums.txt\n",argv[0]);
		exit(-1);
	}  
  	//asignar los valores de los argumentos a las variables correspondientes

	NumThreads=atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));

	N=atoi(argv[2]);

    a = atoi(argv[3]);
    A = malloc(N * sizeof(int));
   
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
    if(logrado == NumThreads)
    {
        printf("No se encontro el numero");
    } 
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU's) %.10f s\n",  utime1 - utime0);
	printf("%d threads (Tiempo de procesamiento aproximado por cada thread en CPU) %.10f s\n", NumThreads,(utime1 - utime0)/NumThreads);	
	printf("sys (Tiempo en acciónes de E/S)  %.3f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
}

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

    pos = BusquedaFibonacci(A, inicio, fin, a);
    if (pos != -1)
    {

        printf("posicion: %d", pos + 1);
    }
    else
    {
        logrado++;
    }
}

int min(int a, int y)
{
    return (a <= y) ? a : y;
}

int BusquedaFibonacci(int A[], int inicio, int fin, int a)
{
    int FibAnterior1 = 1, FibAnterior2 = 0, FibActual = FibAnterior1 + FibAnterior2;
    int posicion = -1;

    // Calcular el número de Fibonacci más grande del arreglo, menor o igual a n
    while (FibActual < n)
    {
        FibAnterior2 = FibAnterior1;
        FibAnterior1 = FibActual;
        FibActual = FibAnterior1 + FibAnterior2;
    }

    // Realizar la búsqueda
    while (FibActual > 1)
    {
        int i = min(posicion + FibAnterior2, fin - 1);

        if (A[i] < a)
        {
            FibActual = FibAnterior1;
            FibAnterior1 = FibAnterior2;
            FibAnterior2 = FibActual - FibAnterior1;
            posicion = i;
        }
        else if (A[i] > a)
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

    if (FibAnterior1 == 1 && A[posicion + 1] == a)
    {
        return posicion + 1;
    }

    return -1;
}


