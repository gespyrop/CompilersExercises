%{
%}
var [vV]ar|VAR
integer [iI]nteger|integer
real [rR]eal|REAL
boolean [bB]oolean|BOOLEAN
char [cC]har|CHAR
%%
{var}(" ")+([A-Za-z](":")|[A-Za-z0-9](" ")*(":"))({integer}|{real}|{boolean}|{char})(";") {printf("A variable was declared:\n %s",yytext);}
%%
main() {
   yylex();
}
