#include <stdio.h>
#include <stdlib.h>

/*-----------------------------------------------*/
/*------------- estructura de datos -------------*/
/*-----------------------------------------------*/
typedef struct nodoGenerico{
	int dato;
  	struct nodoGenerico* siguiente;
}nodo;

typedef struct listaGenerica{
	 nodo* inicio;
}TDAlista;
/*-----------------------------------------------*/
/*-----------------------------------------------*/


/*-----------------------------------------------*/
/*----------------- operaciones -----------------*/
/*-----------------------------------------------*/

//nombre funcion: crearListaVacia
//dominio: vacio
//recorrido: TDAlista*
//definicion: funcion que crea una lista vacia

TDAlista* crearListaVacia()
{
  TDAlista* lista=(TDAlista*)malloc(sizeof(TDAlista));
  lista->inicio=NULL;
  return lista;
}

//nombre funcion: esListaVacia
//dominio: TDAlista*
//recorrido: int
//definicion: funcion que retorna un 1 si la lista esta vacia, de lo contrario, retorna 0

int esListaVacia(TDAlista* lista)
{
  if (lista->inicio == NULL){
    return 1;}
	
  else{
    return 0;
  }
	
}

//nombre funcion: recorrerLista
//dominio: TDAlista*
//recorrido: vacio
//definicion: funcion que recorre la lista

void recorrerLista(TDAlista* lista)
{
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      printf("%d ",auxiliar->dato);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista esta vacia\n");
}


//nombre funcion: insertarInicio
//dominio: TDAlista*, int
//recorrido: vacio
//definicion: funcion que inserta un dato al inicio de la lista

void insertarInicio(TDAlista* lista, int dato)
{
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=dato;
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}


//nombre funcion: eliminarInicio
//dominio: TDAlista*
//recorrido: vacio
//definicion: funcion que elimina el dato al inicio de la lista

void eliminarInicio(TDAlista* lista)
{
  nodo* auxiliar;
  if(!esListaVacia(lista))
  {
    auxiliar=lista->inicio;
    lista->inicio=lista->inicio->siguiente;
    free(auxiliar);
  }
}


//nombre funcion: liberarLista
//dominio: TDAlista*
//recorrido: vacio
//definicion: funcion que libera la lista creada

void liberarLista(TDAlista* lista){
	while(!esListaVacia (lista)){
		eliminarInicio(lista);
	//free(lista); 
	}
}

//nombre funcion: buscarDato
//dominio: TDAlista*, int
//recorrido: int
//definicion: funcion que busca un dato dentro de la lista, retorna 1 si el dato existe en la lista, de lo contrario, retorna 0

int buscarDato(TDAlista* lista, int dato){
	//RETORNA 0 SI EL DATO NO EXISTE EN LA LISTA, 1 SI EL DATO EXISTE EN LA LISTA;
	int existencia = 0;
	if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      //printf("%d ",auxiliar->dato);
      if(auxiliar->dato == dato){
      	existencia = 1;
	  }
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista esta vacia\n");
	return existencia;
}


//nombre funcion: obtenerNumeroNodos
//dominio: TDAlista*
//recorrido: int
//definicion: funcion que cuenta y retorna el numero total de nodos en la lista

int obtenerNumeroNodos(TDAlista* lista){
	int numNodos = 0;
	if(!esListaVacia(lista)){
		nodo* auxiliar = lista->inicio;
		while(auxiliar != NULL){
			numNodos = numNodos + 1;
			auxiliar=auxiliar->siguiente;
		}
	}
	else{
		printf("\nLa lista esta vacia");
	}
	return numNodos;	
}

//nombre funcion: insertarNodoFinal
//dominio: TDAlista*, int
//recorrido: vacio
//definicion: funcion que inserta un nodo con el dato al final de la lista

void insertarNodoFinal(TDAlista* lista, int dato){
	if(!esListaVacia(lista)){
		nodo* nuevo = (nodo*)malloc(sizeof(nodo));
        nuevo->dato=dato;
        nuevo->siguiente = NULL;
        nodo* final = lista->inicio;
        while (final->siguiente!=NULL){
        	final = final->siguiente;
    	}
        final->siguiente=nuevo;
 	}	
}


//nombre funcion: insertarNodoDespues
//dominio: TDAlista*, int, int
//recorrido: vacio
//definicion: funcion que inserta un nodo con un nuevo dato despues del dato dado por el usario

void insertarNodoDespues(TDAlista* lista, int dato, int datoAnterior){
	if(!esListaVacia(lista)){
		nodo* auxiliar = lista->inicio;
		while(auxiliar->dato != datoAnterior){
			auxiliar = auxiliar->siguiente;
		}
		nodo* nuevo = (nodo*)malloc(sizeof(nodo));
		nuevo->dato = dato;
		nuevo->siguiente = auxiliar->siguiente;
		auxiliar->siguiente = nuevo;
	}
	
}


//nombre funcion: eliminarFinal
//dominio: TDAlista*
//recorrido: vacio
//definicion: funcion que elimina el nodo del final de la lista

void eliminarFinal(TDAlista* lista){
	if(!esListaVacia(lista)){
		nodo* anterior = NULL;
		nodo* auxiliar = lista->inicio;
		while(auxiliar->siguiente != NULL){
			anterior = auxiliar; 
			auxiliar = auxiliar->siguiente;
		}
		anterior->siguiente = NULL;
		free(auxiliar);
	}
}


//nombre funcion: eliminarDato
//dominio: TDAlista*, int
//recorrido: vacio
//definicion: funcion que elimina un dato de un nodo

void eliminarDato(TDAlista* lista, int dato){
	if(!esListaVacia(lista)){
		nodo* anterior = NULL;
		nodo* auxiliar = lista->inicio;
		while(auxiliar->dato != dato){
			anterior = auxiliar; 
			auxiliar = auxiliar->siguiente;
		}
		anterior->siguiente = auxiliar->siguiente;
		free(auxiliar);
	}

}


//nombre funcion: obtenerNodo
//dominio: TDAlista*, int
//recorrido: nodo*
//definicion: funcion que retorna el valor del nodo en la posicion dada

nodo* obtenerNodo(TDAlista* lista, int posicion){
	if(!esListaVacia(lista)){
		if(posicion <= obtenerNumeroNodos(lista)){
			nodo* auxiliar = lista->inicio;
			int forward = 1;
			while(forward != posicion){
				auxiliar = auxiliar->siguiente;
				forward = forward + 1;
		}
		return(auxiliar);	
		}
		else{
			printf("\nLo siento, esto excede el numero de nodos en la lista");
			nodo* neo;
			neo->dato = 999999;
			//Se retorna numero como valor invalido para el nodo;
			return(neo);
		}
		
	}
	
}
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/














