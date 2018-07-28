/* ---------------------------------------------------------------------------------
---------------------- PROYECTO DE MATEMATICA DISCRETA 2018 ------------------------
------------------------------------------------------------------------------------
    INTEGRANTES: Lucas Astrada - astradalucasezequiel@gmail.com
                 Jenaro Calviño - jen.calvineo@gmail.com
                 Francisco Semino - fseminobellville@gmail.com
-------------------------------------------------------------------------------- */
#include "TheOutsider.h"

Grafo ConstruccionDelGrafo(){
    char linea[BUFFER_SIZE];
    u32 n_vertices = 0;//cantidad de vertices from input
    u32 m_lados = 0;//cantidad de lados from input
		u32 vertice_u, vertice_v = 0; //vertices que se leen del input lados.
    while(fgets(linea, sizeof(linea), stdin)) {
        if(strncmp(linea, "c", 1)) {
            if(!strncmp(linea, "p edge ", 7)) {
              sscanf(linea, "%*c %*s %u %u", &n_vertices, &m_lados);
              break;
            }
        }
    }
		//Creacion, asignacion de memoria y completo campos del grafo respectivamente
		Grafo grafo = NULL;
		grafo = malloc(1*sizeof(struct _Grafo_t));
		grafo->nro_vertices=n_vertices;
		grafo->nro_lados=m_lados;
		grafo->nro_colores=n_vertices;
		grafo->vertices=calloc(n_vertices,sizeof(struct _Vertice_t));
		grafo->orden=malloc(n_vertices*sizeof(PVertice));
		grafo->facil_busqueda = malloc(n_vertices*sizeof(bool));
		memset(grafo->facil_busqueda, false, (n_vertices)*sizeof(bool));
		//carga de lados y vertices
		while(fgets(linea, sizeof(linea), stdin)){
				PVertice vert_input_u = NULL;
				PVertice vert_input_v = NULL;
				if(!strncmp(linea, "e", 1)){
						sscanf(linea, "%*c %u %u", &vertice_u, &vertice_v);
						/*cuando tenemos vertice v y vertice u, cargamos los vertices,
						luego le cargamos el vecino u al vertice v y viceversa*/
						vert_input_u = BuscoOAgregoVert(grafo,vertice_u);
						vert_input_v = BuscoOAgregoVert(grafo,vertice_v);
						//agrego los vecinos
						NuevoVecino(vert_input_v,vert_input_u);//nuevo vecino de u y v
				}
		}
		return grafo;
}

PVertice BuscoOAgregoVert(Grafo g,u32 v_nombre){
/*Agegar vertice seria muy costoso si tendria q cada vez que le llega un vertice
buscar que este no este ya agregado, por eso se indexa y se crea en la estructura
facil_busqueda que es para ver si el vertice esta cargado indexado por su nombre
modulo la cantidad de vertices es te numero puede ser igual para varios vertices
por eso si no esta en ese indice pero dice que ese indice esta ocupado por alguien mas
sigue buscando en el siguiente porque a la hora de guardarlo si su nombre modulo
la cantidad de vertices esta ocupado por otro vertices con la misma operacion
se guarda en el siguiente indice es decir en nombre%cantidad_vertices +1 y asi
sucesivamente*/
		PVertice vert_return = NULL;
		u32 i_fbusqueda = v_nombre%(g->nro_vertices);
		u32 n=0;
		while (g->facil_busqueda[i_fbusqueda] && n < g->nro_vertices) {
        n++;
        if (g->vertices[i_fbusqueda].nombre == v_nombre) {
            vert_return = &g->vertices[i_fbusqueda];
            n = 0;
						return vert_return;
        }
        else {
            i_fbusqueda++;
            if (i_fbusqueda == g->nro_vertices)
                i_fbusqueda = 0;
        }
    }

		g->vertices[i_fbusqueda].nombre = v_nombre;
		g->vertices[i_fbusqueda].grado = 0;
		g->vertices[i_fbusqueda].color = i_fbusqueda;
		g->vertices[i_fbusqueda].cant_de_colores = 0;
		g->vertices[i_fbusqueda].index = i_fbusqueda;
		g->vertices[i_fbusqueda].mem_vecinos = 3;
		g->vertices[i_fbusqueda].tag = i_fbusqueda;
		g->vertices[i_fbusqueda].vecinos=malloc(g->vertices[i_fbusqueda].mem_vecinos*sizeof(PVertice));
		g->facil_busqueda[i_fbusqueda] = true;
		g->orden[i_fbusqueda] = &g->vertices[i_fbusqueda];
		vert_return = &g->vertices[i_fbusqueda];

		return vert_return;

}

void NuevoVecino(PVertice vert_u, PVertice vert_v){
		//Nuevo vecino "V" para el vertice "U"
		if((vert_u->mem_vecinos)==(vert_u->grado)){
			PVertice *vecinos;
			vecinos = realloc(vert_u->vecinos,(vert_u->mem_vecinos+3)*sizeof(PVertice));
			vert_u->mem_vecinos+=3;
			vert_u->vecinos = vecinos;
		}
		vert_u->vecinos[vert_u->grado] = vert_v;
		vert_u->grado++;
		//agrego vecino "U" para el vertice "V"
		if((vert_v->mem_vecinos)==(vert_v->grado)){
			PVertice *vecinos;
			vecinos = realloc(vert_v->vecinos,(vert_v->mem_vecinos+10)*sizeof(PVertice));
			vert_v->mem_vecinos=vert_v->mem_vecinos +10;
			vert_v->vecinos = vecinos;
		}
		vert_v->vecinos[vert_v->grado] = vert_u;
		vert_v->grado++;

}

void DestruccionDelGrafo(Grafo g){
	for(u32 i=0;i<g->nro_vertices;i++)
			free(g->vertices[i].vecinos);
	free(g->vertices);
	free(g->orden);
	free(g);
}
