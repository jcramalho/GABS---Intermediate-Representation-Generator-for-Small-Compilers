%%
[ \t] ;
[0-9]+  { lexval = strdup(yytext); return(INT); }
\+      return(SOMA);
\-      return(SUB);
\n      return(FIM);

.       return(ERRO);

<<EOF>> return(0);
