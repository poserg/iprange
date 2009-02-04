#include "main.h"
#include <map>

using namespace std;

typedef map <unsigned, char> adrtype;
adrtype address;
int line_count = 1;
FILE *old_stdin = stdin;

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
    address[*s1] = 'b';
    address[*s2] = 'e';
}

int find (unsigned& item)
{
    adrtype::iterator it;

    it = address.lower_bound (item);
    if (it->second =='e' || it->first == item){
        return 1;
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
