#include <stdio.h>
#include <stdlib.h>
#include "TDAtablaHashAbierto.h"

/*-----------------------------------------------*/
/*----------- prueba de TDAHashAbierto ----------*/
/*-----------------------------------------------*/

int main(){

    //Creacion de una tabla hash;
    TDAHashAbierto* hashTable = crearTablaVacia(5);
    //Insertar datos en tabla hash;
    insertarHashAbierto(hashTable, 10, 1);
    insertarHashAbierto(hashTable, 5, 2);
    insertarHashAbierto(hashTable, 7, 3);
    insertarHashAbierto(hashTable, 2, 4);
    insertarHashAbierto(hashTable, 3, 5);
    insertarHashAbierto(hashTable, 4, 6);
    insertarHashAbierto(hashTable, 5, 7);
    //Mostrar tabla hash;
    mostrarTablaHashAbierto(hashTable);
    //Comprobar si un dato existe en la tabla con su llave;
    int valor = buscarHashAbierto(hashTable, 3, 5);
    if(valor != 0){
        printf("el dato fue hallado\n");
        }
    else{printf("el dato no se encuentra\n");}
    //Eliminar un dato de la tabla hash con su llave;
    printf("\nel dato a eliminar es el 3, que utiliza la llave 7\n");
    eliminarHashAbierto(hashTable, 7, 3);
    //Mostrar la nueva tabla hash;
    mostrarTablaHashAbierto(hashTable);
    return 0;
}