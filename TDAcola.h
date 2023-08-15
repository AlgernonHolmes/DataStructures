#include <stdio.h>
#include <stdlib.h>


/* ------- definicion TDA cola ------- */

/* se define el struct TDAcola con una direccion de memoria
   al valor del inicio y al valor del final*/

typedef struct cola{
	nodo* inicio;
	nodo* ultimo;
}TDAcola;


/* ------- definicion funciones TDA cola ------- */


//nombre funcion: liberarNodo
//dominio: nodo*
//recorrido: vacio
//descripcion: funcion que recibe un nodo y libera su espacio de memoria

void liberarNodo(nodo* nodo){
	nodo->siguiente = NULL;
	free(nodo);
}

//nombre funcion: crearColaVacia
//dominio: vacio
//recorrido: TDAcola*
//descripcion: funcion que crea una cola vacia

TDAcola* crearColaVacia(){
	TDAcola* cola = (TDAcola*)malloc(sizeof(TDAcola));
	cola->inicio = NULL;
	cola->ultimo = NULL;
	return(cola);
}


//nombre funcion: esColaVacia
//dominio: TDAcola* 
//recorrido: int
//descripcion: funcion que recibe una cola y retorna 1 si esta es vacia, de lo contrario, retorna 0

int esColaVacia(TDAcola* cola){

	int valor = 1;
	if(cola->inicio == NULL){
		return(valor);
	}
	else{
		valor = 0;
		return(valor);
	}
}


//nombre funcion: encolar
//dominio: TDAcola*, int
//recorrido: vacio
//descripcion: funcion que recibe un dato y una cola y encola el dato, o sea, lo pone al final

void encolar(TDAcola* cola, int dato){
	nodo* nod = (nodo*)malloc(sizeof(nodo));
	nod->dato = dato;
	if(cola->inicio == NULL){
		cola->inicio = nod;
		cola->ultimo = nod;
	}
	else{
		cola->ultimo->siguiente = nod;
		cola->ultimo = nod;
	}
}


//nombre funcion: frente
//dominio: TDAcola*
//recorrido: nodo*
//descripcion: funcion que recibe una cola y retorna el nodo del primer valor

nodo* frente(TDAcola* cola){

	nodo* nod = (nodo*)malloc(sizeof(nodo));
	if(cola->inicio){
		nod = cola->inicio;
		//printf("\nSe retorno el nodo con valor %d\n", nod->dato);
		return(nod);
	}
	else{
		printf("\nNo se pude devolver elemento, no existe\n");
		return(NULL);
	}
}

//nombre funcion: final
//dominio: TDAcola*
//recorrido: nodo*
//descripcion: funcion que recibe una cola y retorna el nodo final

nodo* final(TDAcola* cola){

	nodo* nod = (nodo*)malloc(sizeof(nodo));
	if(cola->ultimo){
		nod = cola->ultimo;
		printf("\nSe retorno el nodo con valor %d\n", nod->dato);
		return(nod);
	}
	else{
		printf("\nNo se pude devolver elemento, no existe\n");
		return(NULL);
	}
}


//nombre funcion: descolar
//dominio: TDAcola*
//recorrido: vacio
//descripcion: funcion que recibe una cola y elimina el primer valor

void descolar(TDAcola* cola){

	if(cola->inicio){
		nodo* borrar = cola->inicio;
		cola->inicio = cola->inicio->siguiente;
		liberarNodo(borrar);
	}
	else{
		cola->ultimo = NULL;
		printf("\nNo contiene elementos\n");
	}

}


/*

el trozo de codigo que sigue fue utilizado con fines de prueba en un
archivo .c para probar las funcionalidades detalladas con anterioridad

int main() 
{

	TDAcola* cola = crearColaVacia();
	encolar(cola, 2);
	encolar(cola, 1);
	encolar(cola, 3);
	nodo* nod = frente(cola);
	descolar(cola);
	nodo* nodo = frente(cola);

	return 0;
}*/
