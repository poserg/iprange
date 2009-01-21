%{
#include "main.h"
#define YYERROR_VERBOSE
extern FILE *stderr;
int flag = 0;
%}
%defines
%start input
%token IP QUIT SPACE
%%
input	: /*	*/
	| input '\n'
	| input state 
	{ 
		printf ("add address: %d\n", $2);
	}
	| input QUIT
	{ 
		//flag = 1;
		YYACCEPT; 
		//yywrap();
	}
	;

state 	: ad 
	| ad SPACE '-' SPACE ad
	| ad SPACE ':' SPACE ad
	;

ad	: IP'.'IP'.'IP'.'IP
	{ 
		printf ("printing 3: %d\n", $3); 
		adrs.A = $1;
		adrs.B = $3;
		adrs.C = $5;
		adrs.D = $7;
		$$ = 123;
	}
	;
%%
extern int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}
