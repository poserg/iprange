#include "main.h"
IPAddress adrs;
int main (int argc, char *argv[])
{
	int flag;
	flag = (argc>1)?0:1;
	printf ("%d - argc\n", argc);
	yyparse();
	argv=NULL;
	printf ("%d\n", adrs.A);
	//yyparse(); //?
	return 0;
}

