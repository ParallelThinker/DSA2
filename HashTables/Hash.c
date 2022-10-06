
//standard libraries
#include <stdio.h>
#include <stdlib.h>/* malloc */ 
#include <math.h> 
#include <string.h> /*strcpy */ 


//usr libraries 
// #include "Hash_defines.h"
#include "Hash.h"


hash_map *hash_Init(llint MAX)
{
    //aloccate a struct to mantain the pointer to array
    hash_map *H = (hash_map*)malloc(sizeof(H));
    if(H!=NULL)
    {

        H->M = MAX+1; 
        H->total_chaves = 0;
        

        hash_node* *aux = (hash_node**) malloc(H->M * sizeof(aux));
        for(int i = 0; i < H->M; i++){
            aux[i] = NULL;
        }
            
        //Linka estrutura auxiliar com Struct Hash_map
        H->ptr_hashLabel = aux;
        return H;
    }
    return NULL;
}


//chave e valor a serem inseridos no vetor de hash
hash_node *new_hash_node(Chave *chave, Valor valor)
{
    hash_node *aux = (hash_node*) malloc (sizeof (aux));

    aux->chave =(char*) malloc(sizeof(char) * STR_SIZE);
    //uso de strncpy -- evita estouro de buffer
    strcpy(aux->chave, chave); 
    aux->valor = valor;
    //aux->vizinho = NULL;
   return aux;
}


//Hash Key generator: h(key) = hash_v1
int hash_h(Chave *chave, int M)
{
    llint prime_num = 127;
    llint i, h = 0;
    for(i = 0; chave[i] != '\0'; i ++){
        h = (h * prime_num + chave[i]) % M;
    }
    return h;
} 

//Hash Key generator: h(key) = hash_v2 
int hash_g(Chave *chave, int M)
{
    llint prime_num = 127;
    llint i, g = 0;
    for(i = 0; chave[i] != '\0'; i ++){
        g = (g * prime_num + chave[i]) % M;
    }
    return g;
} 


//Hash search - split in two situations : get & set value
Valor Hash_get_value(hash_map *H, Chave *chave, int *found)
{

    //Hash Conversion
    int h = hash_g(chave, H->M);

    hash_node* *ptr = (H->ptr_hashLabel);
    //searchs in hash_map struct
    while(!LIVRE(ptr,h) && strcmp(ptr[h]->chave, chave))
    {
        //case not found
        INCR(H,h);       
    }
    
    if (!LIVRE(ptr,h)){
        *found = TRUE;
        return ptr[h]->valor;
    } 
    //else..
    *found = FALSE;
    return 0;
}
//change value key, just in case is found - > return TRUE or FALSE if value was changed
int Hash_set_value(hash_map *H, Chave *chave, Valor novo_valor)
{
        //Hash Conversion
    int h = hash_g(chave, H->M);

    hash_node* *ptr = (H->ptr_hashLabel);
    //searchs in hash_map struct
    while(!LIVRE(ptr,h) && strcmp(ptr[h]->chave, chave))
    {
        //case not found, increment !
        INCR(H,h);       
    }
    
    if (!LIVRE(ptr,h)){
        ptr[h]->valor = novo_valor;
        return TRUE;
    } 
    //else..
    return FALSE;

}

//Hash insertion: Linear Probing -> jumps over till finds a blank space, then links in "vizinho"
int Hash_insert(hash_map *H, Chave *chave, Valor valor)
{
    //Hash conversion
    int h = hash_g(chave, H->M);


    //hash_node **ptr = H->ptr_hashLabel;
    //Similar ao que ocorre em search, iteramos até encontrarmos
    while(!LIVRE(H->ptr_hashLabel,h) && strcmp(H->ptr_hashLabel[h]->chave, chave))
    {
        //while not found, increment
        INCR(H,h);      
    }
    //if is a null pointer, insert !
    if(LIVRE(H->ptr_hashLabel,h))
    {
        if(H->total_chaves == H->M-1)
        {
            printf("Error: Full Label, not inserted...");
            return FALSE;
        }

        H->ptr_hashLabel[h] = new_hash_node(chave, valor);
        H->total_chaves+=1;
    }
    return TRUE;
}

