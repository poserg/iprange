#include "main.h"
#include <list>
list<IPRange> slist;
int line_count = 1;
FILE *old_stdin = stdin;

unsigned pow (int x, int k){
    int i;
    unsigned s;
    s = 1;
    for (i=0; i<k; i++) s*=x;
    return s;
}

unsigned func (int *ch){
    int i;
    unsigned s = 0;
    for (i=0; i<4; i++){
        s += *ch * pow(2, 8*(3-i));
        ch++;
    }
    return s;
}

void unfunc (unsigned s, int *ch)
{
    int i;
    for (i=0; i<4; i++){
        *ch = s/pow(2, 8*(3-i));
        s=s%pow(2, 8*(3-i));
        ch++;
    }
}

void AddAddress (unsigned& s1, unsigned& s2, int& line)
{
    IPRange ipr;
    ipr.first = s1;
    ipr.last = s2;
    ipr.line = line_count;
    slist.push_back(ipr);
}

int find (unsigned& item)
{
    int i;
    list<IPRange>::iterator iter;
    iter = slist.begin();
    while ( iter != slist.end() ){
        if (item >= iter->first && item <= iter->last) return iter->line;
        iter++;
    }
    return 0;
}

int main (int argc, char* argv[])
{
    IPRange k;
    list<IPRange>::iterator iter;

    if ( argv[1] ){
        if ( (stdin = fopen (argv[1], "r")) == NULL){
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
