STUDENT_ID=2620216

build:
	cd bash-4.2; ./configure; cd ..
	make -C ./bash-4.2 -j8 CFLAGS=-g

test:
	./bash-4.2/bash finder.sh ./bash-4.2 execute 20

tar:
	-make distclean -C bash-4.2
	mkdir $(STUDENT_ID)-gdb-lab
	cp -r bash-4.2 Makefile finder.sh $(STUDENT_ID)-gdb-lab
	tar cvzf $(STUDENT_ID)-gdb-lab.tar.gz $(STUDENT_ID)-gdb-lab
	rm -rf $(STUDENT_ID)-gdb-lab

