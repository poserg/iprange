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
	{ AddAddress ($1);}
	| ad SPACE '-' SPACE ad
	{ 
		if ($1[0]<$5[0]) yyerror ("1 < 2");
		else {
			for (i=0; i<$1[3]-$5[3]; i++)
				$1[3]++;
				AddAddress ($1);
		}
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
