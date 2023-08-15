#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

/*-----------------------------------------------*/
/*------------- prueba de TDAlista --------------*/
/*-----------------------------------------------*/

int main(){

    //Creacion de la lista;
    TDAlista* lista = crearListaVacia();
    //Revision de lista;
    esListaVacia(lista);
    //Insercion de datos;
    insertarInicio(lista, 1);
    insertarInicio(lista, 2);
    insertarInicio(lista, 3);
    insertarInicio(lista, 4);
    insertarInicio(lista, 5);
    insertarInicio(lista, 6);
    insertarInicio(lista, 7);
    //Recorrer la lista;
    recorrerLista(lista);
    //Eliminacion de elementos al principio
    eliminarInicio(lista);
    eliminarInicio(lista);
    eliminarInicio(lista);
    eliminarInicio(lista);
    //Recorrer nueva lista;
    recorrerLista(lista);
    //Buscar un dato en la lista;
    int validez = buscarDato(lista, 5);
    printf("se esta buscando el valor 5, el resultado de la busqueda es: %d\n", validez);
    //Obtener el numero de nodos;
    int nods = obtenerNumeroNodos(lista);
    printf("\nel numero de nodos en la lista es %d\n\n", nods);
    //Insertar nodo al final;
    insertarNodoFinal(lista, 5);
    //Recorrer la nueva lista;
    recorrerLista(lista);
    //Insertar un nodo despues del dato x;
    insertarNodoDespues(lista, 6, 2);
    //Recorrer nueva lista;
    recorrerLista(lista);
    //Eliminar nodo al final;
    eliminarFinal(lista);
    //Recorrer nueva lista;
    recorrerLista(lista);
    //Eliminar un dato de la lista;
    eliminarDato(lista, 2);
    //Recorrer nueva lista;
    recorrerLista(lista);
    //Obtener el nodo de la posicion n;
    nodo* newNodo = obtenerNodo(lista, 4);
    if(newNodo->dato != 999999){
        printf("\nel valor del nodo obtenido es: %d\n", newNodo->dato);
    }
    return 0;
}