#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "parser.h"

extern int line_count;
extern FILE *stdin;
extern FILE *old_stdin;
extern int start (void);

extern int yyparse (void);
extern int yyerror (const char*);
#endif
