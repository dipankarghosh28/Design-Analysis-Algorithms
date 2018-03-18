all:
	gcc tromino.c -o tromino.out -lm
	gcc strassen.c -o strassen.out
clean:
	find tromino.out -delete
	find strassen.out -delete
