#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "board.h"

void resetBoard(int8_t board[8][8]){
	int8_t backRank[] = "rnbqkbnr";
	
	for (uint8_t i = 0; i < 8; i++){
	
		switch (i) {
			case 2:
			case 3:
			case 4:
			case 5:
				memset(board[i], ' ', 8);
				break;

			case 0:
			case 7:
				for (uint8_t x = 0; x < 8; x++){
					//uppercase if white
					board[i][x] = backRank[x] - ((i/7) * 32);
				}
				break;

			case 1:
				memset(board[i], 'p', 8);
				break;
			case 6:
				memset(board[i], 'P', 8);
				break;
		}

	}

}

void movePiece(int8_t board[8][8], int8_t coords[4]){
	int8_t tempStorage = ' ';

	tempStorage = board[coords[2]][coords[3]];
	board[coords[2]][coords[3]] = board[coords[0]][coords[1]];
	board[coords[0]][coords[1]] = tempStorage;
}

void printBoard(int8_t board[8][8]){
	
	for(int8_t i = 0; i < 8; i++){
	
		printf(" ---------------------------------\n");
		for (int8_t x = 0; x < 8; x++){
			printf(" | ");
			putchar(board[i][x]);
		}	
		printf(" |\n");

	}

	printf(" ---------------------------------\n");

}
