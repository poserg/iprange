%{
#include "main.h"
#define YYERROR_VERBOSE
extern FILE *stderr;
int i, k;
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
	{
		for (i=0; i<4; i++) 
			if ($1[i]>0) printf ("%d.", $1[i]);
			else printf ("%d.", 256+$1[i]);
		printf ("%c", '\n');
	}
	| ad SPACE '-' SPACE ad
	{ printf ("range IP - '-'\n");}
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
