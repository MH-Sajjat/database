
%{
#include <ctype.h>
#include <stdio.h>
int flag = 0;
%}

%token NUMBER

%%

line	: expr '\n' {printf("ouput value: %d\n", $1);}
	;
expr	: expr '+' term {$$ = $1 + $3;}
	| term {$$ = $1;}
	;
term 	: term '*' factor {$$ = $1 * $3;}
	| factor {$$ = $1;}
	;
factor	: '(' expr ')' {$$ = $2;}
	| NUMBER {$$ = $1;}
	;
%%


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
