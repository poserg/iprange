%{
#include "y.h"
//#define YYERROR_VERBOSE
int i, k, m;
int ch1 [4];
int ch2 [4];
short arr1 [32];
short arr2 [32];
unsigned s1, s2;

int parse (parse_parm *pp)
{
    int par;
    yylex_init (pp, pp->yyscanner);
    yyset_extra (pp, pp->yyscanner);
    par = yyparse (pp, pp->yyscanner);
    yylex_destroy (pp->yyscanner);
    return par;
}
%}
%defines

%pure_parser
%parse-param {parse_parm *parm}
%parse-param {void *scanner}
%lex-param {yyscan_t *scanner}

%start input
%token <ival> IP
%token <ival> QUIT SPACE DIGIT
%token <bval> BINIP badrs
%type <ch> adrs
%union {
    int ch[4];
    int ival;
    short bval[8];
}
%%
input	: /*	*/
	| input '\n'
        { start(parm->line_count); }
	| input state
	| input QUIT
	{ YYACCEPT; }
	| input error
        ;

state	: adrs
        {
            s1 = transform($1);
            m = find (s1, parm->rb);
            printf ("\t");
            printip ($1);
            if ( m ) printf ("\tis exist (%d)\n", m);
            else printf ("\tno\n");
	}
	| adrs'-'adrs
	{
            s1 = transform ($1);
            s2 = transform ($3);
            if (Sorted (&s1, &s2, parm)) YYABORT;
            else {
                printf ("\tadd : ");
                printip ($1);
                printf (" - ");
                printip ($3);
                printf ("\n");
            }
	}
	| adrs'/'IP
	{
            k = $3;
            if (k>32) yyerror (*parm, "Bad range");
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

            if ( Sorted (&s1,&s2,parm) ) YYABORT;
            else {
                printf ("\tadd : ");
                printip (ch1);
                printf (" - ");
                printip (ch2);
                printf ("\n");
            }
	}
        | badrs
        ;

adrs	: IP'.'IP'.'IP'.'IP
	{
            $$[0] = $1;
            $$[1] = $3;
            $$[2] = $5;
            $$[3] = $7;
	}
	;
%%

int yyerror (parse_parm pp, const char *s)
{
    fprintf (stderr, "\tERROR: %s\n", s);
    return 0;
}

void decToBin (int *ch, short *arr)
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

void binToDec (short arr[], int ch[])
{
    int p, i, j, pow;
    pow = 1;
    for (i=0; i<4; i++){
        p = 0;
        for (j=0; j<8; j++){
            p += (*arr) * (pow << j);
            arr++;
        }
        ch[3-i] = p;
    }
}

int Sorted (unsigned *s1, unsigned *s2, parse_parm *pp)
{
    int k;
    if (*s1 <= *s2){
        k = findconflict (*s1, *s2, pp->rb);
        if (!k){
            AddAddress (s1, s2, pp);
        }else {
            printf ("\tConflict lines: %d\n", k);
            return 1;
        }
    } else {
        yyerror (*pp, "s1>s2!");
        return 1;
    }
    return 0;
}

void printip (int *ch)
{
    int i;
    for (i=0; i<4; i++){
        printf ("%d", *ch);
        ch++;
        if (i != 3) printf (".");
    }
}
