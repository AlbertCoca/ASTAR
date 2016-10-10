astar : main.o input.o
	gcc -o astar main.o input.o common.o astar.o -g -lm

main.o: main.c
	gcc -c main.c -g -lm
input.o: input.c
	gcc -c input.c -g -lm
	gcc -c common.c -g -lm
	gcc -c astar.c -g -lm

clean:
	rm *.o
