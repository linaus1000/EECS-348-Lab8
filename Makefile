CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: NFLScore temperature

NFLScore: NFLScore.c
	$(CC) $(CFLAGS) NFLScore.c -o NFLScore

temperature: temperature.c
	$(CC) $(CFLAGS) temperature.c -o temperature

clean:
	rm -f NFLScore temperature