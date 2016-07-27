CC=g++
CFLAGS=-c -Wall -I/usr/local/include
LDFLAGS=-Lusr/local/lib/ -lSimpleAmqpClient -lrabbitmq

all: sender.o receiver.o

sender.o: sender.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) sender.cpp -o sender.o

receiver.o: receiver.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) receiver.cpp -o receiver.o

clean:
	rm *o
