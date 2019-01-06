%{
%}
gwnia [gG][ow]nia|G[OW]NIA
trigwno [tT]rig[ow]no|TRIG[OW]NO
tetragwno [tT]etrag[ow]no|TETRAG[OW]NO
%%
^(([dD]inetai|DINETAI)\n|([dD]inetai|DINETAI)(" ")*({gwnia}|{trigwno}|{tetragwno}|[a-zA-Z]{1,4}))$ {printf("\nLathos protash : %s\n", yytext);}
[dD]inetai|DINETAI {printf("\n%s : einai rhma\n", yytext);}
{gwnia}|{trigwno}|{tetragwno} {printf("\n%s : einai gewmetrikh ontothta\n", yytext);}
{gwnia}[ \t]*[a-eA-E][a-eA-E]+|{trigwno}[ \t]*[a-eA-E]{1,2}\n|{trigwno}[ \t]*[a-eA-E]{4,}|{tetragwno}[ \t]*[a-eA-E]{1,3}\n|{tetragwno}[ \t]*[a-eA-E]{5,} {printf("\nAdynatos syndiasmos : %s\n", yytext);}
[a-eA-E] {printf("\n%s : einai onoma gewmetrikhs ontothtas\n", yytext);}
[a-eA-E]{2}
[a-eA-E]{3,4} {printf("\n%s : einai onoma gewmetrikhs ontothtas\n", yytext);}
[a-eA-E]{5}
.
%%
main() {
   yylex();
}
