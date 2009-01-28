#include "main.h"
#include <list>
list<IPRange> slist;

long pow (int x, int k){
    int i;
    long s;
    s = 1;
    for (i=0; i<k; i++) s*=x;
    return s;
}

long func (int *ch){
    int i,j,k;
    long s;
    s = 0;
    for (i=0; i<4; i++){
        k = *ch;
        s += pow(2, 8*(3-i))*k;
        ch++;
    }
    return s;
}

void unfunc (long s, int *ch)
{
    int i;
    for (i=0; i<4; i++){
        *ch = s/pow(2, 8*(3-i));
        s=s%pow(2, 8*(3-i));
        ch++;
    }
}

void AddAddress (long& s1, long& s2, int& line)
{
    IPRange ipr;
    ipr.first = s1;
    ipr.last = s2;
    ipr.line = line;
    printf ("%d\t%d\t%d\n", ipr.first, ipr.last, ipr.line);
    slist.push_back(ipr);
}

int find (long& item)
{
    int i;
    list<IPRange>::iterator iter;
    iter = slist.begin();
    while (i < slist.size())
        //if ( *iter++ == item ) return 1;
    return 0;
}

int main(void)
{
    IPRange k;
    list<IPRange>::iterator iter;
    iter = slist.begin();

    yyparse();

    printf ("s1 = %d; s2 = %d; line = %d\n", iter->first, iter->last, iter->line);
    k = *iter++;
    printf ("%d\n", k.first);
    return 0;
}
