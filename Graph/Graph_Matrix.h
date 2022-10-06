#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

#include <stdio.h>
#include <stdlib.h>

#include "Graph_defines.h"


typedef struct graph *Graph; 


struct graph{
  int m; // total de Vertices
  int n; // Total de arestas
  int **A;//Pointer para vetor de nodes 
};

//Instantiate Graph: n equals to total vertices
Graph GM_init(int n);

//Graph insertion -> safe way
void GM_insert(Graph G, int v, int w);

//Graph insertion -> unsafe way
void GM_insert_unsafe(Graph G, int v, int w);

//show Graph instance
void GM_display(Graph G);

//print Graph
void GM_print(Graph G, FILE *out);

//Delete GL instances
Graph GM_del(Graph G);

#endif //GRAPH_MATRIX_H