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
extern void Sorted (unsigned&, unsigned&);

extern int line_count;
extern void AddAddress ( unsigned&, unsigned&, int& );
extern unsigned func (int*);
extern void unfunc (unsigned , int*);
extern unsigned pow (int, int );
extern int find (unsigned&);
extern int start (void);

typedef struct _IPRange {
    unsigned first;
    unsigned last;
    int line;
} IPRange;

#endif
