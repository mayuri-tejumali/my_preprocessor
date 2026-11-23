mypreprocessor: main.o macro_rep.o header_inc.o comment_rem.o
	cc -o mypreprocessor main.o macro_rep.o header_inc.o comment_removal.o

main.o: main.c
	cc -c main.c

macro_rep.o: macro_rep.c
	cc -c macro_rep.c

header_inc.o: header_inc.c
	cc -c header_inc.c

comment_rem.o: comment_removal.c
	cc -c comment_removal.c

clean:
	@echo "cleaning up...."
	@rm -f *.o mypreprocessor
