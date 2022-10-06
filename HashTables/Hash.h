#ifndef AVL_H
#define AVL_H

//standard libraries
#include <stdio.h>
#include <stdlib.h>/* malloc */ 
#include <math.h> 
#include <string.h> /*strcpy */ 


//usr libraries 
#include "Hash_defines.h"


// Structs used in this case -> Enderecamento fechado !
typedef struct hash_node{
    Chave *chave;
    Valor valor;
} hash_node;


typedef struct hash_map //contains info about hash Struct
{
    llint M; //Label size
    llint total_chaves; //total keys stored
    
    //pointer to hash_node structures
    hash_node* *ptr_hashLabel;
    
}hash_map;

hash_map *hash_Init(llint MAX);

Valor Hash_get_value(hash_map *H, Chave *chave, int *found);


//chave e valor a serem inseridos no vetor de hash
hash_node *new_hash_node(Chave *chave, Valor valor);


//Hash Key generator: h(key) = hash_v1
int hash_h(Chave *chave, int M);

//Hash Key generator: h(key) = hash_v2 
int hash_g(Chave *chave, int M);

//Hash search - split in two situations : get & set value
Valor Hash_get_value(hash_map *H, Chave *chave, int *found);

//change value key, just in case is found - > return TRUE or FALSE if value was changed
int Hash_set_value(hash_map *H, Chave *chave, Valor novo_valor);

//Hash insertion: Linear Probing -> jumps over till finds a blank space, then links in "vizinho"
int Hash_insert(hash_map *H, Chave *chave, Valor valor);


#endif //AVL_H