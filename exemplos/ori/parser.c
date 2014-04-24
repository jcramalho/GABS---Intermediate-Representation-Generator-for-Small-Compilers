/*
 * ori.c
 * Recursive descencent Parser for Orienteering Courses
 */
 
#include <stdio.h>
#include "tokens.h"
#include "ori.h"

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
OProva rec_OProva();
ListaPontos rec_ListaPontos();
ListaPercursos rec_ListaPercursos();
Pontos rec_Pontos();
Pontos2 rec_Pontos2();
Ponto rec_Ponto();
IdPonto rec_IdPonto();
CoordX rec_CoordX();
CoordY rec_CoordY();
Percursos rec_Percursos();
Percursos2 rec_Percursos2();
Percurso rec_Percurso();
IdPercurso rec_IdPercurso();
ListaRefs rec_ListaRefs();
ListaRefs2 rec_ListaRefs2();

/* ------------------------------------------- */
/* ----
   THE PARSER
   -----
*/

main()
{ OProva res;

  prox_simb = da_simbolo();
  res = rec_OProva();
  printf("\n\nOK\n\n");
  // showExp(res);
  // codeGeneration(res);
} 


OProva rec_OProva()
{
  OProva aux;
  ListaPontos v1;
  ListaPercursos v2;

 rec_term(PROVA);
  v1 = rec_ListaPontos();
  v2 = rec_ListaPercursos();
  rec_term(FIM);
  aux = cons_OProva(v1,v2);
  
  return(aux);
}


ListaPontos rec_ListaPontos()
{
  ListaPontos aux;
  Pontos v1;

  rec_term(PONTOS);
  v1 = rec_Pontos();
  rec_term(FPONTOS);

  aux = cons_ListaPontos(v1);
  return(aux);
}


ListaPercursos rec_ListaPercursos()
{
  ListaPercursos aux;
  Percursos v1;

  rec_term(PERCURSOS);
  v1 = rec_Percursos();
  rec_term(FPERCURSOS);

  aux = cons_ListaPercursos(v1);
  return(aux);
}


Pontos rec_Pontos()
{
  Pontos aux;
  Ponto v1;
  Pontos2 v2;

  v1 = rec_Ponto();
  v2 = rec_Pontos2();
  
  aux = cons_Pontos(v1,v2);
  return(aux);
}


Pontos2 rec_Pontos2()
{
  Pontos2 aux;
  Ponto v1;
  Pontos2 v2;

  switch(prox_simb)
  {
    case FPONTOS: aux = cons_Pontos2_NIL();
                  break;
    case PVIRG  : rec_term(PVIRG);
                  v1 = rec_Ponto();
                  v2 = rec_Pontos2();
                  aux = cons_Pontos2(v1,v2);
                  break;
    default     : error();
  }
  return(aux);
}


Ponto rec_Ponto()
{
  Ponto aux;
  IdPonto v1;
  CoordX v2;
  CoordY v3;

  rec_term(OPAR);
  v1 = rec_IdPonto();
  rec_term(VIRG);
  v2 = rec_CoordX();
  rec_term(VIRG);
  v3 = rec_CoordY();
  rec_term(CPAR);

  aux = cons_Ponto(v1,v2,v3);
  return(aux);
}


IdPonto rec_IdPonto()
{
  IdPonto aux;
  char *v1;

  v1 = rec_term(ID);
  aux = cons_IdPonto(v1);
  return(aux);
}


CoordX rec_CoordX()
{
  CoordX aux;
  int v1;

  v1 = atoi(rec_term(INT));
  aux = cons_CoordX(v1);
  return(aux);
}


CoordY rec_CoordY()
{
  CoordY aux;
  int v1;

  v1 = atoi(rec_term(INT));
  aux = cons_CoordY(v1);
  return(aux);
}


Percursos rec_Percursos()
{
  Percursos aux;
  Percurso v1;
  Percursos2 v2;

  v1 = rec_Percurso();
  v2 = rec_Percursos2();
  
  aux = cons_Percursos(v1,v2);
  return(aux);
}


Percursos2 rec_Percursos2()
{
  Percursos2 aux;
  Percurso v1;
  Percursos2 v2;

  switch(prox_simb)
  {
    case FPERCURSOS : aux = cons_Percursos2_NIL();
                      break;
    case PVIRG  : rec_term(PVIRG);
                  v1 = rec_Percurso();
                  v2 = rec_Percursos2();
                  aux = cons_Percursos2(v1,v2);
                  break;
    default     : error();
  }
  return(aux);
}


Percurso rec_Percurso()
{
  Percurso aux;
  IdPercurso v1;
  char* v2;
  ListaRefs v3;

  v1 = rec_IdPercurso();
  rec_term(DOIS);
  v2 = rec_term(ID);
  rec_term(DOIS);
  v3 = rec_ListaRefs();
  rec_term(UM);

  aux = cons_Percurso(v1,v2,v3);
  return(aux);
}


IdPercurso rec_IdPercurso()
{
  IdPercurso aux;
  char *v1;

  v1 = rec_term(ID);
  aux = cons_IdPercurso(v1);
  return(aux);
}


ListaRefs rec_ListaRefs()
{
  ListaRefs aux;
  IdPonto v1;
  ListaRefs2 v2;

  v1 = rec_IdPonto();
  v2 = rec_ListaRefs2();

  aux = cons_ListaRefs(v1,v2);
  return(aux);
}


ListaRefs2 rec_ListaRefs2()
{
  ListaRefs2 aux;
  IdPonto v1;
  ListaRefs2 v2;

  switch(prox_simb)
  {
    case UM : aux = cons_ListaRefs2_NIL();
              break;

    case VIRG : rec_term(VIRG);
                v1 = rec_IdPonto();
                v2 = rec_ListaRefs2();
                aux = cons_ListaRefs2(v1,v2);
                break;

    default : error();
  }
  return(aux);
}

/* ------------------------------------------- */
