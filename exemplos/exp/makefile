gexp : parser.o lex.yy.o exp.o anasem.o
	cc -o gexp parser.o lex.yy.o exp.o anasem.o -lfl

lex.yy.o : lex.yy.c
	cc -c lex.yy.c

exp.o : exp.h exp.c
	cc -c exp.c

lex.yy.c : analex.l tokens.h
	flex -l analex.l

parser.o : parser.c exp.h anasem.h
	cc -c parser.c

anasem.o : anasem.h exp.h anasem.c
	cc -c anasem.c
