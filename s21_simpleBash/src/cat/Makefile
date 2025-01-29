CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror

TARGET = s21_cat

SRC = cat.c
OBJ = cat.o

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