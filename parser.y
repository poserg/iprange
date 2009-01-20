%{
#include "main.h"
extern FILE *stderr;
%}
%defines
%start input
%token IP
%%
input	: /*	*/
	| input '\n'
	| input ad '\n'
	{ 
		//printf ("не пустая строка: %s \n", $2); 
		/*adrs.A = yylval.A;
		adrs.B = yylval.B;
		adrs.C = yylval.C;
		adrs.D = yylval.D;*/
		//yywrap();
		//printf("%d\n", adrs.D);
		//printf("%s\n", $2);
	}

ad	: IP'.'IP'.'IP'.'IP'\n'
	{ printf ("printing 3: %d\n", $1); 
	$$ = $3;
	}
%%
extern int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}
