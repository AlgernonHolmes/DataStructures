#include <stdio.h>
#include <stdlib.h>
#include "TDAgrafo.h"

/*-----------------------------------------------*/
/*------------- prueba de TDAgrafo --------------*/
/*-----------------------------------------------*/


int main() 
{

	TDAgrafo* grafo;
	//Lectura del grafo no ponderado;
	grafo=leerGrafoNoDirigido("grafo.in");
	printf("Matriz de adyacencia: \n");
	//Se muestra la matriz de adyacencia;
	imprimirMatrizAdyacencia(grafo);
	printf("----------\n");
	//Prueba de funcion de adyacencia de nodos;
	int vertA = 1;
	int vertB = 3;
	if(adyacenciaNodos(grafo,vertA,vertB) == 1){
	 	printf("Los vertices %d y %d son adyacentes\n", vertA, vertB);
	}
	else {
	  	printf("Los vertices %d y %d no son adyacentes\n", vertA, vertB);
	}
	//Prueba de funcion esCamino;
	TDAlista* lista = obtenerAdyacentes(grafo, vertA);
	int valor = 1;
	TDAlista* secuencia = crearListaVacia();
	while(valor != 0){
		int revisar;
		printf("\nEscriba un valor para la secuencia: ");
		scanf("%d",&revisar);
		insertarInicio(secuencia, revisar);
		printf("\nDesea escribir otro valor? (si(1)/no(0)): ");
		scanf("%d",&valor);
	}
	int pseudoBul = EsCamino(grafo, secuencia);
	printf("\nEl resultado del procedimiento EsCamino es: %d", pseudoBul);
	//recorrerLista(lista);
	return 0;
}





