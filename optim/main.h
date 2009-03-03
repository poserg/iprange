#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <redblack.h>
#include "parser.h"

extern int start (int*);
extern void* malloc (unsigned);
extern void* calloc (unsigned, unsigned);

typedef	struct parse_parm_s
{
    void *yyscanner;
    FILE *old_stdin;
    struct rbtree *rb;
    int *line_count;
    int *count;
} parse_parm;

int parse (parse_parm *);

#define YY_EXTRA_TYPE parse_parm*
#endif
