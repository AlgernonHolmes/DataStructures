#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

/*-----------------------------------------------*/
/*------------- estructura de datos -------------*/
/*-----------------------------------------------*/
typedef struct TDAtablaHashAbierto{
  int capacidad;
  TDAlista* * arreglo;
}TDAHashAbierto;
/*-----------------------------------------------*/
/*-----------------------------------------------*/


/*-----------------------------------------------*/
/*----------------- operaciones -----------------*/
/*-----------------------------------------------*/

//nombre funcion: crearTablaVacia
//dominio: int
//recorrido: TDAHashAbierto*
//definicion: funcion que crea una tabla hash de la capacidad dada

TDAHashAbierto* crearTablaVacia(int capacidad){
	TDAHashAbierto* tabla = (TDAHashAbierto*)malloc(sizeof(TDAHashAbierto));
	tabla->capacidad = capacidad;
	tabla->arreglo = (TDAlista* *)malloc(sizeof(TDAlista*) * capacidad);
	for(int i = 0; i< capacidad; i++){
		TDAlista* lista = crearListaVacia();
		tabla->arreglo[i] = lista;
	}
	return(tabla);
}


//nombre funcion: funcionHash
//dominio: TDAHasAbierto*, int
//recorrido: int
//definicion: funcion que mapea un valor a un espacio de la tabla hash

int funcionHash(TDAHashAbierto* tabla, int x){

	int valor = (((x*2) + (x/40))*(x)+10)%(tabla->capacidad);
	return(valor);
}

//nombre funcion: insertarHashAbierto
//dominio: TDAHashAbierto*, int, int
//recorrido: void
//definicion: funcion que inserta un dato en la tabla hash

void insertarHashAbierto(TDAHashAbierto* tabla, int llave, int dato){

	int index = funcionHash(tabla, llave);
	int veri = index;
	insertarInicio(tabla->arreglo[index],dato);
}


//nombre funcion: buscarHashAbierto
//dominio: TDAHashAbierto*, int, int
//recorrido: int
//definicion: funcion que busca un dato en la tabla hash

int buscarHashAbierto(TDAHashAbierto* tabla, int llave, int dato){

	int index = funcionHash(tabla, llave);
	int veri = index;
	return buscarDato(tabla->arreglo[index], dato);
}

//nombre funcion: eliminarHashAbierto
//dominio: TDAHashAbierto*, int, int
//recorrido: vacio
//definicion: funcion que elimina un dato de la tabla hash

void eliminarHashAbierto(TDAHashAbierto* tabla, int llave, int dato){

	int index = funcionHash(tabla, llave);
	int veri = index;
	eliminarDato(tabla->arreglo[index], dato);

}


//nombre funcion: mostrarTablaHashAbierto
//dominio: TDAHashAbierto
//recorrido: vacio
//definicion: funcion que muestra el contenido de una tabla hash

void mostrarTablaHashAbierto(TDAHashAbierto* tabla){

	printf("\nLa tabla Hash contiene los siguientes datos: \n");
	for(int i = 0; i< tabla->capacidad; i++){
		printf("----------------------------\n");
		printf("index: %d - contenido: ", i+1);
		recorrerLista(tabla->arreglo[i]);
	}
	printf("----------------------------\n");
}
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/

















