%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "vector_calcu.c"
#define YYSTYPE double

void yyerror (char *s);
int yylex ();
void warning(char *s, char *t);
%}
%union{
	double val;
	Vector *vector;
}

/**aqui se crean los simbolos terminales y no terminales**/

%token<val>	NUMBER		//Simbolo terminal
%type<vector>	exp
%type<vector>	vector
%type<val>	number

/**aqui va la jerarquia de operadores**/
//Suma y resta
%left '+' '-'
//Producto escalar
%left '*'
//Producto cruz y producto punto
%left 'x' '.'

/**Gramática**/
%% 
inputString:
	| inputString list;
	;

list:	'\n'
	| exp '\n' {imprimeVector($1);}
	| number '\n' {printf("\t%lf\n, $1);}
	;

exp:    vector  
        | exp '+' exp     { $$ = sumaVector($1,$3);}	//Suma de Vectores
        | exp '-' exp     { $$ = restaVector($1,$3);}	//Resta de Vectores
        | exp '*' exp     { $$ = escalarVector($1,$3);}	//Producto escalar
        | exp 'x' exp     { $$ = productoCruz($1,$3);}	//Producto Cruz
	;
	
number:	NUMBER
      	| vector '.' vector 	{$$ = productoPunto($1, $3);}	//Producto punto
	| '|' vector '|' 	{$$ = vectorMagnitud($2);}	//Magnitud del vect
	;

vector : '[' NUMBER NUMBER NUMBER ']' {Vector *v = creaVector(3); 
       					v -> vec[0] = $2;
       					v -> vec[1] = $3;
       					v -> vec[2] = $4;}
	;
%%

#include <stdio.h>
#include <ctype.h>
char *progname;
int lineno = 1;

void main (int argc, char *argv[]){
	progname=argv[0];
  	yyparse ();
}
int yylex (){
  	int c;

  	while ((c = getchar ()) == ' ' || c == '\t')  
  		;
 	if (c == EOF)                            
    		return 0;
  	if (isdigit (c)) {
      		ungetc (c, stdin);
      		scanf ("%lf", &yylval.val);
	      return NUMBER;
    	}
	return c;
}
void yyerror (char *s) {
	warning(s, (char *) 0);
}
void warning(char *s, char *t){
	fprintf (stderr, "%s: %s", progname, s);
	if(t)
		fprintf (stderr, " %s", t);
	fprintf (stderr, "cerca de la linea %d\n", lineno);
}




