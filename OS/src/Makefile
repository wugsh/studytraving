CC := gcc
CFLAGS = -Wall -g -std=c99

OBJ-bl := big_or_little_endian

OBJ-ALL += $(OBJ-bl)

ALL : 
	@$(CC) $(CFLAGS) $(OBJ-bl).c -o $(OBJ-bl)

.PHONY: clean

clean:
	@rm -rf $(OBJ-ALL)

