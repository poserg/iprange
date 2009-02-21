/*
$Rev::                       $: Revision of last commit
$Author::                    $: Author of last commit
$Date::                      $: Date of last commit
*/

#include "main.h"

int compare(const void *pa, const void *pb, const void *config)
{
    if(*(unsigned *)pa < *(unsigned *)pb) return -1;
    if(*(unsigned *)pa > *(unsigned *)pb) return 1;
    return 0;
}

int main (int argc, char* argv[])
{
    struct rbtree *rb;
    extern FILE *stdin;
    FILE *old_stdin;
    parse_parm pp;
    unsigned tmp = 0;
    unsigned *ptr;
    int *line_count = malloc (sizeof (int));
    if (line_count == NULL) {
        yyerror (pp, "No memmory!");
        return 1;
    }

    rb = rbinit (compare, NULL);

    old_stdin = stdin;
    if ( argv[1] ){
        if ((stdin = fopen (argv[1], "r")) == NULL){
            printf ("Can't open file %s\n", argv[1]);
            stdin = old_stdin;
            old_stdin = 0;
        }
    } else old_stdin = 0;

    //old_stdin = 0; //need for genRightIP.sh

    pp.old_stdin = old_stdin;
    pp.line_count = line_count;
    pp.rb = rb;

    *line_count = 0;
    start(line_count);

    tmp = parse(&pp);

    free (line_count);
    rbdestroy (rb);

    return tmp;
}

int start(int *line_count)
{
    printf ("line %d: ", ++(*line_count));
    return 0;
}
