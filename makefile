all:
	gcc pic.c
	./a.out
clean:
	rm pic.ppm
	rm a.out
	rm *~
