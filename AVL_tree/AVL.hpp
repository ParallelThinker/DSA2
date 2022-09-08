#ifndef AVL_H
#define AVL_H

// #include "AVL.cpp"

typedef int Cont;
typedef int Key;

typedef struct node{
    
	Key key;
	Cont content;
	int bal;

    node *father;
    node *left;
    node *right;
} node;



class AVL{
private:
    node *tree;

	//Funcoes-membro privadas:
	//Funcao Recursiva de Add 
	void _add(int, node **, bool &);

	//Funcao recursiva de show
	void show(node *);

	//Funcao recursiva de oper. == and !=
	// bool _equal(const node *, const node *);

	//Funcao recursiva de included
	bool _included(Key x, node *Aux);

	bool _empty(node *aux);

	//control members:
	node *new_node(Key, Cont); 
	node *r_case(node *aux);
	node *l_case(node *aux);
	node *_ins(node *R, Key x, Cont cont);
	
	
	node *insert(node *R, Key key, Cont content);
	node *AVL_insert(node *R, node *novo, bool *del_H);
	void print_AVL(node *R);
public:
    AVL();
    ~AVL();
	void print();

	// verifica valor, se esta incluido
	bool is_included(Key x);

	//verifica se Arvore esta vazia
	bool is_empty();
};



#endif// AVL_H

