#ifndef _Exp
#define _Exp
/* -----------------------------------
 * Production Selectors
 * -----------------------------------
 */

#define PScons_Exp  2000

#define PScons_Soma  2001
#define PScons_Sub  2002
#define PScons_NIL  2003

/* -----------------------------------
 * Abstract Data Types Definition
 * -----------------------------------
 */

/* To avoid dependencies, waiting for a cleaner solution...*/

/* --- dummy Exp ---*/
struct sExp;
typedef struct sExp *Exp;

/* --- dummy Exp2 ---*/
struct sExp2;
typedef struct sExp2 *Exp2;

/* Now the types definition...*/

/* --- Exp ---*/
struct sExp
{ int flag;
  union {
	struct {
		int s1;
		Exp2 s2;
	  } d1;

  } u;
};

/* --- Exp2 ---*/
struct sExp2
{ int flag;
  union {
	struct {
		Exp s1;
	  } d1;
	struct {
		Exp s1;
	  } d2;
	struct {
	  } d3;

  } u;
};

/* -----------------------------------
 * Constructor Function Signatures
 * -----------------------------------
 */

Exp  cons_Exp( int a1, Exp2 a2);

Exp2  cons_Soma( Exp a1);
Exp2  cons_Sub( Exp a1);
Exp2  cons_NIL();

/* ----------------------------------- */

#endif
