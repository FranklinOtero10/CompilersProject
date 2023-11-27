%{
#include "tabsim.c"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void yyerror(char *);
int yylex(void);
void PrintError(int, char *);
int esNumero(char * s){
	int i=0;
	if (s[i] == '-') i++;
	for(; s[i] != 0; i++)
	if ((s[i]<'0') || (s[i]>'9')) return 0;
	return 1;
}
simbolo *t = NULL;
%}

%union 	{
	char cadena[100];
	int numero;
	boolean bolean;
	simbolo * ptr_simbolo;
	expresion valor;
	}
%start programa		
%token PRINT EXIT_COMMAND IF ELSE DO WHILE FOR TAB DOSPUNTOS SWITCH CASE BREAK DEFAULT  COMILLA PUNCOMA
%token FINLINEA AND OR MENOR_IGUAL MAYOR_IGUAL COMPARISON1 COMPARISON2 DIFERENTE INCREMENTO DECREMENTO RETURN
%token MENOS_IGUAL MAS_IGUAL POR_IGUAL ENTRE_IGUAL PARSEINT TOSTRING

%token <numero> NUMERO
%token <boolean> TRUE FALSE
%token <ptr_simbolo> ID ID_MALO
%token <cadena> CADENA

%type<valor> expr expr_comp sentencias pri_for ejecucion

%left '+' '-'
%left '*' '/'

%%
programa: 					
		sentencias 			{;}
		| ejecucion			{;}
		| blo_condicional		{;}
		| sentencia_while		{;}
		| blo_for		{;}
		| sentencia_switch		{;}
		| error FINLINEA			{yyerrok;}	
		;
declaraciones:				
		| ID '=' expr		{
							simbolo *s = buscarEnBloque(t, $1->nombre, level);							
							if (s == NULL){					
								if($3.tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if($3.tipo == 'e'){
										$1->tipo = 'e';
										$1->info.valor_int = $3.info.valor_int;		       	
										insertar(&t, $1);
									} else if($3.tipo == 'c'){ 
										$1->tipo = 'c';
										strcpy($1->info.valor_cad, $3.info.valor_cad);	       	
										insertar(&t, $1);
									} else{ 
										$1->tipo = 'b';
										$1->info.valor_bool = $3.info.valor_bool;	       	
										insertar(&t, $1);
									}											
								}	
							} else{
								PrintError(1, $1->nombre);
							}		     
						}
		| ID_MALO '=' expr		{PrintError(4, "nombre de variable invalida");}
		| declara_multi		{;}
		;
declara_multi:
		ID				{
							simbolo *s = buscarEnBloque(t, $1->nombre, level);		     
							if (s == NULL){	
								$1->tipo = 'i';				       	
								insertar(&t, $1);
							} else{
								PrintError(1, $1->nombre);
							}
						}
		| ID_MALO 			{PrintError(4, "nombre de variable invalida");}
		| ID ',' declara_multi		{
							simbolo *s = buscarEnBloque(t, $1->nombre, level);		     
							if (s == NULL){	
								$1->tipo = 'i';				       	
								insertar(&t, $1);
							} else{
								PrintError(1, $1->nombre);
							}
						}
		| ID_MALO ',' declara_multi	{PrintError(4, "nombre de variable invalida");}
		;
declara_function:
		ID				{
							simbolo *s = buscarEnBloque(t, $1->nombre, level - 1);		     
							if (s == NULL){	
								$1->tipo = 'i';	
								$1->scope--;			       	
								insertar(&t, $1);
							} else{
								PrintError(1, $1->nombre);
							}
						}
		| ID_MALO 			{PrintError(4, "nombre de variable invalida");}
		;
verifica_param:
		ID				{
							simbolo *s = buscarEnBloque(t, $1->nombre, level);		     
							if (s == NULL){	
								PrintError(2, $1->nombre);
							}
						}
		| ID_MALO 			{PrintError(4, "nombre de parametro invalida");}
		| ID ',' verifica_param		{
							simbolo *s = buscarEnBloque(t, $1->nombre, level);		     
							if (s == NULL){	
								PrintError(2, $1->nombre);
							}
						}
		| ID_MALO ',' verifica_param	{PrintError(4, "nombre de parametro invalida");}
		| NUMERO		    	{;}
		| NUMERO ',' verifica_param    	{;}
		| CADENA			{;}
		| CADENA ',' verifica_param    	{;}
		| TRUE				{;}
		| TRUE ',' verifica_param    	{;}
		| FALSE				{;}
		| FALSE ',' verifica_param    	{;}
		;
asig:		
		ID '=' expr            {
                            simbolo *s = buscar(t, $1->nombre);
                            if (s != NULL){                                                            
                                if(s->tipo == 'i'){ s->tipo = $3.tipo;}
                                if($3.tipo == 'i'){
                                    PrintError(5, "");                             
                                }else{
                                    if($3.tipo != s->tipo){
										///VALIDAR SI ES NECESARIO
                                        ///PrintError(4, "tipos incompatibles");    
                                    } else if(s->tipo == 'e'){
                                        s->info.valor_int = $3.info.valor_int;        
                                    } else if(s->tipo == 'c'){
                                        strcpy(s->info.valor_cad, $3.info.valor_cad);    
                                    } else{
                                        s->info.valor_bool = $3.info.valor_bool;
                                    }                                            
                                }     
                            } else{
                                $1->tipo = $3.tipo;                       
                                insertar(&t, $1);
                            }
                        }
        | ID MENOS_IGUAL expr		{	
							simbolo *s = buscar(t, $1->nombre);
							if (s != NULL){														
								if(s->tipo == 'i'){ s->tipo = $3.tipo;}
								if($3.tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((s->tipo == 'b') && ($3.tipo == 'e')) {	//boolean -= entero 
                                        PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'b')) {	//entero -= boolean 
                                        PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'e')) {	//entero -= entero 
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int - $3.info.valor_int;
									} 											
								} 									
							} else{
								PrintError(2, $1->nombre);
							}
						}
        | ID MAS_IGUAL expr		{
							simbolo *s = buscar(t, $1->nombre);
							if (s != NULL){											
								if(s->tipo == 'i'){ s->tipo = $3.tipo;}
								if($3.tipo == 'i'){
									PrintError(5, "");						     
								}else{	
									if((s->tipo == 'b') && ($3.tipo == 'c')) {		//boolean += cadena
                                        PrintError(5, "");
									} else if((s->tipo == 'b') && ($3.tipo == 'e')) {	//boolean += entero
                                        PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'b')) {	//entero += boolean
                                         PrintError(5, "");
									} else if(($1->tipo == 'e') && ($3.tipo == 'e')) {	//entero += entero
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int + $3.info.valor_int;
									} else if((s->tipo == 'c') && ($3.tipo == 'c')) {	//cadena += cadena
										s->tipo = 'c';
										sprintf($1->info.valor_cad, "%s%s", s->info.valor_cad, $3.info.valor_cad);
									} else if((s->tipo == 'b') && ($3.tipo == 'b')) {	//boolean += boolean
                                         PrintError(5, "");
									} else if((s->tipo == 'c') && ($3.tipo == 'e')) {	//cadena += entero
										s->tipo = 'c';
										sprintf(s->info.valor_cad, "%s%d", s->info.valor_cad, $3.info.valor_int);
									} else if((s->tipo == 'e') && ($3.tipo == 'c')) {	//entero += cadena
                                        PrintError(5, "");
									} else{
										s->tipo = 'i';
										if((s->tipo != 'i') && ($3.tipo != 'i'))
											PrintError(5, "");
									}										
								} 
							} else{
								PrintError(2, $1->nombre);
							}
						}