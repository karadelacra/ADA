#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "TADABB.h"
//#include "../TAD_Lista/TADListaSL.h"

/***************************************************************************************
								OPERACIONES DE CONSTRUCCI�N
***************************************************************************************/
//inicializar el arbol
int ultimabusqueda;

void Initialize(abb *a)
{
    a->raiz = NULL;
    a->finabb = NULL;
    a->nivel = 0;
    a->tam = 0;
    printf("\n  ARBOL CREADO");
    return;
}
void Destroy(abb *a)
{
	while(a->raiz != NULL)
	{
		Remove(a, Root(a));
	}
    a->finabb = NULL;
    a->nivel = 0;
    a->tam = 0;
    printf("\n  ARBOL DESTRUIDO");
    return;
}
void CombinarArboles(abb *a, abb *b, abb *c, elemento e)
{
	Initialize(c);
	c->raiz = (posicion)malloc(sizeof(nodoBin));
	c->raiz->dato = e;
	c->raiz->izq = a->raiz;
	c->raiz->der = b->raiz;
	c->raiz->padre = NULL;
	c->finabb = NULL;
	c->nivel = 0;
	return;
}
/***************************************************************************************
						OPERACIONES DE POSICIONAMIENTO Y B�SQUEDA
***************************************************************************************/
// Recibe un ABB y devuelve la posici�n de la ra�z.
posicion Root(abb *a)
{
    return a->raiz;
}
// Recibe un ABB a y una posici�n p, devuelve la posici�n de el padre.
posicion Parent(abb *a, posicion p)
{
    return p->padre;
}
// Recibe un ABB a y una posici�n p, devuelve la posici�n del hijo derecho.
posicion RightSon(abb *a, posicion p)
{
    return p->der;
}
// Recibe un ABB a y una posici�n p, devuelve la posici�n del hijo izquierdo.
posicion LeftSon(abb *a, posicion p)
{
    return p->izq;
}
// Recibe un ABB a y un elemento e, devuelve la posici�n del elemento en el �rbol.
posicion Search(abb *a, elemento e)
{
	ultimabusqueda = 0;
	a->ultbusq = 0;
	posicion aux = BuscarPosPalabra(Root(a), e.p);
	a->ultbusq = ultimabusqueda;
	//printf("\n  N%cmero de b%csquedas: %d",163,163,a->ultbusq);
	return aux;
}
// Recibe una posicion p y una palabra[101] y recursivamente busca si la palabra se encuentra en el �rbol
posicion BuscarPosPalabra(posicion nodo, char palabra[101])
{
	posicion aux = NULL;
	if(nodo == NULL){
	}
	else if(strcmp(nodo->dato.p, palabra) == 0){
		aux = nodo;
	}
	else{
		/*if(BuscarPosPalabra(nodo->izq, palabra) != NULL){
			aux = BuscarPosPalabra(nodo->izq, palabra);
		}
		else{
			if(BuscarPosPalabra(nodo->der, palabra) != NULL){
				aux = BuscarPosPalabra(nodo->der, palabra);
			}
		}*/
		if(strcmp(palabra, nodo->dato.p) > 0)
		{
			aux = aux = BuscarPosPalabra(nodo->der, palabra);
		}
		else{
			aux = BuscarPosPalabra(nodo->izq, palabra);
		}
	}
	ultimabusqueda++;
	return aux;
}
/***************************************************************************************
								OPERACIONES DE CONSULTA
***************************************************************************************/
// Retorna si el �rbol est� vac�o.
bool Empty(abb *a)
{
    bool vacio = false;
	if (a->raiz == NULL)
    {
        vacio = true;
    }
    return vacio;
}
// Retorna si la posici�n es v�lida
bool NullNode(abb *a, posicion p)
{
	bool nulo = true;
	if (p != NULL)
    {
        if(BuscarPosicion(Root(a), p) == true)
        {
        	nulo = false;
        }
    }
    printf("\n\n%d",nulo);
    return nulo;
}

bool BuscarPosicion(posicion nodo, posicion p)
{
	bool validar = false;
	bool izquierda = false;
	bool derecha = false;
	if(nodo == NULL){
		
	}
	else if(nodo == p){
		validar = true;
	}
	else{
		izquierda = BuscarPosicion(nodo->izq, p);
		if (izquierda){
			validar = true;
		}
		else{
			derecha = BuscarPosicion(nodo->der, p);
			if (derecha){
				validar = true;
			}
		}
	}
	return validar;
}
// Retorna el n�mero de elementos en el ABB.
int Size(abb *a)
{
    return a->tam;
}
// Recibe un ABB y una posici�n p, regresa el elemento en dicha posici�n.
elemento Element(abb *a, posicion p)
{
	return p->dato;
}
/***************************************************************************************
							    OPERACIONES DE MODIFICACI�N
***************************************************************************************/
// Inserta un elemento en el �rbol
void Add(abb *a, elemento e)
{
    if(Search(a, e) != NULL)
    {
    	printf("\n YA EXISTE LA PALABRA");
    	return;
	}
	bool EsDerecho;
    posicion nuevo;
    posicion aux = a->raiz;
    posicion aux2 = NULL;
	printf("\n Palabra: %s\tDefinicion: %s", e.p, e.d);
    nuevo = (posicion)malloc(sizeof(struct nodoBin));
    nuevo->padre = NULL;
	nuevo->izq = NULL;
    nuevo->der = NULL;
    nuevo->dato = e;
	if (Empty(a) == true)
    {
    	a->raiz = nuevo;
	}
	else
	{
		while(aux != NULL)
		{
			aux2 = aux;	
			if(strcmp(e.p, aux->dato.p) > 0)
			{
				EsDerecho = true;
				aux = aux->der;
				//printf("\n ES DERECHO");
			}
			else
			{
				EsDerecho = false;
				aux = aux->izq;
				//printf("\n ES IZQUIERDO");
			}
		}
		if(EsDerecho)
		{
			aux2->der = nuevo;
		}
		else
		{
			aux2->izq = nuevo;
		}
		nuevo->padre = aux2;
	}
	a->tam++;
}
