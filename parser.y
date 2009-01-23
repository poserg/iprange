%{
#include "main.h"
#define YYERROR_VERBOSE
extern FILE *stderr;
int i, k;
//int flag = 0;
%}
%defines
%start input
%token <ch> IP 
%token <ival> QUIT SPACE
%type <adr> ad
%union {
	char ch[3];
	int ival;
	char adr[15];
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
		for (i=0; i<15; i++) str[i] = 0;
		for (i=0; i<k; i++) str[i] = $1[i];
		printf ("%c\n", str[2]);
	}
	| ad SPACE '-' SPACE ad
	{ printf ("range IP - '-'\n");}
	| ad SPACE ':' SPACE ad
	{ printf ("range IP - ':'\n");}
	;

ad	: IP'.'IP'.'IP'.'IP
	{ 
		for (i=0; i<15; i++) $$[i]=0;
		k = 0;
		for (i=0; $1[i]; i++) $$[k++] = $1[i];
		$$[k++] = '.';
		for (i=0; $3[i]; i++) $$[k++] = $3[i];
		$$[k++] = '.';
		for (i=0; $5[i]; i++) $$[k++] = $5[i];	
		$$[k++] = '.';
		for (i=0; $7[i]; i++) $$[k++] = $7[i];

	}
	;
%%
extern int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}
