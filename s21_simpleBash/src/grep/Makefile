CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

TARGET = s21_grep

SRC = grep.c grep.h
OBJ = grep.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean test
clean:
	rm -rf $(TARGET) $(OBJ) 

test: $(TARGET)
	sh test.sh