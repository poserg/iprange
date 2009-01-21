#include "main.h"
IPAddress adrs;
int main (int argc, char *argv[])
{
	printf ("%d - argc\n", argc);
	yyparse();
	argv=NULL;
	yyparse();
	printf ("%d\n", adrs.A);
	return 0;
}

