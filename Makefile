CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: football temp_convert

football: football.c
	$(CC) $(CFLAGS) football.c -o football

temp_convert: temp_convert.c
	$(CC) $(CFLAGS) temp_convert.c -o temp_convert

clean:
	rm -f football temp_convert