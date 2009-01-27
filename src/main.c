#include "main.h"
#include <list>
list<long> slist;

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

void AddAddress (long& item)
{
    slist.push_back(item);
}

int find (long& item)
{
    int i;
    list<long>::iterator iter;
    iter = slist.begin();
    while (iter != slist.end())
        if ( *iter++ == item ) return 1;
    return 0;
}

int main(void)
{
    yyparse();
    return 0;
}
