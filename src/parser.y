%{
#include "main.h"
//#define YYERROR_VERBOSE
extern FILE *stderr;
int i, j, k, m;
int ch1 [4];
int ch2 [4];
int arr1 [32];
int arr2 [32];
unsigned s1, s2, s;
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
        { start(); }
	| input state
	| input QUIT
	{ YYACCEPT; }
	| input error
        ;

state	: ad
        {
            s = transform($1);
                m = find(s);
		if ( m ) printf ("\tyes on %d line\n", m);
		else printf ("\tno\n");
	}
	| ad'-'ad
	{
		s1 = transform ($1);
		s2 = transform ($3);
		if (Sorted (s1, s2)) YYABORT;

	}
	| ad'/'IP
	{
		k = $3;
		if (k>32) yyerror ("Bad range");
		for (i=0; i<4; i++) ch1[i] = ch2[i] = $1[i];

		decToBin (ch1, arr1);

		for (i=31; i>=0; i--){
			if (k > 0) {
				arr2[i] = arr1[i];
			} else {
				arr1[i] = 0;
				arr2[i] = 1;
			}
                        k--;
		}
		binToDec (arr1, ch1);
		binToDec (arr2, ch2);

		s1 = transform (ch1);
		s2 = transform (ch2);

		if ( Sorted (s1,s2) ) YYABORT;
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
    fprintf (stderr, "\tERROR: %s\n", s);
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

int Sorted (unsigned& s1, unsigned& s2)
{
    double t = s1/s2;
    int k1, k2;
    if (s1 < s2){
        k1 = find (s1);
        k2 = find (s2);
        if ( ! k1 && ! k2 ){
            AddAddress (s1, s2, k);
            printf ("\tAdd %d line\n", line_count);
            line_count++;
        } else {
            printf ("\tConflict lines: %d, %d\n", k1, k2);
            return 1;
        }
    } else yyerror ("s1>s2!");
    return 0;
}
