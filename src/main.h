#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include "parser.h"

extern int line_count;
extern int start (void);

#define YY_EXTRA_TYPE FILE*

//extern int yyparse (void*);

typedef	struct parse_parm_s
	{
		void *yyscanner;
		FILE *old_stdin;
	} parse_parm;

void parse (parse_parm *);
#endif
