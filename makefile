CC=gcc
AR=ar
FLAGS= -Wall
ALL_FILES = mains maindloop maindrec

all: $(ALL_FILES)
mains: main.o recursives
	$(CC) $(FLAGS) -o mains main.o ./libclassrec.a
maindloop: main.o loopd
	$(CC) -fPIC $(FLAGS) main.o ./libclassloops.so -o maindloop
maindrec: main.o recursived
	$(CC) -fPIC $(FLAGS) main.o ./libclassrec.so -o maindrec

loops: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
recursives: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
loopd: basicClassification.c advancedClassificationLoop.c
	$(CC) $(FLAGS) -shared -o ./libclassloops.so basicClassification.c advancedClassificationLoop.c
recursived: basicClassification.c advancedClassificationRecursion.c
	$(CC) $(FLAGS) -shared -o ./libclassrec.so basicClassification.c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c
	$(CC) $(FLAGS) -c basicClassification.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
.PHONY: clean

clean:
	rm -f *.o *.a *.so $(ALL_FILES)