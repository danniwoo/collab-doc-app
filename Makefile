# TODO: make sure the rules for server client and markdown filled!
CC := gcc
CFLAGS := -Wall -Wextra

SUB := common.c
# source folder
SOURCE := source


all: server client

server: server.o 
	$(CC) $(CFLAGS) -o $@ $^

client: client.o
	$(CC) $(CFLAGS) -o $@ $^

# compile source/%.c to .o
%.o: $(SOURCE)/%.c
	$(CC) -c $<

clean:
