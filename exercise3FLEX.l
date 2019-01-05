%{
%}
var [vV]ar|VAR
integer [iI]nteger|INTEGER
real [rR]eal|REAL
boolean [bB]oolean|BOOLEAN
char [cC]har|CHAR
variableTypes {integer}|{real}|{boolean}|{char}
variableNames ([A-Za-z][A-Za-z0-9]*[ \t]*)([ \t]*","[ \t]*[A-Za-z][A-Za-z0-9]*)*
%%
^{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*(";")[ \t]*)+$ {printf("\nVariable declaration: %s\n",yytext);}
^{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes})([ \t]*";"[ \t]*{variableNames}[ \t]*(":")[ \t]*{variableTypes})*$ {printf("\nError: You forgot a ';'\n");}
.
%%
main() {
   yylex();
}
