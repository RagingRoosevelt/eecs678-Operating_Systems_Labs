all: simple.o
	gcc -lm simple.o -o simple

simple.o: simple.c simple.h
	gcc -Wall -c simple.c

tar: 
	mkdir eecs678-lab-editors
	cp dot_vimrc Makefile simple.* eecs678-lab-editors/
	tar cvzf eecs678-lab-editors.tar.gz eecs678-lab-editors
	rm -rf eecs678-lab-editors
