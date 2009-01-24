#include "main.h"
#include <list>
char str[4];
list<string> slist;

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
		k = (*ch>0)?(*ch):(256+*ch);
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
void Out (string s)
{
	int i;
	for (i=0; i<4; i++){
		printf ("%d.", (int)s[i]);
	}
	printf ("%c", '\n');
}

void AddAddress (char adrs[])
{
	slist.push_back(adrs);
}

int main(void)
{
	int flag;
	int i;
	string str;
	list<string>::iterator iter; 
	yyparse();
	slist.push_back (str);
	iter = slist.begin();
	//cout << *iter << " | in main\n";
	for (i=0; i<slist.size(); i++) {
		Out (*iter);
		iter++;
	}
	return 0;
}
