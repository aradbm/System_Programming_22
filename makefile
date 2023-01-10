CC=gcc
FLAGS= -Wall -g

all: graph
graph: main.o graph.o
	$(CC) $(FLAGS) main.o graph.o -o graph
graph.o: graph.c
	$(CC) $(FLAGS) -c graph.c
main.o: main.c
	$(CC) $(FLAGS) -c main.c



# all: graph
# graph: main.o graph.h
# 	$(CC) $(FLAGS) main.o -o graph
# #edges.o nodes.o algo.o
# main.o: main.c
# 	$(CC) $(FLAGS) -c main.c
# edges.o: edges.c
# 	$(CC) $(FLAGS) -c edges.c
# nodes.o: nodes.c
# 	$(CC) $(FLAGS) -c nodes.c
# algo.o: algo.c
# 	$(CC) $(FLAGS) -c algo.c
.PHONY: clean
clean:
	rm -f *.o *.a *.so graph