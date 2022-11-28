
%{
#include <ctype.h>
#include <stdio.h>
int flag = 0;
int yylex();
%}

%token DIGIT

%%

line	: expr '\n' {printf("ouput value: %d", $1);}
	;
expr	: expr '+' term {$$ = $1 + $3;}
	| term {$$ = $1;}
	;
term 	: term '*' factor {$$ = $1 * $3;}
	| factor {$$ = $1;}
	;
factor	: '(' expr ')' {$$ = $2;}
	| DIGIT {$$ = $1;}
	;
%%

int yylex() {
	int c;
	c = getchar();
	if (isdigit(c)) {
		yylval = c - '0';
		return DIGIT;
	}
	return c;
}

void yyerror() {
	printf("entered expression is invalid\n");
	flag = 1;
}

int main() {
	yyparse();
	if (flag == 0) {
		printf("Entered expression is valid\n");
	}
}
