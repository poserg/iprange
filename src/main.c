#include "main.h"
list slist;
int line_count = 1;
FILE *old_stdin = stdin;

int pow (int x, int k){
    int i, s;
    s = 1;
    for (i=0; i<k; i++) s*=x;
    return s;
}

unsigned transform (int *ch){
    int i;
    unsigned s = 0;
    for (i=0; i<4; i++){
        s += *ch * pow(2, 8*(3-i));
        ch++;
    }
    return s;
}

void untransform (unsigned* s, int *ch)
{
    int i;
    for (i=0; i<4; i++){
        *ch = *s/pow(2, 8*(3-i));
        *s = *s%pow(2, 8*(3-i));
        ch++;
    }
}

void AddAddress (unsigned* s1, unsigned* s2, int* line)
{
    IPRange ipr;
    ipr.first = *s1;
    ipr.last = *s2;
    ipr.line = *line_count;
    slist.push_back(ipr);
}

int find (unsigned& item)
{
    int i;
    list::Data* iter = slist.head;
    while ( iter ){
        if (item >= iter->ipr.first && item <= iter->ipr.last) return iter->ipr.line;
        iter = iter->next;
    }
    return 0;
}

int main (int argc, char* argv[])
{
    IPRange k;
    if ( argv[1] ){
        if ((stdin = fopen (argv[1], "r")) == NULL){
            printf ("Can't open file %s\n", argv[1]);
            stdin = old_stdin;
        }
    }
    start();
    yyparse();
    return 0;
}

int start()
{
    printf ("line %d: ", line_count);
    return 0;
}
