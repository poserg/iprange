/*
$Rev::                       $: Revision of last commit
$Author::                    $: Author of last commit
$Date::                      $: Date of last commit
*/

#include "main.h"

unsigned transform (int *ch){
    int i;
    unsigned s = 0;
    int pow = 1;
    for (i=0; i<4; i++){
        s += *ch * ( pow << ((3-i)*8) );
        ch++;
    }
    return s;
}

void AddAddress (unsigned *s1, unsigned *s2, parse_parm *pp)
{
    unsigned *val;
    val = calloc (3, sizeof (unsigned));
    if (val == NULL) yyerror (*pp, "No memory!");
    val[0] = *s1;
    val[1] = *s2;
    val[2] = *(pp->line_count);
    val = (unsigned *)rbsearch (val, pp->rb);
    free (val);
}

int find (unsigned item, struct rbtree *rb)
{
    unsigned *ptr;
    ptr = (unsigned *)rblookup (RB_LULTEQ, &item, rb);
    if (ptr == NULL || ptr[1] < item) return 0;
    else return ptr[2];
}

int findconflict (unsigned item1, unsigned item2, struct rbtree *rb)
{
    unsigned *ptr;
    ptr = (unsigned *)rblookup (RB_LULTEQ, &item1, rb);
    if (ptr == NULL || ptr[1] < item1){
        ptr = (unsigned *)rblookup (RB_LUNEXT, ptr, rb);
        if (ptr == NULL || ptr[0] > item2) return 0;
        else return ptr[2];
    } else return ptr[2];
}

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

    AddAddress (&tmp, &tmp, &pp);

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
