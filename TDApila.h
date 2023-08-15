#include <stdio.h>
#include <stdlib.h>

/*------------- estructura de datos -------------*/



typedef struct
{
  int capacidad;
  int size;
  nodo* tope;
}TDApila;

/*------------- operaciones -------------*/

/*------------- FUNCIONES PROPORCIONADAS EN EL LABORATORIO -------------*/
//nombre: crearPilaVacia
//dominio o entrada: un entero que representa la capacidad de la pila
//recorrido o salia: devuelve un TDApila de la capacidad indicada
//descripcion: esta funcion crea el recipiente para la pila con una cierta capacidad indicada que no se puede exceder

TDApila* crearPilaVacia(int capacidad)
{
  TDApila* pila=(TDApila*)malloc(sizeof(TDApila));
  pila->capacidad=capacidad;
  pila->size=0;
  pila->tope=NULL;
  return pila;
}


//nombre: esPilaVacia
//dominio o entrada: un TDApila
//recorrido o salia: devuelve un 1 o un 0 como valores de verdad
//descripcion: esta funcion pide un TDApila con el fin de revisar si contiene elementos; devuelve un 1 si esta vacia y un 0 si contiene elementos

int esPilaVacia(TDApila* pila)
{
  if (pila->size == 0)
    return 1;
  else
    return 0;
}


/*------------- Actividad 2 -------------*/

/*------------- FUNCIONES IMPLEMENTADAS POR ESTUDIANTE -------------*/

//nombre: apilar
//dominio o entrada: un TDApila y un dato entero
//recorrido o salia: no devuelve ningun elemento
//descripcion: esta funcion agrega un dato encima de la pila, agregando direcciones de memoria y nodos a la lista enlazada

void apilar(TDApila* pila, int dato){

  if(pila->size < pila->capacidad){
    nodo* nod = (nodo*)malloc(sizeof(nodo)); //se crea un nodo nuevo
    nod->dato = dato; //le asigno el dato a guardar
    nod->siguiente = pila->tope; //el nodo apunta a la pila
    pila->tope = nod; //el tope de la pila apunta al nodo
    pila->size = pila->size + 1; //como se agrega un dato, se muestra en la pila
    //printf("\nSe acaba de apilar el valor: %d", dato);

  }
  else{
    printf("\nNo es posible agregar mas elementos");
  }
}


//funcion de uso practico par visualizar la pila
//se uso como traza

//nombre: mostrarPila
//dominio o entrada: un TDApila
//recorrido o salia: no devuelve ningun elemento
//descripcion: esta funcion muestra los valores contenidos en la pila en orden

/*void mostrarPila(TDApila* pila){

  printf("\n");
  while(pila->tope != NULL){

    printf("%d",pila->tope->dato);
    pila->tope = pila->tope->siguiente;
    
  }
}*/ 


//nombre: desapilar
//dominio o entrada: un TDApila
//recorrido o salia: no devuelve ningun elemento
//descripcion: esta funcion borra de la memoria el primer elemento de la pila, desplazado las direcciones de memoria al proximo y liberando el espacio usado en la lista
//enlazada

void desapilar(TDApila* pila){
 
  if(esPilaVacia(pila) != 1){
    //printf("\nSe acaba de desapilar el valor: %d", pila->tope->dato);
    nodo* nodAux = (nodo*)malloc(sizeof(nodo));
    nodAux = pila->tope;
    pila->tope = pila->tope->siguiente;
    free(nodAux);
    pila->size = pila->size - 1;
  }
  else{
    printf("\nLa pila entregada esta vacia");
  }
  
}


//nombre: tope
//dominio o entrada: un TDApila
//recorrido o salia: devuelve una variable tipo nodo (especificado en el TDA)
//descripcion: esta funcion toma el primer elemento de la pila (el tope) y la devuelve como variable 

nodo* tope(TDApila* pila){

  nodo* nodAux = (nodo*)malloc(sizeof(nodo));
  nodAux->dato = pila->tope->dato;
  nodAux = pila->tope;
  return(nodAux);

}

/*------------- Actividad 4 -------------*/


/*------------- FUNCION IMPLEMENTADA POR ESTUDIANTE -------------*/

//nombre: buscarDatoPila
//dominio o entrada: un TDApila y un valor entero llamado dato
//recorrido o salia: devuelve un entero (un 0 o un 1)
//descripcion: esta funcion crea una pila auxiliar para apilar los valores mientras se va buscando el dato indicado. Una vez se encuentra
//se vuelven a apilar en el orden original todos los valores y se devuelve un 1 si se encontro el valor buscado o de lo contrario devuelve un 0 

int buscarDatoPila(TDApila* pila, int dato){

  TDApila* auxPila = crearPilaVacia(pila->capacidad);
  nodo* nodAux;
  int valor;
  int verificador = 0;
  while(pila != NULL){
    nodAux = tope(pila);
    valor = nodAux->dato;
    desapilar(pila);
    if(valor == dato){
      verificador = 1;
    }
    apilar(auxPila,valor);

  
  }
  while(auxPila->tope->siguiente != NULL){
    nodAux = tope(auxPila);
    valor = nodAux->dato;
    desapilar(auxPila);
    apilar(pila,valor);
  }
  
  return(verificador);
}




