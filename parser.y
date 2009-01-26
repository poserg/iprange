%{
#include "main.h"
//#define YYERROR_VERBOSE
extern FILE *stderr;
int i, k;
unsigned s1, s2, s;
int p [4];
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
	| input QUIT
	{ YYACCEPT; }
	| input error '\n'
	;

state 	: ad
	{ 
		s = func($1);
		if (find(s)) printf ("yes\n");
		else printf ("no\n");
	}
	| ad'-'ad
	{
		s1 = func ($1);
		s2 = func ($3);
		if (s1<=s2){
			for ( ; s1<=s2; s1++){
				if (!find(s1))
					AddAddress (s1);
				else {
					printf ("IP is exist: ");
					unfunc (s1, p);
					for (i=0; i<4; i++){
						k = p[i];
						printf ("%d.", k);
					}
					printf ("\n");
				}
			}
			printf ("Add\n");
		} else printf ("Not add\n");
		
	}
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

