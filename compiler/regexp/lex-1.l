%{
#include "y.tab.h"
extern int yylval;
%}

%%

[0-9] {
	yylval = yytext[0] - '0';
	return DIGIT;
}

[\t] {}

. {return yytext[0];}

\n {return yytext[0];}

%%

int yywrap() {
return 1;
}
