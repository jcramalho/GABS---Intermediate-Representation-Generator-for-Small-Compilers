/*
 * exp.c
 * Recursive descencent Parser for Simple Aritmetic Expressions
 */

#include <stdio.h>
#include "tokens.h"
#include "exp.h"
#include "anasem.h"

extern int yylex();

static int prox_simb;

int da_simbolo()
{ return yylex(); }

char* rec_term(int simb)
{ char *aux;

  if(prox_simb == simb)
  {
	aux = lexval;
	prox_simb = da_simbolo();
	return aux;
  }
  else{
	fprintf(stderr, "ERROR: unexpexpected token = %d",prox_simb);
	exit(1);
  }
}


void error()
{ fprintf(stderr, "ERROR: Syntactic, near - %d", prox_simb);
  exit(2);
}


/* ----
   Parser functions declaration
   ----
*/
Exp rec_Exp();
Exp2 rec_Exp2();

/* ------------------------------------------- */
/* ----
   THE PARSER
   -----
*/

main()
{ Exp res;

  prox_simb = da_simbolo();
  res = rec_Exp();
  rec_term(FIM);
  printf("\n\nOK\n\n");
  // showExp(res);
  preshowExp(res);
  // codeGeneration(res);
}


Exp rec_Exp()
{ Exp aux;
  int v1;
  Exp2 v2;

  v1 = atoi(rec_term(INT));
  v2 = rec_Exp2();
  aux = cons_Exp(v1, v2);

  return aux;
}


Exp2 rec_Exp2()
{
  Exp2 aux;
  int v1;
  Exp v2;

  switch(prox_simb)
  {
	case SOMA : rec_term(SOMA);
				v2 = rec_Exp();
				aux = cons_Soma(v2);
				break;
	case SUB : rec_term(SUB);
				v2 = rec_Exp();
				aux = cons_Sub(v2);
				break;
	case FIM :
			   aux = cons_NIL();
			   break;
	default  : error();
  }


  return(aux);
}
