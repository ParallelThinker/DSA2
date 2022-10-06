typedef long long int llint;

//Valor = inteiro
typedef unsigned long int Valor;


//Chave = char
typedef char Chave;

//boolean definitions
#define TRUE 1 
#define FALSE 0 


//About Strings
#define STR_SIZE 20
#define TXT_DELIMITER " .\n\t\r"



//Macros to clean code:
#define LIVRE(HashMap, h) ((HashMap)[h] == NULL)

//Sondagem Linear..
#define INCR(HashMap, h) (h = h == HashMap->M - 1 ? 0 : h + 1) // (h = (h + 1) % M)
