#include "exp.h"

/* -----------------------------------
 * Constructor Function Implementations
 * -----------------------------------
 */

Exp  cons_Exp( int a1, Exp2 a2)
{
    Exp aux0;

  aux0 = (Exp) malloc(sizeof(struct sExp));
  aux0->flag = PScons_Exp;
  aux0->u.d1.s1 = a1;
  aux0->u.d1.s2 = a2;
  return(aux0);
}


Exp2  cons_Soma( Exp a1)
{
    Exp2 aux0;

  aux0 = (Exp2) malloc(sizeof(struct sExp2));
  aux0->flag = PScons_Soma;
  aux0->u.d1.s1 = a1;
  return(aux0);
}

Exp2  cons_Sub( Exp a1)
{
    Exp2 aux0;

  aux0 = (Exp2) malloc(sizeof(struct sExp2));
  aux0->flag = PScons_Sub;
  aux0->u.d2.s1 = a1;
  return(aux0);
}

Exp2  cons_NIL()
{
    Exp2 aux0;

  aux0 = (Exp2) malloc(sizeof(struct sExp2));
  aux0->flag = PScons_NIL;
  return(aux0);
}


