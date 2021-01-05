#include "vectores.h"
typedef struct Symbol { /* entrada de la tabla de símbolos */
	char   *name;
	short   type;   /* VAR, BLTIN, UNDEF */
	union {
		Vector *val;	       /* si es VAR */
		double (*ptr)();
	} u;
	struct Symbol   *next;  /* para ligarse a otro */ 
} Symbol;

Symbol *install(char *,int, Vector *); 
Symbol *lookup(char *s);
