CC = gcc 
FC = /usr/bin/f95 
CFLAGS = -I/usr/include/python2.7 
LFLAGS = -L/usr/local/lib -lpython2.7 -lm 

.PHONY: all clean

all: main

main: rootF.o rootC.o
	$(FC) $^ -o $@ $(LFLAGS)

rootF.o: fcallpy.f95
	$(FC) -c $< -o $@

rootC.o: root.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o
