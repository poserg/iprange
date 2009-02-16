#include "main.h"

int power (int x, int k){
    int i, s;
    s = 1;
    for (i=0; i<k; i++) s*=x;
    return s;
}

unsigned transform (int *ch){
    int i;
    unsigned s = 0;
    for (i=0; i<4; i++){
        s += *ch * power(2, 8*(3-i));
        ch++;
    }
    return s;
}

void AddAddress (unsigned *s1, unsigned *s2, parse_parm *pp)
{
    unsigned *val;
    val = calloc (3, sizeof (unsigned));
    if (val == NULL) yyerror (pp, "No memory!\n");
    val[0] = *s1;
    val[1] = *s2;
    val[2] = *(pp->line_count);
    val = (int *)rbsearch (val, pp->rb);
}

int find (unsigned item, struct rbtree *rb)
{
    unsigned *ptr;
    //ptr = rbfind (&item, rb);
    ptr = (int *)rblookup (RB_LULTEQ, &item, rb);
    if (ptr == NULL || ptr[1] < item) return 0;
    else return ptr[2];
    //if (ptr == NULL) printf ("fsdfsdf\n");
    // else printf ("fsdfsdf   %u\n", ptr[0]);
    //return 0;
}

int compare(const void *pa, const void *pb, const void *config)
{
    if(*(int *)pa < *(int *)pb) return -1;
    if(*(int *)pa > *(int *)pb) return 1;
    return 0;
}

int main (int argc, char* argv[])
{
    struct rbtree *rb;
    extern FILE *stdin;
    FILE *old_stdin;
    int *line_count = malloc (sizeof (int));
    if (line_count == NULL) {
        printf ("No memmory!\n");
        return 1;
    }
    parse_parm pp;

    rb = rbinit (compare, NULL);
    old_stdin = stdin;
    if ( argv[1] ){
        if ((stdin = fopen (argv[1], "r")) == NULL){
            printf ("Can't open file %s\n", argv[1]);
            stdin = old_stdin;
            old_stdin = 0;
        }
    } else old_stdin = 0;

    pp.old_stdin = old_stdin;
    pp.line_count = line_count;
    pp.rb = rb;

    int tmp = 0;
    AddAddress (&tmp, &tmp, &pp);

    *line_count = 0;
    start(line_count);

    parse(&pp);

    free (line_count);

    return 0;
/*
    unsigned *ptr;

    for (ptr = rblookup (RB_LUFIRST, NULL, rb);
         ptr != NULL;
         ptr = rblookup (RB_LUNEXT, ptr, rb))
    {
        printf ("%u - %u;\t%d\n", ptr[0], ptr[1], ptr[2]);
    }
*/

}

int start(int *line_count)
{
    printf ("line %d: ", ++(*line_count));
    return 0;
}
