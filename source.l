%{
#include "main.h"
char s[3];
int i, j;
%}

OCTET	[0-9]{1,3}
BIN	[01]{8,8}
CLASSIP	{SPACE}*({OCTET}{DOT}){3,3}{OCTET}{SPACE}*
BINIP	{SPACE}*({BIN}{DOT}){3,3}{BIN}{SPACE}*
SPACE	[' '\t]
DOT	\.

%%
^{CLASSIP}\n {
	for (i=0; i<13; i+=4){
		for (j=0; j<3; j++) s[j] = yytext[i+j];
		if (atoi(s) >255) printf("ERROR\n");
		switch (i % 4){
			case 0: adrs.A = atoi(s);
				break;
			case 1: adrs.B = atoi(s);
				break;
			case 2: adrs.C = atoi(s);
				break;
			case 3: adrs.D = atoi(s);
				break;
		}
	}
	printf ("class ip: %s\n", yytext);
	yylval.ch = yytext;
	return IP;
}

^{BINIP}$ ECHO;

.|\n
%%
int yywrap ()
{
	return 1;
}
