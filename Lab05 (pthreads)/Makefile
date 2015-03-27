# Defined constants for command base name and arguments for simple test
#
STUDENT_ID=2620216
PTC=ptcount
LOOP=1000000
INC=1

all:
	gcc -g  -o $(PTC) $(PTC).c -lpthread 

nolock:
	gcc -g  -o $(PTC) ptcount_nolock.c -lpthread

test:
	./$(PTC) $(LOOP) $(INC)

test1:
	./$(PTC) 2000 2

clean:
	rm -f $(PTC) 

tar:
	make clean
	mkdir $(STUDENT_ID)-pthreads_intro-lab
	cp ptcount.c ptcount_nolock.c Makefile $(STUDENT_ID)-pthreads_intro-lab/
	tar cvzf $(STUDENT_ID)-pthreads_intro-lab.tar.gz $(STUDENT_ID)-pthreads_intro-lab
	rm -rf $(STUDENT_ID)-pthreads_intro-lab

