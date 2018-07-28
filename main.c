/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

bool arrayIsSorted(PVertice *a, u32 n) {
  if ((n == 1) || (n == 0))
    return true;

  if (a[n-1]->nombre < a[n-2]->nombre) {
    printf("%u %u\n", a[n-1]->nombre, a[n-2]->nombre);
    return false;
  }

  return arrayIsSorted(a, n-1);
}

/* En nuestro caso sabemos que tienen el mismo largo */
bool arrayIsEqual(PVertice *a, PVertice *b, u32 n) {
  if ((n == 1) || (n == 0))
    return true;

  if (a[n]->nombre != b[n]->nombre)
    return false;

  return arrayIsEqual(a, b, n-1);
}

int main(){
		clock_t tiempo_inicio;
		clock_t tiempo_final;
		double segundos;
		double minutos;
		tiempo_inicio = clock();
		Grafo g = ConstruccionDelGrafo();
		printf("CARGUE EL GRAFO\n" );

		OrdenNatural(g);

    //bool b = arrayIsSorted(g->orden, g->nro_vertices);

  //  printf("ESTA ORDENADO?\n");
    //if (b) printf("SI\n");




/*		for (u32 i = 0 ; i< NumeroDeVertices(g);i++){
			printf("Soy el Vertice %u y mi COLOR ES: %u\n",NombreDelVertice(g,i),ColorDelVertice(g,i) );
		}*/


/*
		printf("cant vertices %u\n",NumeroDeVertices(g) );
		printf("cant lados %u\n", NumeroDeLados(g));
		printf("cant colores %u\n", NumeroDeColores(g));
		printf("Nombre del vertice 1: %u\n",NombreDelVertice(g,1) );
		printf("grado del vertice 1: %u\n",GradoDelVertice(g,1) );
		printf("color del vertice 1: %u\n",ColorDelVertice(g,1) );
		printf("color del vecino 0 del vertice 1: %u\n",ColorJotaesimoVecino(g,1,0) );
		printf("nombre del vecino 0 del vertice 1: %u\n",NombreJotaesimoVecino(g,1,0) );
		printf("Es bipartito: %i\n",Bipartito(g));
		printf("cant colores %u\n", NumeroDeColores(g));*/
/*
		ReordenManteniendoBloqueColores(g, 1);
		printf("NotSoGreedy Inmediatamente despues de aplicar ReordenManteniendoBloqueColores con semilla 0 y NotSoGreedy con semilla 1: %u\n", NotSoGreedy(g,1));
		printf("Not So Greedy con semilla 1 : %u\n", NotSoGreedy(g,1));
		ReordenManteniendoBloqueColores(g,1);
		for(u32 i = 0; i< NumeroDeVertices(g); i++)
      	printf("Nombre: %u, Grado: %u, Color: %u, Cant Apariciones %u\n", g->orden[i]->nombre, g->orden[i]->grado,g->orden[i]->color, g->orden[i]->cant_de_colores);
		for(u32 i= 0; i<10;i++) // 10 Cortidas de NotSoGreedy
			printf("cantida de colores NotSoGreedy: %u\n", NotSoGreedy(g,i));
*/
/* ------------------------------- CUESTIONES DE ORDEN -------------------------------*/

/*--------------------------------------------------------------- */
		/*
		printf("Sin aplicar Orden\n");
		for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			printf("%u\n", g->orden[i]->nombre);
		printf("NotSoGreedy SIN ORDENAR con semilla 1: %u\n", NotSoGreedy(g,1));
		*/
/*--------------------------------------------------------------- */
		/*
		OrdenNatural(g);
		printf("Orden Natural\n");
		for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			printf("%u\n", g->orden[i]->nombre);
		printf("NotSoGreedy Inmediatamente despues de aplicar Orden Natural con semilla 1 : %u\n", NotSoGreedy(g,1));
		*/
/*--------------------------------------------------------------- */
		/*
		OrdenWelshPowell(g);
		printf("Orden Orden Wesh Powell\n");
		for(u32 i = 0 ; i< NumeroDeVertices(g);i++)
			printf("Nombre: %u Grado: %u\n", g->orden[i]->nombre, g->orden[i]->grado);
		printf("NotSoGreedy Inmediatamente despues de aplicar Wesh Powell con semilla 1 : %u\n", NotSoGreedy(g,1));
		*/
/*--------------------------------------------------------------- */
u32 bloque = 0;
u32 natural = 0;

printf("/*--------------------------------------------------------------------------------- */\n");
printf("TERCERAS 10 ITERACIONES ALTERNANDO ENTRE ORDEN NATURAL O BLOQUE COLOR CON X > 1\n");
printf("/*--------------------------------------------------------------------------------- */\n");
for(u32 i=0; i<100;i++){
	if (i % 2 == 0) {
		OrdenNatural(g);
		natural=NotSoGreedy(g,i);
	} else {
		ReordenManteniendoBloqueColores(g,2);
		bloque=NotSoGreedy(g,i);

	}
	printf("NATURAL: %u\nBLOQUE; %u\n",natural, bloque );

	if (!(bloque<=natural)){
		printf("ERRORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
	}
}
/*--------------------------------------------------------------- */
		/*
		ReordenManteniendoBloqueColores(g, 0);
		for(u32 i = 0; i< NumeroDeVertices(g); i++)
			printf("ORDEN BLOQUE 0: %u\n", g->orden[i]->color);
		printf("NotSoGreedy Inmediatamente despues de aplicar ReordenManteniendoBloqueColores con semilla 0 y NotSoGreedy con semilla 1: %u\n", NotSoGreedy(g,1));
		*/

		//ReordenManteniendoBloqueColores(g, 1);
		//for(u32 i = 0; i< NumeroDeVertices(g); i++)
			//printf("%u\n", g->orden[i]->nombre);
		/*
    for (u32 j = 0; j<5; j++) {
  		ReordenManteniendoBloqueColores(g, 2);
      printf("ORDEN BLOQUE 2 SEMILLA %u: \n", j);
  		for(u32 i = 0; i< NumeroDeVertices(g); i++)
  			printf("%u |", g->orden[i]->color);
      printf("\n");
    }


    for (u32 j = 0; j<5; j++) {
      ReordenManteniendoBloqueColores(g, 2);
      printf("ORDEN BLOQUE 2 SEMILLA %u: \n", j);
      for(u32 i = 0; i< NumeroDeVertices(g); i++)
        printf("%u |", g->orden[i]->color);
      printf("\n");
    }
    // ReordenManteniendoBloqueColores(g, 3);
    // printf("ORDEN BLOQUE 2 SEMILLA 3:\n");
		// for(u32 i = 0; i< NumeroDeVertices(g); i++)
		// 	printf("%u |", g->orden[i]->color);
    //
    // printf("\n" );
    //
    // ReordenManteniendoBloqueColores(g, 2);
    // printf("ORDEN BLOQUE 2 SEMILLA 2: \n");
		// for(u32 i = 0; i< NumeroDeVertices(g); i++)
		// 	printf("%u |", g->orden[i]->color);
    //
    // printf("\n" );
    //
    // ReordenManteniendoBloqueColores(g, 3);
    // printf("ORDEN BLOQUE 2 SEMILLA 3:\n");
		// for(u32 i = 0; i< NumeroDeVertices(g); i++)
		// 	printf("%u |", g->orden[i]->color);
    //
    // printf("\n" );
    */
		/* --------------------------------------*/

		tiempo_final = clock();
		segundos = (double)(tiempo_final - tiempo_inicio) / CLOCKS_PER_SEC;
		printf("TIEMPO EN SEGUNDOS : %f\n",segundos);
		minutos = segundos / 60;
		printf("TIMEPO EN MINUTOS: %f\n", minutos);
		DestruccionDelGrafo(g);

}
