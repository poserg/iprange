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
extern int Sorted (unsigned&, unsigned&);

extern int line_count;
extern FILE *old_stdin;
extern void AddAddress ( unsigned&, unsigned&, int& );
extern unsigned transform (int*);
extern void untransform (unsigned , int*);
extern unsigned pow (int, int );
extern int find (unsigned&);
extern int start (void);

typedef struct IPRange {
    unsigned first;
    unsigned last;
    int line;
};

#endif
