// El siguiente algoritmo contará cuantos caracteres hay en el archivo de texto que se lea y guardará la cantidad de vces que se repite cada caracter en un arreglo de estructuras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lib/TAD_ABB/TADABB.h"
#include "lib/presentacion.h"

void LimpiarArreglo();
void CargarArchivo();
void shell(int *d, int *p, int n);
void Imprimir(int d[], int p[]);

int i = 0;
char caracter = 'a';
int k, c;
int r = 256;
int pp = 0;
int q;
int d[256];
int p[256];
char direccion[256];

int main()
{
    LimpiarArreglo();
    CargarArchivo();
    Imprimir(d, p);

    return 0;
}

void CargarArchivo()
{
    FILE *archivo;
    printf("Ingrese la direccion del archivo: \n");
    scanf("%s", direccion);
    archivo = fopen(direccion, "rb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    while ((c = fgetc(archivo)) != -1)
    {

        if (putchar(c) != 1)
        {
            //   printf("letra: %c\n", c);
            k = putchar(c);
            if (k == p[k])
            {
                d[k]++;
            }
            else
            {
                p[k] = k;
                d[k] = 1;
            }
        }
    }
    fclose(archivo);
}

void LimpiarArreglo()
{
    memset(d, 0, sizeof(d));
    memset(p, '\0', sizeof(p));
}

void shell(int *d, int *p, int n)
{
    int i,k,b,temp,temp2;

    k=trunc(n/2);
    while(k>=1){
        b = 1;
        while (b!=0){
            b=0;
            for (i=k; i<n; i++){
                if (d[i-k] > d[i]){
                    temp=d[i];
                    temp2=p[i];
                    d[i]=d[i-k];
                    p[i]=p[i-k];
                    d[i-k]=temp;
                    p[i-k]=temp2;
                    b=b+1;
                }
            }

        }
        k=trunc(k/2);
    }
}

void Imprimir(int d[], int p[])
{
    shell(d, p, 256);
    FILE *archivo;
    archivo = fopen("salida.txt", "w");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }

    for (i = 0; i <= 256; i++)
    {
        if (d[i] != 0)
        {
            fprintf(archivo, "%c: %d\n", p[i], d[i]);
        }
    }

    fclose(archivo);
}