%{
#include "tokens.h"
%}

%%
PROVA      return(PROVA);
FIM        return(FIM);
PONTOS     return(PONTOS);
FPONTOS    return(FPONTOS);
\;         return(PVIRG);
\(         return(OPAR);
\)         return(CPAR);
\,         return(VIRG);
PERCURSOS  return(PERCURSOS);
FPERCURSOS return(FPERCURSOS);
\:         return(DOIS);
\.         return(UM);


[0-9]+               {lexval = strdup(yytext); return(INT); }
[a-zA-Z][a-zA-Z0-9]+ {lexval = strdup(yytext); return(ID);}


.          return(ERRO);

<<EOF>>    return(0);
