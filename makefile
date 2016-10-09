astar : main.o input.o
	gcc -o astar main.o input.o common.o -g

main.o: main.c
	gcc -c main.c -g 
input.o: input.c
	gcc -c input.c -g
	gcc -c common.c -g

clean:
	rm *.o
