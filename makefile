CC=gcc //compiler to use
AR=ar // static libary maker
FLAGS= -Wall -g // flags for output
OBJECTS_LOOPS = NumClass.h basicClassification.c advancedClassificationLoop.c
OBJECTS_RECURSION = NumClass.h basicClassification.c advancedClassificationRecurtion.c

mains: main.o libclassrec.a
	$(CC) $(FLAGS)-o mains main.c
maindloop: main.c libclassloops.so
	$(CC) $(FLAGS) main.c
maindrec: main.c libclassrec.so
	$(CC) $(FLAGS) -o main.c 

all: libclassloops.a libclassloops.so libclassrec.a libclassrec.so 	
libclassloops.a: $(OBJECTS_LOOPS)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOPS)
libclassloops.so: $(OBJECTS_LOOPS)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOPS)
libclassrec.a: $(OBJECTS_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSION)
libclassrec.so: $(OBJECTS_RECURSION)
	$(CC) -shared -o libclassrec.so $(OBJECTS_RECURSION)
mains.o: main.c NumClass.h
	$(CC) $(FLAGS) -c mains.c

.PHONY: clean

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
