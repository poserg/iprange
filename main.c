#include "main.h"
#include <list>
using namespace std;
IPAddress adrs;
char adr[15];
void Out (string& s)
{
	cout << s << '\n';
}



void ListOut (list<string>& slist)
{
	list<string>::iterator iter = slist.begin();
	for ( ; iter != slist.end(); ++iter)
		cout << *iter << '\n';
	
}

void AddAddress (list<string>& list, IPAddress& adrs)
{
	string temp;// = ch[1]+ch[2]+ch[3]+'\0';
	list.push_back (temp);
}

int main(void)
{
	int flag;
	string str;
	list<string> slist;
	list<string>::iterator iter; 
	slist.push_back( "Hello");
	slist.push_back( "World");
	iter = slist.begin();
	for ( ; iter != slist.end(); ++iter)
		cout << *iter << '\n';
	str = *slist.begin();
	iter = slist.begin();
	Out (*iter);
	//Out (str);
	//Out (slist.begin());
	//flag = (argc>1)?0:1;
	//printf ("%d - argc\n", argc);
	yyparse();
	//argv=NULL;
	//printf ("%d\n", adrs.A);
	//yyparse(); //?
	AddAddress (slist, adrs);
	ListOut (slist);
	return 0;
}
