%{
%}
gwnia [gG][ow]nia|G[OW]NIA
trigwno [tT]rig[ow]no|TRIG[OW]NO
tetragwno [tT]etrag[ow]no|TETRAG[OW]NO
dinetai [dD]inet(ai|e)|DINET(AI|E)
%%
^{dinetai}[ \t]*$ {printf("\nSfalma! Den dwthike gewmetrikh ontothta kai onoma gewmetrikhs ontothtas: %s\n\n", yytext);}
^{dinetai}[ \t]*({gwnia}|{trigwno}|{tetragwno})[ \t]*$ {printf("\nSfalma! Den dwthike onoma gewmetrikhs ontothtas : %s\n\n", yytext);}
^{dinetai}[ \t]*([a-zA-Z]{1,4})[ \t]*$ {printf("\nSfalma! Den dwthike gewmetrikh ontothta : %s\n\n", yytext);}
{dinetai} {printf("\n%s : einai rhma\n", yytext);}
{gwnia}|{trigwno}|{tetragwno} {printf("\n%s : einai gewmetrikh ontothta\n", yytext);}
[a-eA-E]*[aA][a-eA-E]*[aA][a-eA-E]*|[a-eA-E]*[bB][a-eA-E]*[bB][a-eA-E]*|[a-eA-E]*[cC][a-eA-E]*[cC][a-eA-E]*|[a-eA-E]*[dD][a-eA-E]*[dD][a-eA-E]*|[a-eA-E]*[eE][a-eA-E]*[eE][a-eA-E]* {printf("\nSfalma: epanalhpsh grammatos sthn gewmetrikh ontothta %s\n", yytext);}
{gwnia}[ \t]*[a-eA-E][a-eA-E]+|{trigwno}[ \t]*[a-eA-E]{1,2}\n|{trigwno}[ \t]*[a-eA-E]{4,}|{tetragwno}[ \t]*[a-eA-E]{1,3}\n|{tetragwno}[ \t]*[a-eA-E]{5,} {printf("\nAdynatos syndiasmos : %s\n", yytext);}
[a-eA-E] {printf("\n%s : einai onoma gewmetrikhs ontothtas\n", yytext);}
[a-eA-E]{2}
[a-eA-E]{3,4} {printf("\n%s : einai onoma gewmetrikhs ontothtas\n", yytext);}
[a-eA-E]{5}
[ \t\n]
.
%%
main() {
   yylex();
}
