%{
#include "y.tab.h"
extern int yylval;
%}

digit [0-9]

%%

{digit}+ {
	yylval = atoi(yytext);
	return NUMBER;
}

[\t] {}

. {return yytext[0];}

\n {return yytext[0];}

%%

int yywrap() {
return 1;
}
