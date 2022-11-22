CC=gcc
AR=ar
FLAGS= -Wall -g
ALL_FILES = mains maindloop maindrec loops recursives loopd recursived

all: $(ALL_FILES)
mains: main.o libclassrec.a
	$(CC) $(FLAGS) main.o ./libclassrec.a -o mains
maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) main.o ./libclassloops.so -o maindloop
maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) main.o ./libclassrec.so -o maindrec

loops: libclassloops.a
recursives: libclassrec.a
loopd: libclassloops.so
recursived: libclassrec.so

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o
libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o
libclassloops.so: basicClassification.c advancedClassificationLoop.c
	$(CC) $(FLAGS) -fPIC -shared -o ./libclassloops.so basicClassification.c advancedClassificationLoop.c
libclassrec.so: basicClassification.c advancedClassificationRecursion.c
	$(CC) $(FLAGS) -fPIC -shared -o ./libclassrec.so basicClassification.c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c
basicClassification.o: basicClassification.c
	$(CC) $(FLAGS) -fPIC -c basicClassification.c
advancedClassificationRecursion.o: advancedClassificationRecursion.c
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
advancedClassificationLoop.o: advancedClassificationLoop.c
	$(CC) $(FLAGS)  -c advancedClassificationLoop.c

.PHONY: clean

clean:
	rm -f *.o *.a *.so $(ALL_FILES)