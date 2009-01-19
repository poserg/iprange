%{
//main.h;
%}

CLASSIP	[0-9]{1,3}
IP	{SPACE}*{CLASSIP}{DOT}{CLASSIP}{DOT}{CLASSIP}{DOT}{CLASSIP}{SPACE}*
SPACE	[' '\t]
DOT	\.

%%
^{CLASSIP}\n ECHO;

^{IP}$	ECHO;

.|\n

