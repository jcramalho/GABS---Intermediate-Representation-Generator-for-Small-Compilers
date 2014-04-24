  Mail : ElemList 
  ;

  ElemList : Elem ElemList2 
  | 
  ;

  ElemList2 : Elem ElemList2 
  | 
  ;

  Elem : ToList 
  | CcList 
  | Subject 
  | Message 
  ;

  ToList : char * ToList2 
  ;

  ToList2 : char * ToList2 
  | 
  ;

  CcList : ToList 
  | 
  ;

  Subject : char * Subject 
  | 
  ;

  Message : char * Message 
  | 
  ;

/* -----------------------------------
 * Production Selectors
 * -----------------------------------
 */

#define PScons_Mail  2000

#define PScons_ElemList  2001
#define PScons_ElemList_NIL  2002

#define PScons_ElemList2  2003
#define PScons_ElemList2_NIL  2004

#define PScons_Elem_ToList  2005
#define PScons_Elem_CcList  2006
#define PScons_Elem_Subject  2007
#define PScons_Elem_Message  2008

#define PScons_ToList  2009

#define PScons_ToList2  2010
#define PScons_ToList2_NIL  2011

#define PScons_CcList  2012
#define PScons_CcList_NIL  2013

#define PScons_Subject  2014
#define PScons_Subject_NIL  2015

#define PScons_Message  2016
#define PScons_Message_NIL  2017

/* -----------------------------------
 * Abstract Data Types Definition
 * -----------------------------------
 */

/* --- Mail ---*/
typedef struct sMail 
{ int flag;
  union {  
    struct {
        ElemList s1;
      } d1;

  } u;
} *Mail;

/* --- ElemList ---*/
typedef struct sElemList 
{ int flag;
  union {  
    struct {
        Elem s1;
        ElemList2 s2;
      } d1;
    struct {
      } d2;

  } u;
} *ElemList;

/* --- ElemList2 ---*/
typedef struct sElemList2 
{ int flag;
  union {  
    struct {
        Elem s1;
        ElemList2 s2;
      } d1;
    struct {
      } d2;

  } u;
} *ElemList2;

/* --- Elem ---*/
typedef struct sElem 
{ int flag;
  union {  
    struct {
        ToList s1;
      } d1;
    struct {
        CcList s1;
      } d2;
    struct {
        Subject s1;
      } d3;
    struct {
        Message s1;
      } d4;

  } u;
} *Elem;

/* --- ToList ---*/
typedef struct sToList 
{ int flag;
  union {  
    struct {
        char * s1;
        ToList2 s2;
      } d1;

  } u;
} *ToList;

/* --- ToList2 ---*/
typedef struct sToList2 
{ int flag;
  union {  
    struct {
        char * s1;
        ToList2 s2;
      } d1;
    struct {
      } d2;

  } u;
} *ToList2;

/* --- CcList ---*/
typedef struct sCcList 
{ int flag;
  union {  
    struct {
        ToList s1;
      } d1;
    struct {
      } d2;

  } u;
} *CcList;

/* --- Subject ---*/
typedef struct sSubject 
{ int flag;
  union {  
    struct {
        char * s1;
        Subject s2;
      } d1;
    struct {
      } d2;

  } u;
} *Subject;

/* --- Message ---*/
typedef struct sMessage 
{ int flag;
  union {  
    struct {
        char * s1;
        Message s2;
      } d1;
    struct {
      } d2;

  } u;
} *Message;

/* -----------------------------------
 * Constructor Function Signatures
 * -----------------------------------
 */

Mail  cons_Mail();

ElemList  cons_ElemList();
ElemList  cons_ElemList_NIL();

ElemList2  cons_ElemList2();
ElemList2  cons_ElemList2_NIL();

Elem  cons_Elem_ToList();
Elem  cons_Elem_CcList();
Elem  cons_Elem_Subject();
Elem  cons_Elem_Message();

ToList  cons_ToList();

ToList2  cons_ToList2();
ToList2  cons_ToList2_NIL();

CcList  cons_CcList();
CcList  cons_CcList_NIL();

Subject  cons_Subject();
Subject  cons_Subject_NIL();

Message  cons_Message();
Message  cons_Message_NIL();

