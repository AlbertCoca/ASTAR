astar: main.o input.o common.o astar.o
	gcc -o astar main.o input.o common.o astar.o -g -lm

main.o: main.c
	gcc -c main.c -g -lm
input.o: input.c
	gcc -c input.c -g -lm
common.o: common.c
	gcc -c common.c -g -lm
astar.o: astar.c
	gcc -c astar.c -g -lm
test.o: test.c
	gcc -c test.c -g -lm

test: test.o input.o common.o astar.o
	gcc -o test test.o input.o common.o astar.o -g -lm

clean:
	rm *.o
