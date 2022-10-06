

#include "Graph_Matrix.h"


//Instantiate Graph: n equals to total vertices
Graph GM_init(int n){
  Graph _G; 
  int i, j; //aux to "for" iterations

  _G = malloc(sizeof(_G));
  _G->m = 0; 
  _G->n = n; 
  _G->A= malloc(n * sizeof(int*));//Aloca vetor de ponteiros p/ inteiros
  for(i=0; i < n; i++){ //O(n^2)
    _G->A[i] = calloc(n, sizeof(int)); // Aloca em cada pos. do vetor, um vetor de int zerado
  }

  return _G;
}

//Graph insertion -> safe way
void GM_insert(Graph G, int v, int w){
  int i;
  //checagem se ha o elemento em questao
    if(G->A[v][w] == 0){
      G->A[v][w] = 1;
      G->m+=1;
    }  
}

//Graph insertion -> unsafe way
void GM_insert_unsafe(Graph G, int v, int w){
  G->A[v][w] = 1;
  G->m+=1;
}

//show Graph instance
void GM_display(Graph G){
  int i, j;
  for (i = 0; i < G->n; i++) {
    printf("%2d -",i);
    for (j = 0; j < G->n; j++)
      if (G->A[i][j] == 1)
        printf( "%2d ", j);
    printf("-1"); // sentinela para marcar fim de lista
    printf("\n");
  }
}

//print Graph
void GM_print(Graph G, FILE *out){

  int v,w; //aux. to "for" iteration
  fprintf(out, "%2d %2d", G->n, G->m); //Nro. vertice Nro. Aresta
  for(v=0;v < G->n;v++){ //O(n^2)
    for(w=0; w<G->n;w++)
      if(G->A[v][w] == 1)
        fprintf(out,"%2d ", w);
    
    fprintf(out, "-1");
    fprintf(out, "\n");  
  }

}

//Delete GL instances
Graph GM_del(Graph G){

  int i;
  for(i =0; i < G->n; i++){ //O(n)
    free(G->A[i]);
    G->A[i] = NULL;
  }  

  free(G->A);
  G->A = NULL;
  free(G);
  return NULL;
}
