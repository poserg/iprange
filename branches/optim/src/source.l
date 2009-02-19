%{
#include "main.h"
#define parm yyget_extra (scanner)
int flag = 0;
int j;
%}
%option reentrant bison-bridge
DIGIT	[0-9]
OCTET	{DIGIT}{1,3}
BIN	[01]{8,8}
CLASSIP	{SPACE}*({OCTET}{DOT}){3,3}{OCTET}{SPACE}*
BINIP	{SPACE}*({BIN}{DOT}){3,3}{BIN}{SPACE}*
SPACE	[' '\t]
DOT	\.
QUIT	^{SPACE}*[Qq][Uu][Ii][Tt]{SPACE}*$
RESERV	[-\:\.\/]
LETTER  [A-z]+

%%
{OCTET} {
	yylval->ival = atoi (yytext);
	if (yylval->ival > 255) yyerror ("Octet wasn't bigger 255");
	return IP;
}      

{BIN} {
      for (j=0; j<yyleng; j++){
          yylval->bval[j] = yytext[j] - '0';
      }
      return BINIP;
}      

\n {
   return '\n';
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

[^{OCTET}{SPACE}{RESERV}] {
                          //yyerror ("SYNTAX ERROR");
}
%%
int yywrap (yyscan_t scanner)
{
        if ( parm->old_stdin && ! flag) {
                yyset_in (parm->old_stdin, scanner);
                flag++;
                return 0;
        } else return 1;
        return 1;
}

