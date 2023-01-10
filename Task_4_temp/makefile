CC=gcc
#FLAGS= -Wall -g

#edges.o nodes.o algo.o
all: graph
graph: main.o graph.h
	$(CC) $(FLAGS) main.o -o graph
#edges.o nodes.o algo.o
main.o: main.c
	$(CC) $(FLAGS) -c main.c
edges.o: edges.c
	$(CC) $(FLAGS) -c edges.c
nodes.o: nodes.c
	$(CC) $(FLAGS) -c nodes.c
algo.o: algo.c
	$(CC) $(FLAGS) -c algo.c

.PHONY: clean
clean:
	rm -f *.o *.a *.so graph