#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

using namespace std;

extern int yylex(void);
extern int yyparse(void);
extern int yyerror(const char *);
extern void decToBin (char*, int*);
extern void binToDec (int*, char*);
extern void Sorted (unsigned&, unsigned&);

extern int flag;

typedef struct _IPAddress {
	char A;
	char B;
	char C;
	char D;
} IPAddress;

extern void AddAddress ( unsigned& item);
extern unsigned func (char *ch);
extern void unfunc (unsigned s, int* ch);
extern unsigned pow (int x, int k);
extern int find (unsigned& item);

#endif
