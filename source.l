%{
#include "main.h"
char ch[3];
int i;
%}

OCTET	[0-9]{1,3}
BIN	[01]{8,8}
CLASSIP	{SPACE}*({OCTET}{DOT}){3,3}{OCTET}{SPACE}*
BINIP	{SPACE}*({BIN}{DOT}){3,3}{BIN}{SPACE}*
SPACE	[' '\t]
DOT	\.
QUIT	^{SPACE}*[Qq][Uu][Ii][Tt]$

%%
{OCTET} {
	yylval = atoi (yytext);
	if (yylval > 255) yyerror ("ERROR!!!!");
	ch[0]=ch[1]=ch[2]=' ';
	for (i=0; i<yyleng; i++) ch[i] = yytext[i];
	printf ("++%d\n", atoi (ch));
	return IP;
}
^{BINIP}$ ECHO;

'\n' {
	return '\n';
}

\. {
	return '.';
}

{QUIT} {
	return QUIT;
}

.|\n
%%
int yywrap ()
{
	return 1;
}
