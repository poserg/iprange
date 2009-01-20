#include "main.h"
IPAddress adrs;
int main()
{
	yyparse();
	printf ("%d\n", adrs.A);
	return 0;
}

