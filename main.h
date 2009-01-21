#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

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

#endif
