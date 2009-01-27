%{
#include "main.h"
//#define YYERROR_VERBOSE
extern FILE *stderr;
int i, j, k, m;
int ch1 [4];
int ch2 [4];
int arr1 [32];
int arr2 [32];
long s1, s2, s;
int p [4];
%}
%defines
%start input
%token <ival> IP 
%token <ival> QUIT SPACE DIGIT
%type <ch> ad
%union {
	int ch[4];
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
		Sorted (s1, s2);
		
	}
	| ad'/'IP 
	{
		k = $3;
		if (k>32) yyerror ("Bad range");
		for (i=0; i<4; i++) ch1[i] = ch2[i] = $1[i];
		
		decToBin (ch1, arr1);
		
		for (i=31; i>=0; i--){
			if (k-- > 0) {
				arr2[i] = arr1[i];
			} else {
				arr1[i] = 0;
				arr2[i] = 1;
			}
		}
		binToDec (arr1, ch1);
		binToDec (arr2, ch2);
		
		s1 = func (ch1);
		s2 = func (ch2);
		
		Sorted (s1,s2);
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
int yyerror (const char *s)
{
	fprintf (stderr, "ERROR: %s\n", s);
	return 0;
}

void decToBin (int *ch, int *arr)
{
	int t, i, j, k;
	for (i=0; i<4; i++){
		k = ch[3-i];
		for (j=0; j<8; j++){
			t = k / 2;
			*arr = k-2*t;
			arr++;
			k = t;
		}
	}
	
}

void binToDec (int *arr, int *ch)
{
	int p, i, j;
	for (i=0; i<4; i++){
		p = 0;
		for (j=0; j<8; j++){
			p += (*arr) * pow(2, j);
			arr++;
		}
		ch[3-i] = p;
	}
}

void Sorted (long& s1, long& s2)
{	
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
	} else yyerror ("s1>s2!");
}
