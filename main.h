#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "y.tab.h"
#include <string>
#include <vector>

using namespace std;

extern int yylex(void);
extern int yyparse(void);
extern int yyerror(const char *);

extern int flag;
extern char ch[3];

typedef struct _IPAddress {
	char A;
	char B;
	char C;
	char D;
} IPAddress;

extern IPAddress adrs;
extern char str[15];
//extern list<string> 

//extern void AddAddress (
#endif
