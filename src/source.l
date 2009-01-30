%{
#include "main.h"
int flag = 0;
int j;
%}
DIGIT	[0-9]
OCTET	{DIGIT}{1,3}
BIN	[01]{8,8}
CLASSIP	{SPACE}*({OCTET}{DOT}){3,3}{OCTET}{SPACE}*
BINIP	{SPACE}*({BIN}{DOT}){3,3}{BIN}{SPACE}*
SPACE	[' '\t]
DOT	\.
QUIT	^{SPACE}*[Qq][Uu][Ii][Tt]{SPACE}*$
RESERV	[-\n\:\.\/]
LETTER  [A-z]+

%%
{OCTET} {
	yylval.ival = atoi (yytext);
	if (yylval.ival > 255) yyerror ("Octet wasn't bigger 255");
	return IP;
}      

{BIN} {
      for (j=0; j<yyleng; j++){
          yylval.bval[j] = yytext[j] - '0';
      }
      return BINIP;
}      

{RESERV} {
	return yytext[0];
}

{QUIT} {
	return QUIT;
}

{DOT}+ {
	yyerror ("More dot");
}

{LETTER} {
         yyerror ("syntax error");
}

.|\n {
	//yyerror ("Syntax error!");
}
%%
int yywrap ()
{
        if (flag == 0){
                yyrestart(old_stdin);
                flag = 1;
                return 0;
        } else return 1;
}
