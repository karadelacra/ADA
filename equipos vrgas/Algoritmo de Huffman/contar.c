// El siguiente algoritmo contará cuantos caracteres hay en el archivo de texto que se lea y guardará la cantidad de vces que se repite cada caracter en un arreglo de estructuras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "lib/TAD_ABB/TADABB.h"
#include "lib/presentacion.h"

// forma de compilar gcc .\contar.c -o .\contar.exe lib/TAD_ABB/TADABB.c lib/presentacionWin.c -w

void LimpiarArreglo();
void CargarArchivo(abb *arbol);
void shell(int *d, int *p, int n);
void Imprimir(int d[], int p[]);
void CargarArbol(abb *arbol, int d[], int p[]);
void limpiarBuffer();

int i = 0;
char caracter = 'a';
int k, c;
int d[256];
int p[256];
char direccion[256];

int main()
{
    abb arbol;
    elemento e;
    posicion pos;
    Initialize(&arbol);
    BorrarPantalla();
    printf("\n\033[34m Compresor de Archivos\n");
    printf("Archivo a comprimir: ");
    scanf("%s", direccion);
    CargarArchivo(&arbol);
    

    return 0;
}

void CargarArchivo(abb *arbol)
{
    LimpiarArreglo();
    FILE *archivo, *r;
    archivo = fopen(direccion, "rb");
    r = fopen("basura.txt", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
    while ((c = fgetc(archivo)) != -1)
    {

        if (fgetc(archivo) != 1)
        {
            k = fputc(c, r);
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

    Imprimir(d, p);
    CargarArbol(&arbol, d, p);
    fclose(archivo);
    fclose(r);
    remove("basura.txt");
}

void LimpiarArreglo()
{
    memset(d, 0, sizeof(d));
    memset(p, '\0', sizeof(p));
}

void shell(int *d, int *p, int n)
{
    int i, k, b, temp, temp2;

    k = trunc(n / 2);
    while (k >= 1)
    {
        b = 1;
        while (b != 0)
        {
            b = 0;
            for (i = k; i < n; i++)
            {
                if (d[i - k] > d[i])
                {
                    temp = d[i];
                    temp2 = p[i];
                    d[i] = d[i - k];
                    p[i] = p[i - k];
                    d[i - k] = temp;
                    p[i - k] = temp2;
                    b = b + 1;
                }
            }
        }
        k = trunc(k / 2);
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

void CargarArbol(abb *arbol, int d[], int p[])
{
    elemento e;
    int cont = 0;
    for (i = 0; i <= 256; i++)
    {
        if (d[i] != '\0' && p[i] != ':')
        {
            sprintf(&e.p, "%c", p[i]);
            e.d = d[i];
            cont = 0;
        }
        else if (cont == 0 && p[i] == ':')
        {
            cont++;
        }
        if (cont == 1 && p[i] == ':')
        {
            cont = 1;
            sprintf(&e.p, "%c", p[i]);
            e.d = d[i];
        }
        if (cont == 1 && p[i] != ':')
        {
            sprintf(&e.p, "%c", p[i]);
            e.d = d[i];
            Add(arbol, e);
        }
    }
    RecorridoInOrden(&arbol);
}


