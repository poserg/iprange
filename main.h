#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

extern int yylex(void);
extern int yyparse(void);
extern int yyerror(const char *);

typedef struct _IPAddress {
	int A, B, C, D;
} IPAddress;

extern IPAddress adrs;

#endif
