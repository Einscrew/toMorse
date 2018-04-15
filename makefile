morse: morse_alfab.c
	gcc -o $@ $^ -g -Wall

clean:
	rm -f morse