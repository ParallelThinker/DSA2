


// Usr Libraries
#include "Graph_List.h"

//Instantiate Graph: n equals to total vertices
Graph GL_init(int n){
  Graph GL_aux;
  int i;
  //allocate Graph in memo.
  GL_aux = (Graph) malloc(sizeof(GL_aux));

  //fill up
  GL_aux->n = n; //total vertices
  GL_aux->m = 0; //total arc.
  GL_aux->A =(Node **) malloc(n * sizeof(Node*));

  for(i = 0; i < n; i++)
    GL_aux->A = NULL; //Null Pointers at first

  return GL_aux;
}

//Graph insertion -> safe way
//Inserts a new vertice !
void GL_insert(Graph G, int v, int w){
  
  Node *p_aux;
  for(p_aux = G->A[v]; p_aux != NULL ; p_aux = p_aux->next)
    if(p_aux->rotulo == w) // ja existente no grafo !
      return ;
  p_aux = malloc(sizeof(Node));//Aloca um novo no, que seria a relacao entre v-w
  //preenche seus valores
  p_aux->rotulo = w;
  p_aux->next = G->A[v];
  G->A[v] = p_aux;
  G->m+=1;
}

//Graph insertion -> unsafe way
//Inserts a new arch without checking
void GL_insert_unsafe(Graph G, int v, int w){
  Node *p_aux;
  p_aux = malloc(sizeof(Node));

  p_aux->rotulo = w;   
  p_aux->next = G->A[v];

  G->A[v] = p_aux;
  G->m +=1; 
}

//show Graph instance
void GL_display(Graph G){

}

//print Graph
void GL_print_file(Graph G, FILE *output){
  int i;
  Node *p; 
  fprintf(output, "%d %d\n", G->n, G->m); //vertice + aresta
  for(int i = 0; i < G->n;i++){
    for(p=G->A[i]; p != NULL; p = p->next)
      fprintf(output, "%2d", p->rotulo); //imprime arcos do vertice
    fprintf(output, "-1"); //indica final da linha no Grafo (sentinela)
    fprintf(output, "\n");

  }

}

//Delete GL instances
Graph GL_del(Graph G){
  Node *p; 
  int i;
  for(i=0; i <G->n; i++){
    p = G->A[i]; 
    while(p!=NULL){
      G->A[i] = p; 
      p = p->next;
      free(G->A[i]);
    }
    G->A[i] = NULL;

  }
  free(G->A);
  G->A = NULL;
  
  free(G);
  return NULL;
}