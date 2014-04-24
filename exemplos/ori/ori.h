/* -----------------------------------
 * Production Selectors
 * -----------------------------------
 */

#define PScons_OProva  2000

#define PScons_ListaPontos  2001

#define PScons_Pontos  2002

#define PScons_Pontos2  2003
#define PScons_Pontos2_NIL  2004

#define PScons_Ponto  2005

#define PScons_IdPonto  2006

#define PScons_CoordX  2007

#define PScons_CoordY  2008

#define PScons_ListaPercursos  2009

#define PScons_Percursos  2010

#define PScons_Percursos2  2011
#define PScons_Percursos2_NIL  2012

#define PScons_Percurso  2013

#define PScons_IdPercurso  2014

#define PScons_ListaRefs  2015

#define PScons_ListaRefs2  2016
#define PScons_ListaRefs2_NIL  2017

/* -----------------------------------
 * Abstract Data Types Definition
 * -----------------------------------
 */

/* To avoid dependencies, waiting for a cleaner solution...*/

/* --- dummy OProva ---*/
struct sOProva;
typedef struct sOProva *OProva;

/* --- dummy ListaPontos ---*/
struct sListaPontos;
typedef struct sListaPontos *ListaPontos;

/* --- dummy Pontos ---*/
struct sPontos;
typedef struct sPontos *Pontos;

/* --- dummy Pontos2 ---*/
struct sPontos2;
typedef struct sPontos2 *Pontos2;

/* --- dummy Ponto ---*/
struct sPonto;
typedef struct sPonto *Ponto;

/* --- dummy IdPonto ---*/
struct sIdPonto;
typedef struct sIdPonto *IdPonto;

/* --- dummy CoordX ---*/
struct sCoordX;
typedef struct sCoordX *CoordX;

/* --- dummy CoordY ---*/
struct sCoordY;
typedef struct sCoordY *CoordY;

/* --- dummy ListaPercursos ---*/
struct sListaPercursos;
typedef struct sListaPercursos *ListaPercursos;

/* --- dummy Percursos ---*/
struct sPercursos;
typedef struct sPercursos *Percursos;

/* --- dummy Percursos2 ---*/
struct sPercursos2;
typedef struct sPercursos2 *Percursos2;

/* --- dummy Percurso ---*/
struct sPercurso;
typedef struct sPercurso *Percurso;

/* --- dummy IdPercurso ---*/
struct sIdPercurso;
typedef struct sIdPercurso *IdPercurso;

/* --- dummy ListaRefs ---*/
struct sListaRefs;
typedef struct sListaRefs *ListaRefs;

/* --- dummy ListaRefs2 ---*/
struct sListaRefs2;
typedef struct sListaRefs2 *ListaRefs2;

/* Now the types definition...*/

/* --- OProva ---*/
struct sOProva 
{ int flag;
  union {  
    struct {
        ListaPontos s1;
        ListaPercursos s2;
      } d1;

  } u;
};

/* --- ListaPontos ---*/
struct sListaPontos 
{ int flag;
  union {  
    struct {
        Pontos s1;
      } d1;

  } u;
};

/* --- Pontos ---*/
struct sPontos 
{ int flag;
  union {  
    struct {
        Ponto s1;
        Pontos2 s2;
      } d1;

  } u;
};

/* --- Pontos2 ---*/
struct sPontos2 
{ int flag;
  union {  
    struct {
        Ponto s1;
        Pontos2 s2;
      } d1;
    struct {
      } d2;

  } u;
};

/* --- Ponto ---*/
struct sPonto 
{ int flag;
  union {  
    struct {
        IdPonto s1;
        CoordX s2;
        CoordY s3;
      } d1;

  } u;
};

/* --- IdPonto ---*/
struct sIdPonto 
{ int flag;
  union {  
    struct {
        char * s1;
      } d1;

  } u;
};

/* --- CoordX ---*/
struct sCoordX 
{ int flag;
  union {  
    struct {
        int s1;
      } d1;

  } u;
};

/* --- CoordY ---*/
struct sCoordY 
{ int flag;
  union {  
    struct {
        int s1;
      } d1;

  } u;
};

/* --- ListaPercursos ---*/
struct sListaPercursos 
{ int flag;
  union {  
    struct {
        Percursos s1;
      } d1;

  } u;
};

/* --- Percursos ---*/
struct sPercursos 
{ int flag;
  union {  
    struct {
        Percurso s1;
        Percursos2 s2;
      } d1;

  } u;
};

/* --- Percursos2 ---*/
struct sPercursos2 
{ int flag;
  union {  
    struct {
        Percurso s1;
        Percursos2 s2;
      } d1;
    struct {
      } d2;

  } u;
};

/* --- Percurso ---*/
struct sPercurso 
{ int flag;
  union {  
    struct {
        IdPercurso s1;
        char * s2;
        ListaRefs s3;
      } d1;

  } u;
};

/* --- IdPercurso ---*/
struct sIdPercurso 
{ int flag;
  union {  
    struct {
        char * s1;
      } d1;

  } u;
};

/* --- ListaRefs ---*/
struct sListaRefs 
{ int flag;
  union {  
    struct {
        IdPonto s1;
        ListaRefs2 s2;
      } d1;

  } u;
};

/* --- ListaRefs2 ---*/
struct sListaRefs2 
{ int flag;
  union {  
    struct {
        IdPonto s1;
        ListaRefs2 s2;
      } d1;
    struct {
      } d2;

  } u;
};

/* -----------------------------------
 * Constructor Function Signatures
 * -----------------------------------
 */

OProva  cons_OProva( ListaPontos a1, ListaPercursos a2);

ListaPontos  cons_ListaPontos( Pontos a1);

Pontos  cons_Pontos( Ponto a1, Pontos2 a2);

Pontos2  cons_Pontos2( Ponto a1, Pontos2 a2);
Pontos2  cons_Pontos2_NIL();

Ponto  cons_Ponto( IdPonto a1, CoordX a2, CoordY a3);

IdPonto  cons_IdPonto( char * a1);

CoordX  cons_CoordX( int a1);

CoordY  cons_CoordY( int a1);

ListaPercursos  cons_ListaPercursos( Percursos a1);

Percursos  cons_Percursos( Percurso a1, Percursos2 a2);

Percursos2  cons_Percursos2( Percurso a1, Percursos2 a2);
Percursos2  cons_Percursos2_NIL();

Percurso  cons_Percurso( IdPercurso a1, char * a2, ListaRefs a3);

IdPercurso  cons_IdPercurso( char * a1);

ListaRefs  cons_ListaRefs( IdPonto a1, ListaRefs2 a2);

ListaRefs2  cons_ListaRefs2( IdPonto a1, ListaRefs2 a2);
ListaRefs2  cons_ListaRefs2_NIL();

