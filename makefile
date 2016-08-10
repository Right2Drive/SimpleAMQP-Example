CC=g++
CFLAGS=-Wall -Werror -I/usr/local/include
LDFLAGS=-lSimpleAmqpClient -lrabbitmq

all: sender receiver

sender: sender.cpp
	$(CC) sender.cpp -o sender.out $(CFLAGS) $(LDFLAGS)

receiver: receiver.cpp
	$(CC) receiver.cpp -o receiver.out $(CFLAGS) $(LDFLAGS)

clean:
	rm *o *out 2>/dev/null || true
