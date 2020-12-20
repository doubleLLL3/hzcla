.PHONY: clean
all: lib/libhaizei.a test.o
	g++ test.o -L./lib -lhaizei
test.o: test.cpp
	g++ -I./include -c test.cpp
clean:
	rm -rf a.out  test.o
