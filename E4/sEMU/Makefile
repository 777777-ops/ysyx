CFLAGS=-g -O0 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=src/control.c src/cpu.c src/immSel.c src/memory.c src/regfile.c src/rom.c
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=tests/main.c
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/lib.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
tests: $(TESTS)

#这里要修改tests  会存在顺序问题
$(TESTS): %: %.c $(TARGET)
	$(CC) $(CFLAGS) $< $(TARGET) -o $@

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

