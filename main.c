#include "main.h"
#include <list>
char str[4];
list<string> slist;
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
	for (i=0; i<5; i++) {
		Out (*iter);
		iter++;
	}
	return 0;
}
