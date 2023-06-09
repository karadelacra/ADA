/*
Autor: Edgardo Adrián Franco Martínez
Versión 1.1 (02 de Octubre de 2013)
Descripción: Cabecera de la libreria para recrear presentaciones más agradables al usuario en el modo consola bajo Linux
Observaciones: Esta implementación de la libreria solo es compatible con Linux y el compilador GNU gcc  de UNIX ya que utiliza la libreria "unistd.h", la cuál no es estandar.
Compilación de la libreria: Linux (gcc -c presentacionLin.c)
*/
//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  		//Libreria no ANSI C/
// #include <time.h>
#include"presentacion.h"

//DEFINICIÓN DE FUNCIONES

//Función para mover el cursor de escritura de pantalla, simulación de la función gotoxy() que se tenia en borland 3.0 en la libreria conio.h
void MoverCursor( int x, int y )
{
	printf("%c[%d;%df",0x1B,y,x);
	return;
}

//Función para esperar un tiempo en milisegundos, simulación de la función delay() que se tenia en borland 3.0 en la libreria conio.h
void EsperarMiliSeg(int t)
{
	// usleep fue reemplazada por nanosleep en POSIX.1-2001
	usleep(t*1000);		//Función no ANSI C
	// struct timespec tim, tim2;
	// tim.tv_sec = 0;
	// tim.tv_nsec = t*1000000L;
	// nanosleep(&tim , &tim2);
	return;
}

