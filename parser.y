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
	int val;
}
%%
input	: /*	*/
	| input IP
	{ printf ("не пустая строка: %s \n", $2); }
%%
extern int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}
