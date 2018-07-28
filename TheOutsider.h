/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE 1024

/* Definiciniones */

typedef uint32_t u32; /* Definición de tipo u32 */
typedef struct _Vertice_t *PVertice;
typedef struct _Grafo_t *Grafo;

/* Definición de Estructura Vertice */
struct _Vertice_t {
    u32 nombre; /* Nombre real del vértice */
    u32 grado; /* Grado del vértice */
    u32 color; /* Color del vértice  */
    u32 index; /* Indice */
		u32 mem_vecinos;
		u32 tag;
		bool visitado;/*variable para saber el numero de componentes conexas*/
		u32 x_aleatorio;/* u32 para uso exclusivo en funcion orden aleatorio */
		u32 aleatorio; /* u32 para uso exclusivo en funcion orden aleatorio */
    u32 cant_de_colores; //uso exclusivo para orden bloque  == 1
    PVertice *vecinos; /* Vecinos del vértice */
};

/* Definición de Estructura Grafo */
struct _Grafo_t {
    u32 nro_vertices; /* Cantidad de vértices del Grafo */
    u32 nro_lados; /* Cantidad de lados del Grafo */
    u32 nro_colores; /* Cantidad de colores usados para colorear el Grafo */
    PVertice vertices; /* Arreglo de Vértices del Grafo */
		bool *facil_busqueda;
    PVertice *orden; /* Arreglo indicador del orden de los vértices del Grafo*/
};

/* Tipo Abstracto de Datos QUEUE, utilizado para el algoritmo Bipartito tal como se vio en clase */

typedef struct _Queue_t *Queue;

struct _Queue_t {
	u32 head;
	u32 tail;
	PVertice *theQueue;
};

/* FUNCIONES */

/* Funciones deL TAD Cola */
/*----------------------------------------------------------------------------------------------------*/
void DestruirQueue(Queue q);
void Enqueue(Queue q, PVertice v);
PVertice Dequeue(Queue q);
u32 isEmpty(Queue q);
/*----------------------------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------------------------*/
/* Funciones Auxiliares de Carga del Grafo */
/*----------------------------------------------------------------------------------------------------*/
PVertice BuscoOAgregoVert(Grafo g,u32 v_nombre);
void NuevoVecino(PVertice vert_u, PVertice vert_v);
/*----------------------------------------------------------------------------------------------------*/


/* Funciones de Carga y Destrucción del Grafo */
/*----------------------------------------------------------------------------------------------------*/
Grafo ConstruccionDelGrafo(); /* Alloca memoria para un Nuevo Grado leido por entrada estándar */
void DestruccionDelGrafo(Grafo G); /* Destruye G y libera la memoria alocada */
/*----------------------------------------------------------------------------------------------------*/


/* Funciones de Información del Grafo */
/*----------------------------------------------------------------------------------------------------*/
u32 NumeroDeVertices(Grafo G); /* Retorna el número de Vértices del grafo G */
u32 NumeroDeLados(Grafo G); /* Retorna el número de lados del grafo G */
u32 NumeroDeColores(Grafo G); /* Retorna el número de colores del grafo G */
/*----------------------------------------------------------------------------------------------------*/


/* Funciones de Información del Vértice */
/*----------------------------------------------------------------------------------------------------*/
u32 NombreDelVertice(Grafo G, u32 i); /* Devuelve el nombre real del vértice número i en el orden guardado en ese momento en G */
u32 ColorDelVertice(Grafo G, u32 i); /* Devuelve el color con el que está coloreado el vértice número i en el orden guardado en ese momento en G */
u32 GradoDelVertice(Grafo G, u32 i); /* Devuelve el grado del vértice número i en el orden guardado en ese momento en G */
u32 ColorJotaesimoVecino(Grafo G, u32 i,u32 j); /* Devuelve el color del vecino numero j del vértice número i en el orden guardado en ese momento en G */
u32 NombreJotaesimoVecino(Grafo G, u32 i,u32 j); /*Devuelve el nombre del vecino numero j del vértice número i en el orden guardado en ese momento en G */
u32 GradoJotaesimoVecino (Grafo G, u32 i, u32 j); /* Devuelve el grado del vecino numero j del vértice número i en el orden guardado en ese momento en G */
u32 NumeroDeVerticesDeColor(Grafo G, u32 i); /* Devuelve la cantidad de veces que un color fue usado*/
/*----------------------------------------------------------------------------------------------------*/


/* Funciones de Ordenación */
/*----------------------------------------------------------------------------------------------------*/
void OrdenNatural(Grafo G); /* Ordena los vértices en orden creciente de sus “nombres” reales */
void OrdenWelshPowell(Grafo G); /* Ordena los vértices de G de acuerdo con el orden Welsh-Powell */
void AleatorizarVertices(Grafo G,u32 semilla); /* Esta función ordena pseudoaleatoriamente los vértices de G, usando alguna función pseudoaleatoria que dependa determinísticamente de semilla. */
void ReordenManteniendoBloqueColores(Grafo G,u32 x);
/*ReordenManteniendoBloqueColores

• Si x=0, entonces j1=r,j2=r−1,...,jr−1=2,jr=1.

• Si x=1, entonces j1,j2,...son tales que|VCj1|≤|VCj2|≤...≤|VCjr|

• Si x>1, entonces se usa alguna función de pseudoaleatoriedad que dependa determinísticamente de x
para generar un orden aleatorio de los números {1, 2, ..., r}, obteniendo un orden j1, j2, ..., jr.*/
/*----------------------------------------------------------------------------------------------------*/


/* Funciones de Coloreo */
/*----------------------------------------------------------------------------------------------------*/
u32 mi_rand(u32 semilla);/*Funcion pseudoaleatoria*/
void DFS(Grafo G, u32 inicio);/* Funcion DFS para saber cantidad componentes_conexas */
u32 NotSoGreedy(Grafo G,u32 semilla); /* Corre la variación de greedy en G con el orden interno que debe estar guardado de alguna forma dentro de G. Devuelve el numero de colores que se obtiene. */
int Bipartito(Grafo G); /* Si k es el número de componentes conexas de G, devuelve k si G es bipartito, y −k si no */
/*----------------------------------------------------------------------------------------------------*/
