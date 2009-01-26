#include "main.h"
#include <list>
unsigned it;
list<unsigned> slist;

unsigned pow (int x, int k){
	int i; 
	unsigned s;
	s = 1;
	for (i=0; i<k; i++) s*=x;
	return s;
}

unsigned func (char *ch){
	int i,j,k;
	unsigned s;
	s = 0;
	for (i=0; i<4; i++){	
		k = (*ch>=0)?(*ch):(256+*ch);
		s += pow(2, 8*(3-i))*k;
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

void AddAddress (unsigned& item)
{
	slist.push_back(item);
}

int find (unsigned& item)
{
	int i;
	list<unsigned>::iterator iter;
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
