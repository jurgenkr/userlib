all: userapp yieldapp

.PHONY: clean all

userapp: userapp.o csse332_lib.o

yieldapp: yieldapp.o csse332_lib.o

csse332_lib.o: csse332_lib.c csse332_lib.h

clean:
	rm -rf *.o userapp yieldapp
