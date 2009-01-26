%{
#include "main.h"
int j;
int flag;
%}
OCTET	[0-9]{1,3}
BIN	[01]{8,8}
CLASSIP	{SPACE}*({OCTET}{DOT}){3,3}{OCTET}{SPACE}*
BINIP	{SPACE}*({BIN}{DOT}){3,3}{BIN}{SPACE}*
SPACE	[' '\t]
DOT	\.
QUIT	^{SPACE}*[Qq][Uu][Ii][Tt]$
RESERV	[-\n\:\.]

%%
{OCTET} {
	yylval.ival = atoi (yytext);
	if (yylval.ival > 255) yyerror ("ERROR!!!!");
	return IP;
}

^{BINIP}$ ECHO;

{RESERV} {
	return yytext[0];
}

{QUIT} {
	return QUIT;
}

{DOT}+ {
	yyerror ("More dot");
}

.|\n {
	yyerror ("Syntax error!");
}
%%
int yywrap ()
{
	if (flag) return flag;
	if (!flag) {
		flag = 1;
		return 0;
	}
}
