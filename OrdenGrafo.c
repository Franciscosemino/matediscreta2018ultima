		/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

int cmpfunc (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = (vertice_1->nombre > vertice_2->nombre) - (vertice_1->nombre < vertice_2->nombre);
	return resultado;
}

void OrdenNatural(Grafo G) {
    qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunc);
}

int cmpfuncgrado (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = ( vertice_2->grado )-(vertice_1->grado);
	return resultado;
}
void OrdenWelshPowell(Grafo G){
	qsort(G->orden,G->nro_vertices,sizeof(PVertice), cmpfuncgrado);
}

int cmpfunccolor (const void * a, const void * b) {
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
  int resultado = (vertice_2->color )-(vertice_1->color);
	return resultado;
}

int cmpfunccantcolor (const void * a, const void * b) {
  PVertice vertice_1 = *(PVertice*)a;
  PVertice vertice_2 = *(PVertice*)b;
  int resultado;
  if (vertice_1->cant_de_colores == vertice_2->cant_de_colores) {
    resultado = (vertice_2->color )-(vertice_1->color);
  } else {
    resultado = (vertice_1->cant_de_colores > vertice_2->cant_de_colores) - (vertice_1->cant_de_colores < vertice_2->cant_de_colores);
  }
  return resultado;
}

int cmpfuncaleat(const void * a, const void * b){
	PVertice vertice_1 = *(PVertice*)a;
	PVertice vertice_2 = *(PVertice*)b;
	return (vertice_1->x_aleatorio < vertice_2->x_aleatorio);
}

void AleatorizarVertices(Grafo G, u32 x) {
  u32 seed = x;
  for(u32 i = 0; i < G->nro_vertices; i++){
    seed = mi_rand(seed);
    G->vertices[i].x_aleatorio = seed;
  }
  qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfuncaleat);
}

void ReordenManteniendoBloqueColores(Grafo G,u32 x) {
    if (x == 0) {
        qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunccolor);
    } else if (x == 1) {
      if (G->nro_colores != G->nro_vertices) {
        u32 cant_cada_color[G->nro_colores+1];
        memset(cant_cada_color, 0, (G->nro_colores + 1)*sizeof(u32));
        for (u32 i = 0; i<G->nro_vertices; i++) {
          cant_cada_color[G->orden[i]->color] += 1;
        }
        for (u32 i = 0; i<G->nro_vertices; i++) {
          G->orden[i]->cant_de_colores = cant_cada_color[G->orden[i]->color];
        }
        qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfunccantcolor);
      }
    } else if (x > 1) {
      u32 seed = x;
			u32 array_rand[NumeroDeColores(G)];
			for(u32 i=0;i<NumeroDeColores(G);i++){
				array_rand[i]=0;
			}
			for(u32 i=1;i<=NumeroDeColores(G);i++){
				seed = mi_rand(seed);
				u32 j = seed%NumeroDeColores(G);
				bool exit=true;
				while(exit){
					if(array_rand[j]==0){
						array_rand[j]=i;
						exit = false;
					}else if(j!=(NumeroDeColores(G)-1)){
						j++;
					}else{
						j=0;
					}
				}
			}
			for(u32 i=0;i<NumeroDeColores(G);i++){
				u32 color = array_rand[i];
				for(u32 j = 0; j<NumeroDeVertices(G);j++){
					if(ColorDelVertice(G,j)==color){
						G->orden[j]->x_aleatorio=i;
					}
				}
			}
			qsort(G->orden, G->nro_vertices, sizeof(PVertice), cmpfuncaleat);

    }
}
