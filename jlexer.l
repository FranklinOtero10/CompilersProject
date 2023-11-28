%{
#include "tabsim.h"
#include "y.tab.h"
#include <string.h>
simbolo *t;
//int yylineno = 1;
%}
letra [a-zA-Z]
entero [0-9]+
dec {entero}("."){entero}?
id ("_"|{letra})("_"|{letra}|{entero})*
esp		[ \t\n]*
print		("print")
comment1	("//")((.)*)([\n])
comment2	("/*")({esp})((.)|({esp}))*("*/")


%%+
{print}		{return PRINT;}
"int"		{return INTEGER;}
"string"	{return STRING;}
"boolean"	{return BOOLEAN;}
"exit"		{return EXIT_COMMAND;} 
"if"		{ return IF;} 
"else"		{ return ELSE;}
"do"		{ return DO;}
"while"		{ return WHILE;}
"for"		{ return FOR;}
"switch"	{return SWITCH;}
"case"		{entrarBloque(); return CASE;}
"break"		{return BREAK;}
"default"	{return DEFAULT;} 		 
"parseInt"	{return PARSEINT;}
".toString()"	{return TOSTRING;}	
{comment1}	;
{comment2}	;
"true"		{return TRUE;}
"false"		{return FALSE;}
"return"	{return RETURN;}
\"			{return COMILLA;}
\;			{return PUNCOMA;}
\t			{return TAB;}
"{"			{entrarBloque(); return LLAVEAPER;}
"}"			{salirBloque();return LLAVECIE;}
"and"		{return AND;}
"or"		{return OR;}
"<="		{return MENOR_IGUAL;}
">="		{return MAYOR_IGUAL;}
"=="		{return COMPARISON1;} // Realiza la comparacion pero ignora el tipo de dato al que pertenece la variable.
"!="		{return DIFERENTE;}
"-="		{return MENOS_IGUAL;}
"+="		{return MAS_IGUAL;}
"*="		{return POR_IGUAL;}
"/="		{return ENTRE_IGUAL;}
[0-9]+		{
			yylval.numero = atoi(yytext);	// Se realiza la conversion del dato entero recibido como string en int
			return NUMERO;
		}
\"[^\"]*\" 	{
			strcpy(yylval.cadena, yytext+1); 	//se omiten las comillas dobles
			yylval.cadena[yyleng-2] = 0; 		//se eliminar las comillas dobles
			return CADENA;
		}
[-+()/=*;<>,]	{return *yytext;}	/*ESTA ES LA SECCION DE OPERADORES */
[{] 		{ return *yytext; }	/* inicio de bloque */ 
[}] 		{ return *yytext; }	/* fin de bloque */ 
{id}		{	
				if(strlen(yytext)>19) yytext[19] = 0;
				
				yylval.ptr_simbolo = (simbolo *) malloc(sizeof(simbolo));
				strcpy(yylval.ptr_simbolo->nombre, yytext);					
				yylval.ptr_simbolo->scope = level;

				if((yytext[0] >= '0') && (yytext[0] <= '9')){
					return ID_MALO;
				} else{		
					return ID;
				}		
			}
[ \t]       	; 	/* espacios en blanco */
[\n]		{yylineno++;}
.		{yyerror("caracter no valido");}
%%

int yywrap(void) {
    return 1;
}