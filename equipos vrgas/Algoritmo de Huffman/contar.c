//El siguiente algoritmo contará cuantos caracteres hay en el archivo de texto que se lea y guardará la cantidad de vces que se repite cada caracter en un arreglo de estructuras

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>


void LimpiarArreglo();
void CargarArchivo();
// void ImprimirConteo();


int i = 0;
    char caracter = 'a';
    int p[256], k,l,c;
    int d[256];
    char direccion[256];

int main()
{   
    LimpiarArreglo();
    CargarArchivo();
    // ImprimirConteo();
    
    for (i = 0; i < 256; i++)
    {
       if (d[i] != 0)
       {
           printf("%c: %d\n", p[i], d[i]);
       }
    }

   
    return 0;
}

void CargarArchivo()
{
    FILE *archivo;
    // printf("Ingrese la direccion del archivo: \n");
    // scanf("%s", direccion);
    archivo = fopen("out.txt", "rb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        exit(1);
    }
     while ((c = fgetc(archivo)) != -1)
    {
       
       if (putchar(c) != 1)
       {     printf("letra: %c\n", c);
            k = putchar(c);
        if(k == p[k])
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
    memset(p,'\0', sizeof(p));
}

// void ImprimirConteo()
// {
//     FILE *archivo;
//     archivo = fopen("salida.txt", "w");

//     if (archivo == NULL)
//     {
//         printf("Error al abrir el archivo");
//         exit(1);
//     }

//     for(i = 0; i < 256; i++)
//     {
//         fprintf(archivo, "%c: %d\n", p[i], d[i]);
//     }
    

//     fclose(archivo);
// }