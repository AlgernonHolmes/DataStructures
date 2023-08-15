#include <stdio.h>
#include <stdlib.h>
#include "TDAtablaHashCerrado.h"

/*-----------------------------------------------*/
/*----------- prueba de TDAHashCerrado ----------*/
/*-----------------------------------------------*/

int main(){

    //Creacion de una tabla hash;
    TDAHashCerrado* hashTable = crearTablaVacia(5);
    //Insertar datos en tabla hash;
    insertarHashCerrado(hashTable, 10, 1);
    insertarHashCerrado(hashTable, 5, 2);
    insertarHashCerrado(hashTable, 7, 3);
    insertarHashCerrado(hashTable, 2, 4);
    insertarHashCerrado(hashTable, 3, 5);
    insertarHashCerrado(hashTable, 4, 6);
    insertarHashCerrado(hashTable, 5, 7);
    //Mostrar tabla hash;
    mostrarTablaHashCerrado(hashTable);
    //Comprobar si un dato existe en la tabla con su llave;
    buscarHashCerrado(hashTable, 3, 5);
    //Eliminar un dato de la tabla hash con su llave;
    printf("\nel dato a eliminar es el 3\n");
    eliminarHashCerrado(hashTable, 3);
    //Mostrar la nueva tabla hash;
    mostrarTablaHashCerrado(hashTable);
    return 0;
}