#include <iostream>

#include "AVL.hpp"

node *rotDir(node *R){
    node *aux = R->left;
    if(aux->right)  aux->right->father = R;
    aux->right = R;
    R->father = aux; 
    return aux;    
}

node *rotEsq(node *R){
    node *aux = R->right;
    if(aux->left)  aux->left->father = R;
    aux->left = R;
    R->father = aux; 
    return aux;    
}


AVL::AVL()
{
    tree = nullptr;
}


AVL::~AVL(){
    std::cout <<" fim";
}

node *AVL::new_node(Key x, Cont cont){
    node *aux = new node;
    aux->bal = 0;
    aux->key = x; 
    aux->content = cont;
    aux->left = nullptr; 
    aux->right = nullptr;
    aux->father = nullptr;
    return aux;
}

bool AVL::is_empty(){return this->_empty(tree);}
bool AVL::_empty(node *R){
    if(R == nullptr) return true;
    return false; 
}

bool AVL::is_included(Key key){return this->_included(key, tree);}
bool AVL::_included(Key x, node *aux)
{
    //Check null pointer
    if(_empty(aux)) return false;
    if(aux->key == x) return true; 
    if(aux->key < x) return this->_included(x, aux->right);
    //else if (aux->key > x) 
    return this->_included(x, aux->left);
}


node *AVL::AVL_insert(node *R, node *novo, bool *ptr_del_H){
    // caso 1: subarvore vazia
    if(_empty(R)){
        *ptr_del_H = true;
        return novo;
    }
    
    if(novo->key <= R->key)//busca pela esquerda
    {
        R->right = AVL_insert(R->left, novo, ptr_del_H);
        R->left->father = R;

        if(*ptr_del_H == true){//aumento da subarvore
            // Caso 2: inseriu do lado mais baixo
            if(R->bal == 1){
                R->bal = 0; 
                *ptr_del_H = false;
            }
            //Caso 3: dois lados de tamanho igual
            else if(R->bal == 0){ 
                R->bal = -1;
                *ptr_del_H = true;
            }
            //Caso 4: dividimos em duas situacoes:
            else if(R->bal == -1){
                //Caso 4.1: insere a esquerda do filho esq.
                if(R->left->bal == -1){
                    //Rotacao simples
                    R = rotDir(R);
                    R->right->bal = 0;
                }
                else{ //Caso 4.2: inseriu a direita do filho esq.
                    //Rot. dupla esq + dir
                    R->left = rotEsq(R->left);
                    R = rotDir(R);
                    if(R->bal == 0){
                        R->left->bal = 0;
                        R->right->bal = 0;
                    }
                    else if(R->bal == -1){
                        R->left->bal = 0;
                        R->right->bal = +1;
                    } 
                    else{//R->bal == +1
                        R->left->bal = -1;
                        R->right->bal = 0;
                    }
                }
                R->bal = 0; 
                *ptr_del_H = 0;

            }
            
        }   

    }
    else // Busca pela direita
    {
        R->right = AVL_insert(R->right, novo, ptr_del_H);
        R->right->father = R;

        if(*ptr_del_H == true){//aumento da subarvore
            // Caso 2: inseriu do lado mais baixo
            if(R->bal == 1){
                R->bal = 0; 
                *ptr_del_H = false;
            }
            //Caso 3: dois lados de tamanho igual
            else if(R->bal == 0){ 
                R->bal = -1;
                *ptr_del_H = true;
            }
            //Caso 4: dividimos em duas situacoes:
            else if(R->bal == -1){
                //Caso 4.1: insere a esquerda do filho esq.
                if(R->right->bal == -1){
                    //Rotacao simples
                    R = rotEsq(R);
                    R->left->bal = 0;
                }
                else{ //Caso 4.2: inseriu a direita do filho esq.
                    //Rot. dupla dir + esq
                    R->right = rotDir(R->right);
                    R = rotEsq(R);
                    if(R->bal == 0){
                        R->left->bal = 0;
                        R->right->bal = 0;
                    }
                    else if(R->bal == -1){
                        R->left->bal = 1;
                        R->right->bal = 0;
                    } 
                    else{//R->bal == +1
                        R->left->bal = 0;
                        R->right->bal = -1;
                    }
                }
                R->bal = 0; 
                *ptr_del_H = 0;

            }
            
        }   
   
    }



    return R;
}



void AVL::print(){return this->print_AVL(tree);}
void AVL::print_AVL(node *R){
    if(!_empty(R))  std::cout << R->key << std::endl;
    print_AVL(R->left); std::cout << " ";
    print_AVL(R->right);
}

