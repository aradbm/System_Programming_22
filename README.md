# System Programming 2022 Winter
#### about
<!-- TABLE OF CONTENTS -->
### Tasks
* [Task 1 - Makefile](#task-1---makefile)
* [Task 2 - Loops & Arrays - Floyd Warshall algorithm](#task-2---Loops-&-Arrays---Floyd-Warshall-algorithm)
* [Task 3 - Strings](#task-3---strings)
* [Task 4 - Graphs using struct](#task-4---graphs-using-struct)
## Task 1 - Makefile
#### about
In task 1 we create a libary of functions to use. We implement those functions with loops and in the other file in rucursion. than we use the makefile to create from the functions 4 different libaries, static and dynamic:
1. libclassloops.a
2. libclassrec.a
3. libclassloops.so
4. libclassrec.so

and finally we create 3 different executable files using this libaries:  mains maindloop maindrec.

#### Included files
 * UndoableStringBuilder
 * Tests.java
 * makefile
 * NumClass.h
 * basicClassification.c
 * advancedClassificationLoop.c
 * advancedClassificationRecursion.c
 * main.c
#### How to use the project
First, clone the repository and than run "make" inside the folder of the following files. 


## Task 2 - Loops & Arrays - Floyd Warshall algorithm 
#### about
In this task we create a program that creates a undirected graph using adjacency matrix from the user input.
For input 'A' the program insert numbers to the matrix cells.
For input 'B' the program get 2 numbers of vertices in the graph and return if a path from i to j exists.
For input 'C' the program get 2 numbers of vertices and returns the shortest path from i to j using Floyd Warshall algorithm. -1 if there isn't a path.
#### Included files
* Makefile
* my_mat.h
* my_mat.c
* main.c
 
#### How to use the project
First, clone the git repository and run "make" command inside the teminal in the repository location.
Than, run the executable file "connections"

## Task 3 - Strings 
#### about
In task 3 we create 2 programs:
1. txtfind - takes a string and a text, then it can print all the lines in the text with the selected string. Alternatively, it can print all the words in the text that are similar up to one letter to the string.
2. isort - have functions "shift_element" and "insertion_sort"
#### Included files
* makefile
* isort.c
* txtfind.c
 
#### How to use the project
First, clone the git repository and run the "make" command inside the terminal in the repository location. Then run the executable file "isort" or "txtfind".

## Task 4 - Graphs using struct 
#### about
In task 4 we create a directed graph with weights. We can use the graph to run some functions on it:
1. For input 'A' the user enters values to create the graph.
2. For input 'B' the user can add a node to the graph. If the node already exists, it will delete the previous node and all the edges coming out from it.
3. For input 'D' the user can delete a node in the graph.
4. For input 'S' the user can check the distance between two nodes in the graph. Using the belman-ford algorithm. 
5. For input 'T' the user can run on 'k' selected nodes the TCP problem to see the fasted way to go through all the nodes in the shortest path.
#### Included files
* makefile
* graph.c
* graph.h
* main.c
 
#### How to use the project
First, clone the git repository and run the "make" command inside the terminal in the repository location. Then run the executable file "graph".
