%{
#include "main.h"
extern FILE *stderr;
%}
%defines
%start input
%token IP QUIT
%%
input	: /*	*/
	| input '\n'
	| input ad '\n'
	{ 
		printf ("add address: %d\n", $2);	
	}
	| input QUIT
	{ YYACCEPT; }
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
