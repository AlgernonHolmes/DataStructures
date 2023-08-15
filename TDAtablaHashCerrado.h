#include <stdio.h>
#include <stdlib.h>


/*-----------------------------------------------*/
/*------------- estructura de datos -------------*/
/*-----------------------------------------------*/
typedef struct TDAtablaHashCerrado{
  int capacidad;
  int* arreglo;
}TDAHashCerrado;
/*-----------------------------------------------*/
/*-----------------------------------------------*/


/*-----------------------------------------------*/
/*----------------- operaciones -----------------*/
/*-----------------------------------------------*/

//nombre funcion: crearTablaVacia
//dominio: int
//recorrido: TDAHashCerrado*
//definicion: funcion que crea una tabla hash de la capacidad dada

TDAHashCerrado* crearTablaVacia(int capacidad){
	int i = 0;
	TDAHashCerrado* tabla = (TDAHashCerrado*)malloc(sizeof(TDAHashCerrado));
	tabla->capacidad = capacidad;
	tabla->arreglo = (int*)malloc(sizeof(int) * capacidad);
	while(i <= capacidad){tabla->arreglo[i] = 99999;i++;}
	return(tabla);
}

//nombre funcion: funcionHash
//dominio: TDAHasCerrado*, int
//recorrido: int
//definicion: funcion que mapea un valor a un espacio de la tabla hash

int funcionHash(TDAHashCerrado* tabla, int x){

	int valor = (((x*2) + (x/40))*(x)+10)%(tabla->capacidad);
	return(valor);
}

//nombre funcion: insertarHashCerrado
//dominio: TDAHashCerrado*, int, int
//recorrido: void
//definicion: funcion que inserta un dato en la tabla hash

void insertarHashCerrado(TDAHashCerrado* tabla, int llave, int dato){

	int index = funcionHash(tabla, llave);
	int veri = index;
	if(tabla->arreglo[index] == 99999){
		tabla->arreglo[index] = dato;
	}
	else{
		while(index<tabla->capacidad && tabla->arreglo[index] != 99999){
			index = index + 1;
		}
		if(index == tabla->capacidad && tabla->arreglo[index] != 99999){
			index = 0;
		}
		if(tabla->arreglo[index] != 99999){
			while(index<veri && tabla->arreglo[index] != 99999){
				index = index + 1;
			}
			if(index == veri && tabla->arreglo[index] != 99999){
				printf("\nNo hay espacio para almacenar el dato\n");
			}
		}
	}	
}

//nombre funcion: buscarHashCerrado
//dominio: TDAHashCerrado*, int, int
//recorrido: void
//definicion: funcion que busca un dato en la tabla hash

void buscarHashCerrado(TDAHashCerrado* tabla, int llave, int dato){

	int index = funcionHash(tabla, llave);
	int veri = index;
	while(index<tabla->capacidad && tabla->arreglo[index] != dato){
		index = index + 1;
	}
	if(index == tabla->capacidad){
		index = 0;
	}
	while(index<veri && tabla->arreglo[index] != dato){
		index = index + 1;
	}
	if(tabla->arreglo[index] == dato){
		printf("\nEl dato buscado es %d y esta en la posicion %d\n", tabla->arreglo[index], index);
	}
	else{
		printf("\nNo se encontro el dato\n");
	}
}

//nombre funcion: eliminarHashCerrado
//dominio: TDAHashCerrado*, int
//recorrido: void
//definicion: funcion que elimina un dato en la tabla hash

void eliminarHashCerrado(TDAHashCerrado* tabla, int dato){

	for(int i = 0; i<tabla->capacidad;i++){
		if(tabla->arreglo[i] == dato){
			tabla->arreglo[i] = 99999;
		}
	}
	
}

//nombre funcion: mostrarHashCerrado
//dominio: TDAHashCerrado*
//recorrido: void
//definicion: funcion que muestra los contenidos de la tabla hash

void mostrarTablaHashCerrado(TDAHashCerrado* tabla){

	printf("\nLa tabla Hash contiene los siguientes datos: \n");
	printf("----------------------------\n");
	for(int i = 0; i< tabla->capacidad; i++){
		if(tabla->arreglo[i] != 99999){
			printf("{index: %d - dato: %d}\n", i+1, tabla->arreglo[i]);
			}
		else{printf("{index: %d - dato: -}\n", i+1);}
	}
	printf("----------------------------\n");
}
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/