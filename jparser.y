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
	bool bolean;
	simbolo * ptr_simbolo;
	expresion valor;
	}
%start programa		
%token PRINT INTEGER STRING BOOLEAN  EXIT_COMMAND IF ELSE DO WHILE FOR TAB LLAVEAPER LLAVECIE SWITCH CASE BREAK DEFAULT  COMILLA PUNCOMA
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
		LLAVEAPER					
		sentencias 			{;}
		| ejecucion			{;}
		| blo_condicional		{;}
		| sentencia_while		{;}
		| blo_for		{;}
		| sentencia_switch		{;}
		LLAVECIE	{;}
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
		| ID POR_IGUAL expr		{
							simbolo *s = buscar(t, $1->nombre);
							if (s != NULL){											
								if(s->tipo == 'i'){ s->tipo = $3.tipo;}
								if($3.tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((s->tipo == 'b') && ($3.tipo == 'e')) {	//boolean *= entero
										PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'b')) {	//entero *= boolean
										PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'e')) {	//entero *= entero
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int * $3.info.valor_int;
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
		| ID ENTRE_IGUAL expr		{
							simbolo *s = buscar(t, $1->nombre);
							if (s != NULL){										
								if(s->tipo == 'i'){ s->tipo = $3.tipo;}
								if($3.tipo == 'i'){
									PrintError(5, "");						     
								}else{
									if((s->tipo == 'b') && ($3.tipo == 'e')) {	//boolean /= entero
										PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'b')) {	//entero /= boolean
										PrintError(5, "");
									} else if((s->tipo == 'e') && ($3.tipo == 'e')) {	//entero /= entero
										s->tipo = 'e';
										s->info.valor_int = s->info.valor_int / $3.info.valor_int;
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
		;

bloque:
		LLAVEAPER sentencias				{;}
		| LLAVEAPER expr					{;}
		| sentencias						{;}
		| expr								{;}
		| blo_condicional					{;}
		| sentencia_while					{;}
		| blo_for							{;}	
blo_condicional:	
		IF '('expr_comp')' bloque  				{;}
		| blo_condicional blo_else			{;}
		;	
blo_else:
		ELSE bloque							{;}
		| ELSE blo_condicional				{;}
		;		
sentencia_while:
		WHILE '('expr_comp')' bloque				{;}
		;
blo_for:    
        FOR '(' declaraciones ';' expr_comp ';' expr_comp')'  bloque		{;}
        | blo_for programa                    {;}
        ;	
sentencia_switch:    
        SWITCH '('expr')' FINLINEA		{;}
        ;		
pri_for:
		ID				{$1->tipo = 'i';				       	
						insertar(&t, $1);}		
		;
ejecucion:
		ID '(' ')' 			{ 
								simbolo *s = buscar(t, $1->nombre);
								if(s == NULL){
									PrintError(8, $1->nombre);
								}
							}
		| ID_MALO '(' ')' 		{PrintError(4, "nombre de function invalida");}
		| ID '(' verifica_param ')' FINLINEA	{ 
								simbolo *s = buscar(t, $1->nombre);
								if(s == NULL){
									PrintError(8, $1->nombre);
								}
							}
		| ID_MALO '(' verifica_param ')' 
		  FINLINEA				{PrintError(4, "nombre de function invalida");}
		| ejecucion programa			{;}
		;
sentencias:
		| asig FINLINEA  	{;}
		| FINLINEA  	{;}
		| imprimir FINLINEA  	{;}
		| EXIT_COMMAND		{exit(EXIT_SUCCESS);}
	        | RETURN expr FINLINEA  	{ 
						$$.tipo = $2.tipo;
						if($2.tipo == 'e')
							$$.info.valor_int = $2.info.valor_int;
						else if($2.tipo == 'c')
							strcpy($$.info.valor_cad, $2.info.valor_cad);
						else 
							$$.info.valor_bool = $2.info.valor_bool;
					}
		| PRINT expr FINLINEA	{;}
		| sentencias programa	{;}
		;
una_instruccion: 
		declaraciones FINLINEA	{salirBloque(); eliminarBloque(&t); PrintError(4, "instruccion invalida");}
		| declaraciones 	{salirBloque(); eliminarBloque(&t); PrintError(4, "instruccion invalida");}
		| asig FINLINEA 		{salirBloque();}
		| asig   		{salirBloque();}
		| EXIT_COMMAND		{salirBloque(); exit(EXIT_SUCCESS);}
	        | RETURN expr FINLINEA 	{salirBloque();}
		| PRINT expr FINLINEA	{salirBloque();}
		| PRINT expr 		{salirBloque();}
		;
imprimir:
			PRINT '(' expr ')'		{
									if($3.tipo == 'i'){
													PrintError(4, "no se pueden comparar, tipos indefinidos");
									}
									else if($3.tipo == 'e')printf($3.info.valor_int);
									else if($3.tipo == 'c')printf($3.info.valor_cad);
									else printf($3.info.valor_cad);									
									printf("\n");
									}
			;
expr_comp:
	        expr '<' expr    	{ 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if($1.tipo != 'e' || $3.tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
			| expr '>' expr    	{ 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if($1.tipo != 'e' || $3.tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
			| expr MENOR_IGUAL expr { 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if($1.tipo != 'e' || $3.tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
	        | expr MAYOR_IGUAL expr { 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} else if($1.tipo != 'e' || $3.tipo != 'e'){
							PrintError(4, "no se pueden comparar, tipos diferentes de int");
						} 
					}
			| expr DIFERENTE expr   { 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} 
					}
	        | expr COMPARISON1 expr { 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} 
					}
	        | expr COMPARISON2 expr { 
						if($1.tipo == 'i' || $3.tipo == 'i'){
							PrintError(4, "no se pueden comparar, tipos indefinidos");
						} 
					}
		| TRUE			{
						$$.tipo = 'b';
						$$.info.valor_bool = true;
					}
		| FALSE			{
						$$.tipo = 'b';
						$$.info.valor_bool = false;
					}
		| expr			{PrintError(4,"no se puede comparar la expresion");
					}
			| '(' expr_comp ')'     { 
						$$.tipo = $2.tipo;
						if($2.tipo == 'e')
							$$.info.valor_int = $2.info.valor_int;
						else if($2.tipo == 'c')
							strcpy($$.info.valor_cad, $2.info.valor_cad);
						else 
							$$.info.valor_bool = $2.info.valor_bool;
					}
	        | expr_comp AND expr_comp 	{;}
	        | expr_comp OR expr_comp 	{;}
        	;
expr:		
		NUMERO		    	{ 						
						$$.tipo = 'e';
						$$.info.valor_int = $1;
					}
		| CADENA		{
						$$.tipo = 'c';
						strcpy($$.info.valor_cad, $1);
					}
		| TRUE			{
						$$.tipo = 'b';
						$$.info.valor_bool = true;
					}
		| FALSE			{
						$$.tipo = 'b';
						$$.info.valor_bool = false;
					}
			| ID                	{ 
						simbolo *s = buscar(t, $1->nombre);
							if(s != NULL){
								$$.tipo = s->tipo;
								if($$.tipo == 'i'){
									PrintError(6, s->nombre);
							}else{
								if($$.tipo == 'e'){
									$$.info.valor_int = s->info.valor_int;
								} else if($$.tipo == 'c'){
									strcpy($$.info.valor_cad, s->info.valor_cad);
								} else{
									$$.info.valor_bool = s->info.valor_bool;
								}
							} 
						} else{
							PrintError(2, $1->nombre);
						}
					}
			| expr '+' expr     	{ 	
						if(($1.tipo == 'b') && ($3.tipo == 'c')) {		//boolean + cadena
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'b') && ($3.tipo == 'e')) {	//boolean + entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'b')) {	//entero + boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'e')) {	//entero + entero
							$$.tipo = 'e';
							$$.info.valor_int = $1.info.valor_int + $3.info.valor_int;
						} else if(($1.tipo == 'c') && ($3.tipo == 'c')) {	//cadena + cadena
							$$.tipo = 'c';
							sprintf($$.info.valor_cad, "%s%s", $1.info.valor_cad, $3.info.valor_cad);
						} else if(($1.tipo == 'b') && ($3.tipo == 'b')) {	//boolean + boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'c') && ($3.tipo == 'e')) {	//cadena + entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'c')) {	//entero + cadena
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else{
							$$.tipo = 'i';
							if (($1.tipo != 'i') && ($3.tipo != 'i'))
								PrintError(4, "Expresion de tipos indefinidos");
						}
					}	
			| expr '-' expr     	{ 
						if(($1.tipo == 'b') && ($3.tipo == 'e')) {		//boolean - entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'b')) {	//entero - boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'e')) {	//entero - entero
							$$.tipo = 'e';
							$$.info.valor_int = $1.info.valor_int - $3.info.valor_int;
						} else {
							$$.tipo = 'i';
							if (($1.tipo != 'i') && ($3.tipo != 'i'))
								PrintError(4, "Expresion de tipos indefinidos");
						}
					}		
			| expr '*' expr     	{ 
						
						if(($1.tipo == 'b') && ($3.tipo == 'e')) {		//boolean *= entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'b')) {	//entero *= boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'e')) {	//entero *= entero
							$$.tipo = 'e';
							$$.info.valor_int = $1.info.valor_int * $3.info.valor_int;
						} else{
							$1.tipo = 'i';
							if (($1.tipo != 'i') && ($3.tipo != 'i'))
								PrintError(5, "");
						}
					}	
			| expr '/' expr     	{ 
						
						if(($1.tipo == 'b') && ($3.tipo == 'e')) {		//boolean /= entero
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'b')) {	//entero /= boolean
							PrintError(4, "no se pueden concatenar, tipos diferentes de int");
						} else if(($1.tipo == 'e') && ($3.tipo == 'e')) {	//entero /= entero
							$$.tipo = 'e';
							$$.info.valor_int = $1.info.valor_int / $3.info.valor_int;
						} else{
							$1.tipo = 'i';
							if (($1.tipo != 'i') && ($3.tipo != 'i'))
								PrintError(5, "");
						}
					}	
			| expr TOSTRING		{	
						if ($1.tipo != 'e') {
							$$.tipo = 'i';
							PrintError(4, "se requiere un entero para la conversion en linea");
						} else {
							$$.tipo = 'c';
							snprintf($$.info.valor_cad, sizeof($$.info.valor_cad), "%d",$1.info.valor_int);
						}
					}
			| PARSEINT '(' expr ')'	{
						if ($3.tipo != 'c') {
		 					$$.tipo = 'i';
							PrintError(4, "se requiere una cadena para la conversion en linea");
						} else if (esNumero($3.info.valor_cad)){
							$$.tipo = 'e';
							$$.info.valor_int = atoi($3.info.valor_cad);
						} else{
							$$.tipo = 'i';
							PrintError(4, "la cadena a convertir solo puede tener digitos en linea");
						}
					}
				| '(' expr ')'      	{ 
						$$.tipo = $2.tipo;
						if($2.tipo == 'e')
							$$.info.valor_int = $2.info.valor_int;
						else if($2.tipo == 'c')
							strcpy($$.info.valor_cad, $2.info.valor_cad);
						else 
							$$.info.valor_bool = $2.info.valor_bool;
					}
		;
%%

void yyerror(char *s){
	extern int yylineno;	// predefinida en lex.c
	extern char *yytext;	// predefinida en lex.c
	errores++; 
	
	printf("ERROR: %s en simbolo \"%s\" en linea %d \n",s,yytext,yylineno); 
}

void PrintError(int opc, char *s){
	extern int yylineno;	// predefinida en lex.c

	switch(opc){
		case 1:{
			errores++;
			printf("Error: variable '%s' repetetida en linea %d \n", s, yylineno);
			break;
		}
		case 2:{
			errores++;
			printf("Error: variable '%s' no declarada en linea %d \n", s, yylineno);
			break;
		}
		case 3:{
			errores++;
			printf("Error: se esperaba '%s' en linea %d \n", s, yylineno); 
			break;
		}
		case 4:{
			errores++;
			printf("Error: %s, en linea %d \n", s, yylineno); 
			break;
		}
		case 5:{
			errores++;
			printf("Error: asignacion de tipo indefinido en linea %d \n", yylineno); 
			break;
		}
		case 6:{
			errores++;
			printf("Error: tipo de '%s' no definido en linea %d.\n", s, yylineno); 
			break;
		}
		case 7:{
			errores++;
			printf("Error: se esperaba '%s' en linea %d.\n", s, yylineno); 
			break;
		}
		case 8:{
			errores++;
			printf("Error: function '%s' no declarada en linea %d \n", s, yylineno);
			break;
		}
	}	
}

void main(){ 
	t = crear();
	yyparse();	
	if(errores == 0){
		printf("La compilacion fue exitosa!\n"); 
	} else{
		printf("Total de errores: %d\n", errores); 
	}
}