
PROJECT = test_hsv2rgb

INCLUDE = -I../../include

CC = gcc





.PHONY: all clean

all: $(PROJECT)


$(PROJECT): main.c ../../src/color.c
	$(CC) -o $(PROJECT) $(INCLUDE) $^

clean:
	@rm $(PROJECT)
