#include "ori.h"

/* -----------------------------------
 * Constructor Function Implementations
 * -----------------------------------
 */

OProva  cons_OProva( ListaPontos a1, ListaPercursos a2)
{
    OProva aux0;

  aux0 = (OProva) malloc(sizeof(struct sOProva));
  aux0->flag = PScons_OProva;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}


ListaPontos  cons_ListaPontos( Pontos a1)
{
    ListaPontos aux0;

  aux0 = (ListaPontos) malloc(sizeof(struct sListaPontos));
  aux0->flag = PScons_ListaPontos;
  aux0->u.d1.s1 = a1;
  return(aux0);
}


Pontos  cons_Pontos( Ponto a1, Pontos2 a2)
{
    Pontos aux0;

  aux0 = (Pontos) malloc(sizeof(struct sPontos));
  aux0->flag = PScons_Pontos;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}


Pontos2  cons_Pontos2( Ponto a1, Pontos2 a2)
{
    Pontos2 aux0;

  aux0 = (Pontos2) malloc(sizeof(struct sPontos2));
  aux0->flag = PScons_Pontos2;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}

Pontos2  cons_Pontos2_NIL()
{
    Pontos2 aux0;

  aux0 = (Pontos2) malloc(sizeof(struct sPontos2));
  aux0->flag = PScons_Pontos2_NIL;
  return(aux0);
}


Ponto  cons_Ponto( IdPonto a1, CoordX a2, CoordY a3)
{
    Ponto aux0;

  aux0 = (Ponto) malloc(sizeof(struct sPonto));
  aux0->flag = PScons_Ponto;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  aux0->u.d1.s3 = a3;
  return(aux0);
}


IdPonto  cons_IdPonto( char * a1)
{
    IdPonto aux0;

  aux0 = (IdPonto) malloc(sizeof(struct sIdPonto));
  aux0->flag = PScons_IdPonto;
  aux0->u.d1.s1 = a1;
  return(aux0);
}


CoordX  cons_CoordX( int a1)
{
    CoordX aux0;

  aux0 = (CoordX) malloc(sizeof(struct sCoordX));
  aux0->flag = PScons_CoordX;
  aux0->u.d1.s1 = a1;
  return(aux0);
}


CoordY  cons_CoordY( int a1)
{
    CoordY aux0;

  aux0 = (CoordY) malloc(sizeof(struct sCoordY));
  aux0->flag = PScons_CoordY;
  aux0->u.d1.s1 = a1;
  return(aux0);
}


ListaPercursos  cons_ListaPercursos( Percursos a1)
{
    ListaPercursos aux0;

  aux0 = (ListaPercursos) malloc(sizeof(struct sListaPercursos));
  aux0->flag = PScons_ListaPercursos;
  aux0->u.d1.s1 = a1;
  return(aux0);
}


Percursos  cons_Percursos( Percurso a1, Percursos2 a2)
{
    Percursos aux0;

  aux0 = (Percursos) malloc(sizeof(struct sPercursos));
  aux0->flag = PScons_Percursos;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}


Percursos2  cons_Percursos2( Percurso a1, Percursos2 a2)
{
    Percursos2 aux0;

  aux0 = (Percursos2) malloc(sizeof(struct sPercursos2));
  aux0->flag = PScons_Percursos2;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}

Percursos2  cons_Percursos2_NIL()
{
    Percursos2 aux0;

  aux0 = (Percursos2) malloc(sizeof(struct sPercursos2));
  aux0->flag = PScons_Percursos2_NIL;
  return(aux0);
}


Percurso  cons_Percurso( IdPercurso a1, char * a2, ListaRefs a3)
{
    Percurso aux0;

  aux0 = (Percurso) malloc(sizeof(struct sPercurso));
  aux0->flag = PScons_Percurso;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  aux0->u.d1.s3 = a3;
  return(aux0);
}


IdPercurso  cons_IdPercurso( char * a1)
{
    IdPercurso aux0;

  aux0 = (IdPercurso) malloc(sizeof(struct sIdPercurso));
  aux0->flag = PScons_IdPercurso;
  aux0->u.d1.s1 = a1;
  return(aux0);
}


ListaRefs  cons_ListaRefs( IdPonto a1, ListaRefs2 a2)
{
    ListaRefs aux0;

  aux0 = (ListaRefs) malloc(sizeof(struct sListaRefs));
  aux0->flag = PScons_ListaRefs;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}


ListaRefs2  cons_ListaRefs2( IdPonto a1, ListaRefs2 a2)
{
    ListaRefs2 aux0;

  aux0 = (ListaRefs2) malloc(sizeof(struct sListaRefs2));
  aux0->flag = PScons_ListaRefs2;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}

ListaRefs2  cons_ListaRefs2_NIL()
{
    ListaRefs2 aux0;

  aux0 = (ListaRefs2) malloc(sizeof(struct sListaRefs2));
  aux0->flag = PScons_ListaRefs2_NIL;
  return(aux0);
}


