%{
#include "main.h"
#define YYERROR_VERBOSE
extern FILE *stderr;
int i, k;
unsigned s1, s2, s3, s4, s;
char p[4];
//int flag = 0;
%}
%defines
%start input
%token <ival> IP 
%token <ival> QUIT SPACE
%type <ch> ad
%union {
	char ch[4];
	int ival;
}
%%
input	: /*	*/
	| input '\n'
	| input state 
	{ 
		//printf ("add address: %d\n", $2);
	}
	| input QUIT
	{ 
		//flag = 1;
		YYACCEPT; 
		//yywrap();
	}
	;

state 	: ad
	{ AddAddress ($1);}
	| ad SPACE '-' SPACE ad
	{
		s1 = func ($1);
		s2 = func ($5);
		//printf ("s1 = %u; s2 = %u\n", s1, s2);
		unfunc (s1, *p);		
	}
	| ad SPACE ':' SPACE ad
	{ printf ("range IP - ':'\n");}
	;

ad	: IP'.'IP'.'IP'.'IP
	{ 
		$$[0] = $1;
		$$[1] = $3;
		$$[2] = $5;
		$$[3] = $7;
	}
	;
%%
extern int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}

