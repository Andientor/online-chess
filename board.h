#pragma once

struct Board {
	char player1Name[50];
	char player2Name[50];

	int8_t board[8][8];
};

void resetBoard(int8_t board[8][8]);

//coordinates: {x1, y1, x2, y2}
void movePiece(int8_t board[8][8], int8_t coords[4]);

void printBoard(int8_t board[8][8]);
