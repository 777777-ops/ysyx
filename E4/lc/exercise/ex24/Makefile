SRCS := $(wildcard *.c)
OBJS := $(SRCS:.c=.o)
TARGET := $(notdir $(CURDIR))

CC ?= gcc
CFLAGS ?= -Wall -g -I.. 
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(TARGET) *.o
