#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "board.h"

const char *red = "\x1B[91m", *green = "\x1B[92m", *white = "\x1B[0m", *yellow = "\x1B[93m";

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
	
	board[coords[3]][coords[2]] = board[coords[1]][coords[0]];
	board[coords[1]][coords[0]] = ' ';
	
}

//modes - 1 = capture, 2 = moved
void printBoard(int8_t board[8][8], int8_t colorMode, int8_t coords[4]){

	for(int8_t i = 0; i < 8; i++){
	
		printf("   ---------------------------------\n ");
		putchar((7-i) + 65);
		for (int8_t x = 0; x < 8; x++){
			int8_t isColored = 0;

			printf(" | ");
		
			//color character if marked by coords	
			if(i == coords[1] && x == coords[0]){
				isColored = 1;


				switch (colorMode){
					case 1:
						printf("%s", green);
						break;
					
					case 2:
						printf("%s", yellow);
						break;
				}

			} else if (i == coords[3] && x == coords[2]){
				isColored = 1;
				
				switch (colorMode){
					case 1:
						printf("%s", red);
						break;
					
					case 2:
						printf("%s", yellow);
						break;
				}

			}

			if(isColored && board[i][x] == ' '){
				putchar('_');
			} else {
				putchar(board[i][x]);
			}

			printf("%s", white);
		}	
		printf(" |\n");

	}

	printf("   ---------------------------------\n  ");
	
	for(int8_t i = 0; i < 8; i++){
		printf("   %c", i + 49);
	}

	putchar('\n');

}
