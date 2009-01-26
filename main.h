#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "y.tab.h"
#include <string>

using namespace std;

extern int yylex(void);
extern int yyparse(void);
extern int yyerror(const char *);

extern int flag;

typedef struct _IPAddress {
	char A;
	char B;
	char C;
	char D;
} IPAddress;

extern IPAddress adrs;
extern char str[4];
extern void AddAddress ( unsigned& item);
extern unsigned func (char *ch);
extern void unfunc (unsigned s, int* ch);
extern unsigned pow (int x, int k);
extern int find (unsigned& item);

#endif
