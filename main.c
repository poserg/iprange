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
void unfunc (unsigned s, char& ch)
{
	int i;
	for (i=0; i<4; i++){
		ch = s/pow(2, 8*(3-i));
		printf ("%c\n", ch);
	}
}
void Out (unsigned& s)
{
		printf ("%u\n", s);
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
	while (iter++ != slist.end())
		if ( *iter == item ) cout << 1 << '\n';
	cout << 0 << '\n';
	return 0;
}
int main(void)
{
	int flag;
	int i;
	string str;
	list<unsigned>::iterator iter; 
	yyparse();
	//slist.push_back (str);
	iter = slist.begin();
	//cout << *iter << " | in main\n";
	for (i=0; i<slist.size(); i++) {
		Out (*iter);
		iter++;
	}
	cout << "i = " << i << '\n';
	it = 2063729409;
	//find (it);
	//cout << find(it) << '\n';
	return 0;
}
