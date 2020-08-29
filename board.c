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
			case 6:
				memset(board[i], 'p' + (((i-1)/6) + 32), 8);
				break;
		}

	}

}
