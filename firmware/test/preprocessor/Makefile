
PROJECT = test_main

INCLUDE =

CC = gcc





.PHONY: all clean

all: $(PROJECT)


$(PROJECT): main.c
	$(CC) -o $(PROJECT) $(INCLUDE) $^

clean:
	@rm $(PROJECT)
