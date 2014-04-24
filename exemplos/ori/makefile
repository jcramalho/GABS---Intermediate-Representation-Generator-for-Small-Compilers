gori : parser.o lex.yy.o ori.o
	cc -o gori parser.o lex.yy.o ori.o -lfl

lex.yy.o : lex.yy.c 
	cc -c lex.yy.c

ori.o : ori.h ori.c
	cc -c ori.c

lex.yy.c : analex.l tokens.h
	flex -l analex.l

parser.o : parser.c ori.h
	cc -c parser.c
	
