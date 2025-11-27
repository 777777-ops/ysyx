CFLAGS=-g -O0 -Wall -Wextra -I../../src -rdynamic -DNDEBUG $(OPTFLAGS)

SOURCES=$(wildcard ../../src/*.c)
SOURCES+=main.c memory.c
SOURCES:=$(filter-out ../../src/memory.c, $(SOURCES))


NAME = main
SRCS = $(SOURCES)
include $(AM_HOME)/Makefile


