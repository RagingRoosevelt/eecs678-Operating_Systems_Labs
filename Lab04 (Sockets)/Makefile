STUDENT_ID=2620216

all:
	gcc -g client.c -o client -lm
	gcc -g server.c -o server -lm

clean:
	rm -f client server mysock

tar:
	make clean
	mkdir $(STUDENT_ID)-sockets-lab
	cp client.c server.c Makefile $(STUDENT_ID)-sockets-lab/
	tar cvzf $(STUDENT_ID)-sockets-lab.tar.gz $(STUDENT_ID)-sockets-lab
	rm -rf $(STUDENT_ID)-sockets-lab

