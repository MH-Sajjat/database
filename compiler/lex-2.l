%{
int cntLines = 0, cntChars = 0, cntInt = 0, cntFloat = 0;
%}
digit [0-9]

%%

{digit}+ {
	cntChars += yyleng;
	cntInt++;
	int num = atoi(yytext);
	printf("number %d found\n", num);
}

{digit}+\.{digit}+ {
	cntChars += yyleng;
	cntFloat++;
	float num = atof(yytext);
	printf("number %f found\n", num);
}

. {cntChars++;}
\n {cntLines++;}

%%

int yywrap() {
	return 1;
}

int main() {
	yylex();
	printf("chars = %d\n", cntChars);
	printf("lines = %d\n", cntLines);
	printf("int = %d\n", cntInt);
	printf("float = %d\n", cntFloat);
	return 0;
}
