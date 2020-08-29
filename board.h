#include <stdint.h>
#include <stdio.h>

struct Board {
	char player1Name[50];
	char player2Name[50];

	int8_t board[8][8];
};

extern struct Board board;

void resetBoard(int8_t board[8][8]);
