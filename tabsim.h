#include <stdlib.h> /* for atoi */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct _simbolo { 
	struct _simbolo * sig;
	char nombre [20];
	char tipo;
	int scope;
	union {
		char valor_cad[100];
		int valor_int;
		bool valor_bool;
	} info;
} simbolo;

typedef struct {
	char tipo;
	union {
		char valor_cad[100];
		int valor_int;
		bool valor_bool;
	} info;
} expresion;

 simbolo * crear();
 void insertar(simbolo **, simbolo *);
 void eliminar(simbolo **);
 void eliminarBloque(simbolo **);
 simbolo *buscar(simbolo *, char[]);
 simbolo *buscarEnBloque(simbolo *, char[], int);
 void entrarBloque();
 void salirBloque();
 void imprimir(simbolo * );
extern int level;
extern int errores;