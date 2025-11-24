EXERCISE_DIRS := $(wildcard ex*)

CC := gcc
CFLAGS_DEBUG = -Wall -I.. -g -std=c99 -O0 -fno-omit-frame-pointer
CFLAGS_RELEASE = -Wall -I.. -std=c99 -O2

CFLAGS = $(CFLAGS_DEBUG)

.PHONY: all clean debug release $(EXERCISE_DIRS)

all: $(EXERCISE_DIRS)

debug: CFLAGS = $(CFLAGS_DEBUG)
debug: all

release: CFLAGS = $(CFLAGS_RELEASE)
release: all


$(EXERCISE_DIRS):
	$(MAKE) -C $@ CC="$(CC)" CFLAGS="$(CFLAGS)" LDFLAGS="$(LDFLAGS)"
	
clean:
	for dir in $(EXERCISE_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done
