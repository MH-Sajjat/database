%{
int x = 0, y = 0;
%}

%%

. {++x;}

\n {++x; ++y;}

%%

int yywrap() {
	return 1;
}

int main() {
	yylex();
	printf("%d %d\n", x, y);
	return 0;
}

