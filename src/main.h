#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "list.c"

extern int line_count;
extern FILE *old_stdin;
extern int start (void);

extern int yyparse (void);
extern int yyerror (const char*);
#endif
