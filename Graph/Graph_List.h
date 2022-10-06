#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Graph_defines.h"

typedef struct node Node;
typedef struct graph *Graph; 

struct node{
  int rotulo;
  node *next;//Pointer para Proximo
};


struct graph{
  int m; // total de Vertices
  int n; // Total de arestas
  node* *A;//Pointer para vetor de nodes 
};

//Instantiate Graph: n equals to total vertices
Graph GL_init(int n);

//Graph insertion -> safe way
void GL_insert(Graph G, int v, int w);

//Graph insertion -> unsafe way
void GL_insert_unsafe(Graph G, int v, int w);

//show Graph instance
void GL_display(Graph G);

//print Graph
void GL_print(Graph G, FILE *out);

//Delete GL instances
Graph GL_del(Graph G);

#endif //GRAPH_LIST_H