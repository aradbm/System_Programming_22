CC=gcc
AR=ar
FLAGS= -Wall
OBJECTS_LOOPS = basicClassification.c advancedClassificationLoop.c
OBJECTS_RECURSION = basicClassification.c advancedClassificationRecursion.c

all: libclassloops.a libclassloops.so libclassrec.a libclassrec.so mains maind maindrec
mains: main.c libclassrec.a NumClass.h
	$(CC) $(FLAGS) -o mains main.c libclassrec.a NumClass.h
maindloop: main.c libclassloops.so NumClass.h
	$(CC) $(FLAGS) -o maindloop main.c ./libclassloops.so NumClass.h
maindrec: main.c libclassrec.so NumClass.h
	$(CC) $(FLAGS) -o maindrec main.c ./libclassrec.so NumClass.h
	
## 1. NumClass.h place is good?,2. mains doesnt work:
##gcc -Wall -o mains main.c libclassrec.a NumClass.h
##/usr/bin/ld: libclassrec.a: error adding symbols: archive has no index; run ranlib to add one
##collect2: error: ld returned 1 exit status
##make: *** [makefile:9: mains] Error 1


libclassloops.a: $(OBJECTS_LOOPS)
	$(AR) -rcs libclassloops.a $(OBJECTS_LOOPS)
libclassloops.so: $(OBJECTS_LOOPS)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LOOPS)
libclassrec.a: $(OBJECTS_RECURSION)
	$(AR) -rcs libclassrec.a $(OBJECTS_RECURSION)
libclassrec.so: $(OBJECTS_RECURSION)
	$(CC) -shared -o libclassrec.so $(OBJECTS_RECURSION)
	
.PHONY: clean

clean:
	rm -f *.o *.a *.so mains maindloop maindrec
