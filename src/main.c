/*
$Rev::                       $: Revision of last commit
$Author::                    $: Author of last commit
$Date::                      $: Date of last commit
*/

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
    ptr = (unsigned *)rblookup (RB_LULTEQ , &item, rb);
    if (ptr == NULL || ptr[1] < item) return 0;
    else return ptr[2];
}

int findconflict (unsigned item1, unsigned item2, struct rbtree *rb)
{
    unsigned *ptr;
    int val[2];

    val[0] = find (item1, rb);
    val[1] = find (item2, rb);
    if ( ! val[0] && ! val[1] ){
        ptr = (unsigned *)rblookup (RB_LULTEQ, &item2, rb);
        //if (ptr == NULL || ptr[0] <  item1){
        if (ptr == NULL || ptr[0] < item1) return 0;
        else return *(ptr+2);
    } else return val[0];
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

    AddAddress (&tmp, &tmp, &pp);

    *line_count = 0;
    start(line_count);

    return parse(&pp);

    free (line_count);
    rbdestroy (rb);

}

int start(int *line_count)
{
    printf ("line %d: ", ++(*line_count));
    return 0;
}
