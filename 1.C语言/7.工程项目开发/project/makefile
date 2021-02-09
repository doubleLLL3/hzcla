.PHONY: clean
all: main.o haizei/test.o 
	gcc main.o haizei/test.o -o ./bin/haizeix
main.o: main.c haizei/test.h
	gcc -I./ -c main.c
haizei/test.o: haizei/test.c haizei/test.h haizei/linklist.h
	gcc -I./ -c haizei/test.c -o haizei/test.o 
clean:
	rm -rf bin/haizeix main.o haizei/test.o
