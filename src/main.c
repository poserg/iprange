#include "main.h"
#include <redblack.h>


int line_count = 1;
struct rbtree *rb;

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

void AddAddress (unsigned *s1, unsigned *s2, int *line)
{
    unsigned arr[3];
    unsigned *val;
    val = malloc (sizeof arr);
    val[0] = *s1;
    val[1] = *s2;
    val[2] = *line;
    rbsearch (val, rb);
}

int find (unsigned item)
{
    unsigned *ptr;
    printf ("item = %u\n", item);
    //ptr = rbfind (&item, rb);
    ptr = rblookup (RB_LULTEQ, &item, rb);
    if (ptr == NULL || ptr[1] <= item) return 0;
    else return ptr[2];
}

int compare(const void *pa, const void *pb, const void *config)
{
	if(*(int *)pa < *(int *)pb) return -1;
	if(*(int *)pa > *(int *)pb) return 1;
	return 0;
}

int main (int argc, char* argv[])
{
    extern FILE *stdin;
    FILE *old_stdin;
    void *v;
    /*
    struct parser_control
    {
        char old_stdin;
        int line;
    }

    struct parser_control ctrl;
    ctrl.old_stdin ="n";
    ctrl.line = line_count;
    */

    rb = rbinit (compare, NULL);
    old_stdin = stdin;
    if ( argv[1] ){
        if ((stdin = fopen (argv[1], "r")) == NULL){
            printf ("Can't open file %s\n", argv[1]);
        } else {
            //yyparse ((void *) &ctrl);
            yyparse (v);
            printf ("first parser finishing\n");
        }
        stdin = old_stdin;
    }
    start();
    yyparse (v);
    /*
    unsigned *ptr;
    for (ptr = rblookup (RB_LUFIRST, NULL, rb);
         ptr != NULL;
         ptr = rblookup (RB_LUNEXT, ptr, rb))
    {
        printf ("%u - %u;\t%d\n", ptr[0], ptr[1], ptr[2]);
    }
    */
    return 0;
}

int start()
{
    printf ("line %d: ", line_count);
    return 0;
}
