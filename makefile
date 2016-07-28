CC=g++
CFLAGS=-c -Wall -Werror -I/usr/local/include
LDFLAGS=-Lusr/local/lib/ -lSimpleAmqpClient -lrabbitmq

all: sender receiver

sender: sender.o
	$(CC) sender.o -o sender.out

receiver: receiver.o
	$(CC) receiver.o -o receiver.out

sender.o: sender.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) sender.cpp

receiver.o: receiver.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) receiver.cpp

clean:
	rm *o *out
