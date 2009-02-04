#include "main.h"
#include <map>

using namespace std;

int line_count = 1;
FILE *old_stdin = stdin;

struct elem{
    char flag;
    int line;
};

typedef map<unsigned, pair<char, int> > adrtype;
adrtype address;

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
    pair<char, int> p ('b', *line);
    address[*s1] = p;
    p = make_pair ('e', *line);
    address[*s2] =  p;
}

int find (unsigned& item)
{
    adrtype::iterator it;

    it = address.lower_bound (item);
    if (it->second.first == 'e' || it->first == item){
        return it->second.second;
    }else{
        return 0;
    }
}

int main (int argc, char* argv[])
{
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
