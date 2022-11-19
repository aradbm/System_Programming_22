CC=gcc
AR=ar
FLAGS= -Wall
OBJECTS_LOOPS = basicClassification.c advancedClassificationLoop.c
OBJECTS_RECURSION = basicClassification.o advancedClassificationRecursion.o
ALL_FILES = loops recursives recursived loopd mains maindloop maindrec

all: $(ALL_FILES)
mains: main.c recursives
	$(CC) $(FLAGS) -o mains main.c ./libclassrec.a
maindloop: main.c loopd
	$(CC) -fPIC $(FLAGS) -o maindloop main.c ./libclassloops.so
maindrec: main.c recursived
	$(CC) -fPIC $(FLAGS) -o maindrec  main.c ./libclassrec.so

loops: $(OBJECTS_LOOPS)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOPS)
recursives: $(OBJECTS_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSION)
loopd: $(OBJECTS_RECURSION) 
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOPS)	
recursived: $(OBJECTS_RECURSION)
	$(CC) -shared -o libclassrec.so $(OBJECTS_RECURSION)
	
.PHONY: clean

clean:
	rm -f *.o *.a *.so $(ALL_FILES)
