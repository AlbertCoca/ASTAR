astar : main.o input.o
	gcc -o astar main.o input.o

main.o: main.c input.h
	gcc -c main.c
stack.o: input.c input.h
	gcc -c input.c

clean:
	rm *.o