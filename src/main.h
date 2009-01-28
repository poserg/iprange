#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

using namespace std;

extern int yylex(void);
extern int yyparse(void);
extern int yyerror(const char *);
extern void decToBin (int*, int*);
extern void binToDec (int*, int*);
extern void Sorted (long&, long&);

extern void AddAddress ( long&, long&, int& );
extern long func (int*);
extern void unfunc (long , int*);
extern long pow (int, int );
extern int find (long&);

typedef struct _IPRange {
    long first;
    long last;
    int line;
} IPRange;

#endif
