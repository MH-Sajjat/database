%{
#include<stdio.h>
int flag=0;
%}
  
%token NUMBER
  
%left '+' '-'
  
%left '*' '/' '%'
  
%left '(' ')'
  
%%
  
line	: exp { printf("\nResult=%d\n", $1); return 0;};
 exp	: exp '+' exp {$$ = $1 + $3;}
 	|exp '-' exp {$$ = $1 - $3;}
 	|exp '*' exp {$$ = $1 * $3;}
 	|exp '/' exp {
 		if ($3 != 0) {
 			$$ = $1 / $3;
 		} else {
 			printf("Error: devided by zero\n");
 		}
 	}
 	|exp '%' exp {$$ = $1 % $3;}
 		
 	| '(' exp ')' {$$ = $2;}
 	| NUMBER {$$ = $1;}
 	;

%%
  
void main() {
	yyparse();
	if(flag==0)
	printf("\nEntered arithmetic expression is Valid\n\n");
}
  
void yyerror() {
	printf("\nEntered arithmetic expression is Invalid\n\n");
	flag=1;
}
