#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
#include "TDApila.h"


/*-----------------------------------------------*/
/*------------- estructura de datos -------------*/
/*-----------------------------------------------*/
typedef struct matrizGrafo 
{
	int cvertices;
	int** adyacencias;
}TDAgrafo;
/*-----------------------------------------------*/
/*-----------------------------------------------*/

/*-----------------------------------------------*/
/*----------------- operaciones -----------------*/
/*-----------------------------------------------*/

//nombre funcion: crearGrafoVacio
//dominio: int
//recorrido: TDAgrafo*
//descripcion: funcion que crea un grafo vacio a partir de un numero de vertices

TDAgrafo* crearGrafoVacio(int vertices) 
{
	TDAgrafo* grafo = (TDAgrafo*)malloc(sizeof(TDAgrafo));
	grafo->cvertices = vertices;
	grafo->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i,j;
	for (i = 0; i < vertices; i++) 
	{
		grafo->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j=0;j<vertices;j++){
			grafo->adyacencias[i][j] = 0;
		}	
	}
	return grafo;
}


//nombre funcion: imprimirMatrizAdyacencia
//dominio: TDAgrafo*
//recorrido: vacio
//descripcion: funcion que muestra por pantalla la matriz de adyacencia

void imprimirMatrizAdyacencia(TDAgrafo* grafo) 
{
	int i, j;
	
	for (i = 0; i < grafo->cvertices; i++) 
	{
		for (j = 0; j < grafo->cvertices; j++) 
		{
			printf("%d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

//nombre funcion: adyacenciaNodos
//dominio: TDAgrafo*, int, int
//recorrido: int
//descripcion: funcion que comprueba en la matriz que dos nodos sean adyacentes

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB) 
{
	if (grafo->adyacencias[vertA - 1][vertB - 1] == 1) 
	{
		return 1;
	}
	return 0;
}

//nombre funcion: leerGrafoNoDirigido (no ponderado)
//dominio: char*
//recorrido: TDAgrafo*
//descripcion: funcion que lee un archivo que contiene la matriz de adyacencia de un grafo

TDAgrafo* leerGrafoNoDirigido(char *nombreArchivo){
	FILE*pf;		   //para abrir archivo
	pf = fopen(nombreArchivo,"r");
	int n_vertices, m_aristas;
	int i,j,k;
	if (pf ==NULL){
		printf("Error de archivo\n");
		return NULL;
	}else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		TDAgrafo *G=crearGrafoVacio(n_vertices);	
		//dependiendo de las lineas de archivo, 
		// 1 para grafo no dirigido no ponderado
		for(k=0;k<m_aristas;k++){
			fscanf(pf,"%d %d",&i, &j);
			G->adyacencias[i-1][j-1] = 1;
			G->adyacencias[j-1][i-1] = 1;
		}
		fclose(pf);
		return  G;	
	}
}

//nombre funcion: obtenerAdyacentes
//dominio: TDAgrafo*, int
//recorrido: TDAlista*
//descripcion: funcion que comprueba y guarda los nodos que son adyacentes en una lista enlazada

TDAlista* obtenerAdyacentes(TDAgrafo* grafo, int vertice){

	TDAlista* lista = crearListaVacia();
	int totalVertices = grafo->cvertices;
	for(int i = 0; i<totalVertices; i++){
		if(adyacenciaNodos(grafo,vertice,i+1) == 1){
			insertarInicio(lista,i+1);
		}
	}
	return(lista);
}

//nombre funcion: EsCamino
//dominio: TDAgrafo*, TDAlista*
//recorrido: int
//descripcion: funcion que recibe un grafo y una lista con una secuencia y comprueba que
//los nodos dados sean adyacentes, o sea, que haya camino o lineas que los unan

int EsCamino( TDAgrafo* grafo, TDAlista* secuencia){
	nodo* aux = secuencia->inicio;
	int valor = 0;
	while(aux->siguiente != NULL){
		if(adyacenciaNodos(grafo, aux->dato, aux->siguiente->dato) == 1){
			valor = 1;
		}
		aux = aux->siguiente;
	}
	return(valor);
}

//nombre funcion: EsCiclo
//dominio: TDAgrafo*, TDAlista*
//recorrido: int
//descripcion: funcion que comprueba si la secuencia dada por usuario corresponde a un ciclo

int EsCiclo( TDAgrafo* grafo, TDAlista* secuencia){
	nodo* aux = secuencia->inicio;
	nodo* aux2 = secuencia->inicio;
	int valor = 1;
	while(aux->siguiente != NULL){
		aux = aux->siguiente;
	}
	if(aux->dato != aux2->dato){
		valor = 0;
	}
	return(valor);
}

//nombre funcion: leerGrafoNoDirigido (ponderado)
//dominio: char*
//recorrido: TDAgrafo*
//descripcion: funcion que lee un archivo que contiene la matriz de adyacencia de un grafo
TDAgrafo* leerGrafoNoDirigidoPonderado(char *nombreArchivo){
	FILE*pf;		   //para abrir archivo
	pf = fopen(nombreArchivo,"r");
	int n_vertices, m_aristas;
	int i,j,w,k;
	if (pf ==NULL){
		printf("Error de archivo\n");
		return NULL;
	}else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		TDAgrafo *G=crearGrafoVacio(n_vertices);	
		//dependiendo de las lineas de archivo, 
		// 1 para grafo no dirigido no ponderado
		for(k=0;k<m_aristas;k++){
			fscanf(pf,"%d %d %d",&i, &j,&w);
			G->adyacencias[i-1][j-1] = w;
			G->adyacencias[j-1][i-1] = w;
		}
		fclose(pf);
		return  G;	
	}
}
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/
/*-----------------------------------------------*/

