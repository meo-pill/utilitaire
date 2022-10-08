CFLAGS = -g -Wall -Wextra -Werror -pedantic -std=c99
CC = gcc

objetDir = obj

sources = file.c list.c pile.c

objects = $(sources:.c=.o)

all: $(objects)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(objetDir)/$@
