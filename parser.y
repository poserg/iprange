%{
#include "main.h"
extern FILE *stderr;
%}
%defines;
%start input
%token <ch> IP
%token <val> OCTET
%union {
	int A;
	int B;
	int C;
	int D;
	char ch;
}
%%
input	: /*	*/
	| input '\n'
	| input IP '\n'
	{ 
		//printf ("не пустая строка: %s \n", $2); 
		/*adrs.A = yylval.A;
		adrs.B = yylval.B;
		adrs.C = yylval.C;
		adrs.D = yylval.D;*/
		//yywrap();
		//printf("%d\n", adrs.D);
		printf("%s\n", $2);
	}
%%
extern int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}
