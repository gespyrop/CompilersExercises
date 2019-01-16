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
^{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*(";")[ \t]*)+$ {printf("\nVariable declaration: %s\n\n",yytext);}
^{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes})([ \t]*";"[ \t]*{variableNames}[ \t]*(":")[ \t]*{variableTypes})*$ {printf("\nError: You forgot a ';'\n\n");}
^{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableNames}[ \t]*(";")[ \t]*)+$ {printf("\nError: Unrecognized variable type\n\n");}
^{var}[ \t]+({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*)+$ {printf("\nError: You forgot ';'\n\n");}
^{var}[ \t]+({variableNames}[ \t]*{variableTypes}[ \t]*(";")[ \t]*)+$ {printf("\nError: You forgot ':'\n\n");}
^{var}[ \t]+({variableNames}[ \t]*{variableTypes}[ \t]*)+$ {printf("\nError: You forgot a ':' and a ';'\n\n");}
({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*(";")[ \t]*)+$ {printf("\nError: You forgot the keyword 'var'\n\n");}
({variableNames}[ \t]*(":")[ \t]*{variableNames}[ \t]*(";")[ \t]*)+$ {printf("\nError: Unrecognized variable type\nYou forgot the keyword 'var'\n\n");}
({variableNames}[ \t]*{variableTypes}[ \t]*(";")[ \t]*)+$ {printf("\nError: Unrecognized variable declaration\n\n");}
({variableNames}[ \t]*{variableTypes}[ \t]*)+$ {printf("\nError: Unrecognized variable declaration\n\n");}
({variableNames}[ \t]*(":")[ \t]*{variableTypes}[ \t]*) {printf("\nError: Unrecognized variable declaration\n\n");}
[\t\n]+
.
%%
main() {
   yylex();
}
