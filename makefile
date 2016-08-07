CC=g++
CFLAGS=-c -Wall -Werror -I/usr/local/include
LDFLAGS=-Lusr/local/lib/ -lSimpleAmqpClient -lrabbitmq

all: sender receiver

sender: sender.o
	$(CC) sender.o -o sender.out $(LDFLAGS)

receiver: receiver.o
	$(CC) receiver.o -o receiver.out $(LDFLAGS)

sender.o: sender.cpp
	$(CC) $(CFLAGS) sender.cpp $(LDFLAGS)

receiver.o: receiver.cpp
	$(CC) $(CFLAGS) receiver.cpp $(LDFLAGS)

clean:
	@rm *o *out 2>/dev/null || true
