OUTPUT=ps3
CC=gcc
CFLAGS=-std=c11 -Werror -Wall
LDLIBS=-lm

all: $(OUTPUT)

$(OUTPUT):cheesefactory.o mm.o isolation.o racer.o
	echo "Running compilation"
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $(OUTPUT)

cheesefactory.o: cheesefactory.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

mm.o: mm.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

racer.o: racer.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

isolation.o: isolation.c
	$(CC) $(CFLAGS) -c $^ $(LDLIBS) -o $@

clean:
	echo "Deleting object files"
	rm $(OUTPUT) *.o