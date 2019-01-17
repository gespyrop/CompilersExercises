%{
	int decStart = 0;
%}
var [vV]ar|VAR
integer [iI]nteger|INTEGER
real [rR]eal|REAL
boolean [bB]oolean|BOOLEAN
char [cC]har|CHAR
variableTypes {integer}|{real}|{boolean}|{char}
variableNames ([A-Za-z][A-Za-z0-9]*[ \t]*)([ \t]*","[ \t]*[A-Za-z][A-Za-z0-9]*)*
%%
{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*(";")[ \t\n]*)+ {printf("\nVariables declaration:\n%s\n\n",yytext); decStart = 1;}
({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*(";")[ \t\n]*)+ {if(decStart == 1) printf("\nVariables declaration:\n%s\n\n",yytext); else printf("\nYou forgot the keyword var:\n%s\n\n",yytext);}
[ \t]*{variableNames}[ \t]*(":")[ \t]*[A-Za-z0-9]+[ \t]*(";")[ \t\n]* {if(decStart == 1) printf("\nUnrecognized variable type:\n%s\n\n",yytext);}
[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t\n]*)+ {if(decStart == 1) printf("\nYou forgot a ';':\n %s\n\n",yytext); }
({variableNames}[ \t]+{variableTypes}[ \t]*(";")[ \t\n]*)+ {if(decStart == 1) printf("\nYou forgot a ':':\n %s\n\n",yytext); }
({variableNames}[ \t]+{variableTypes}[ \t\n]*)+ {if(decStart == 1) printf("\nYou forgot a ':' and ';':\n %s\n\n",yytext); }
[ \t\n]+
.
%%
main() {
   yylex();
}
